/*
 * Filename: main.cpp 
 * Author:
 * Userid:
 * Description:
 * Date:
 */

#include <math.h>
#include <iostream>
#include <thread>
#include <future>
#include <sys/time.h>
#include "pamt2.h"

/*
 * Function name: main()
 * Function prototype: int main( int argc, char* argv[] );
 * Description: C main driver which calls function on numbers read in from
 *              command line header file (both sequentially and in parallel) to
 *              determine if each is prime and reports results and statistics.
 * Parameters: None. 
 * Side Effects: Outputs number of threads, value of each number in global array
 *               and whether it is prime, and benchmark info.
 * Error Conditions: None.
 * Return Value: 0 indicating successful execution. 
 */

int main(int argc, char* argv[])
{
  if (argc < 2) {
    fprintf(stderr, "Usage: %s num1 [num2 num3 ...]\n", argv[0]);
    return 1;
  }

  struct timeval t0, t1;

  std::cout << "Number of threads = " << numOfThreads << std::endl << std::endl;

  for( int i = 1; i < argc; ++i )
  {

    long long num = strtoll(argv[i], NULL, 0);

    /*
     * Only need to check factors up to the square root of the number.
     */

    long long max = (long long) (sqrt( (double)num ) + 1);

    /*
     * First do sequential isPrime
     */

    std::cout << "Sequential isPrime for " << num << std::endl;  

    gettimeofday( &t0, NULL ); // start

    bool answer = isPrime( num, 3, max );

    gettimeofday( &t1, NULL ); // finish

    double seqTime = t1.tv_sec - t0.tv_sec +
                    (t1.tv_usec - t0.tv_usec) / 1000000.0;
    std::cout << num << (answer == true ? " is " : " is not ")
              << "prime" << std::endl;
    std::cout << "Completed in " << seqTime << " sec" << std::endl << std::endl;

    /*
     * Now do async-get C++11 multi-threading
     */

    std::cout << "Async-get parallel isPrime for " << num << std::endl;  

    /* TODO Calculate size of each parallel partition */
      long long range = max - 3;
      long long partialRange = range / numOfThreads;

    /*
     * results[] holds the future<bool> values from the different async threads
     *           We have to get() [join] each thread
     *
     * answers[] holds the actual bool value returned in each future<bool>
     *           Makes it a little easier to iterate over this to check if any
     *           threads found the number not to be prime.
     */

    std::future<bool> results[numOfThreads - 1];

    bool answers[numOfThreads];

    gettimeofday( &t0, NULL ); // start parallel part

    /*
     * Map each of the partitions to a separate thread with async()
     * (except the last partition).
     */

    int j;
    for ( j = 0; j < numOfThreads - 1; ++j )
    {
      results[j] = std::async( std::launch::async, isPrime,
                               num,  3 + partialRange * j, 3 + partialRange * (j+1));
    }

    /*
     * Run the last partition in this current thread.
     *
     * Be sure to include any extra elements due to integer divide.
     * Hi (exclusive) value needs to be max and not partitionSize * (j+1).
     */

    answers[j] = isPrime(num, 3 + partialRange * j, max);

    /*
     * We have to join/wait on all the threads with get() first.
     */

    for ( j = 0; j < numOfThreads - 1; ++j )
    {
      answers[j] = results[j].get();
    } 

    /*
     * Now see if any thread found num not to be prime.
     * This is a reduction - reducing all the separate thread results into
     * a single answer.
     */

    answer = true;

    for ( j = 0; j < numOfThreads; ++j )
    {
        /*TODO Using the results from each of the threads, check if any returned
               false and set answer to false and jump out of the loop if so.  */
        if (answers[j] == false) {
            answer = false;
        }
    }

    gettimeofday( &t1, NULL ); // finish - have to include reduction work

    double parallelTime = t1.tv_sec - t0.tv_sec + 
                         (t1.tv_usec - t0.tv_usec) / 1000000.0;

    std::cout << num << (answer == true ? " is " : " is not ")
              << "prime" << std::endl;

    std::cout << "Completed in " << parallelTime 
              << " sec" << std::endl << std::endl;

    std::cout << "Speed-up: " << (double) seqTime / parallelTime 
              << std::endl << std::endl;

    std::cout << "--------------" << std::endl << std::endl;
  }

  return 0;
}

