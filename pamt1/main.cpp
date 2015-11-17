/*
 * Filename: main.cpp
 * Author: Yuchun Li
 * Userid: cse30xlq
 * Description: C main driver for pamt1
 * Date: Nov. 7, 2014
 */

#include <thread>
#include <future>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "pamt1.h"

/*
 * Function name: main()
 * Function prototype: int main( int argc, char *argv[] );
 * Description: C main driver which takes in a single command-line argument,
 *              creates an array, calls function on this array (both
 *              sequentially and in parallel) and reports statistics
 * Parameters: size of array to create and process
 * Side Effects: Outputs sum of squares of the array, the min and max values
 *               seen, and benchmark information
 * Error Conditions: None.
 * Return Value: 0 indicating successful execution.
 */

int main( int argc, char *argv[] )
{
  if ( argc != 2 )
  {
    usage(argv[0]);
    exit( -1 );
  }

  struct timeval t0, t1;
  struct result result;

  /* Convert command-line arg to long and initialize array */
  int size = strtol( argv[1], nullptr, 10 );
  char *array = (char *) malloc( size );

  (void) printf( "Initializing array (size = %d) with random values\n\n", size);

  initData( array, size );

  /* First do sequential sum, min, max */

  (void) printf( "Sequential squared sum, min, max (be patient)\n" );  

  gettimeofday( &t0, NULL ); // start time

  result = sequentialSquaredSumMinMax( array, 0, size );

  gettimeofday( &t1, NULL ); // end time

  double seqTime = t1.tv_sec - t0.tv_sec + (t1.tv_usec - t0.tv_usec)/1000000.0;

  (void) printf( "Squared Sum is: %lld\n", result.sum );
  (void) printf( "Min value is: %d\n", result.min );
  (void) printf( "Max value is: %d\n", result.max );
  (void) printf( "Completed in %f sec\n\n", seqTime );

  /*
   * Now do async-get divide-and-conquer by mapping/partitioning portions
   * of the array to the different threads.
   */

  (void) printf( "Async-get parallel squared sum, min, max\n" );  
  (void) printf( "Number of threads = %d\n", numOfThreads );

  /*
   * Create an array of future results - one for each thread except this
   * main thread (so # of elements = numOfThreads - 1).
   */
  std::future<struct result> results[numOfThreads - 1];

  gettimeofday( &t0, NULL ); // start time

  /* Calculate size of each parallel partition */
   long partSize;
   partSize = size / numOfThreads;
  /* End Calculate size of parallel partitions */

  /*
   * Launch a thread to work on its part of the array. Each thread will
   * return its result in a struct with that partition's squared sum, min,
   * and max values.
   */
  int i;
  for ( i = 0; i < numOfThreads - 1; ++i )
  {
    results[i] = std::async( std::launch::async, sequentialSquaredSumMinMax,
                             array, partSize*i, partSize*(i+1));
  }

  /*
   * Run the last partition in this current main thread.
   * Be sure to include any extra elements due to integer divide.
   * Initialize the overall reduced result to this last partition's result.
   */

  result = sequentialSquaredSumMinMax( array, partSize*i, size);

  /*
   * Now cycle through the results array which holds the results from the
   * different threads and reduce to a single overall result already
   * started with the above main thread's result.
   *
   * First need to get() - waits for the async'ed thread (future) result
   * and retrieves it.
   */

  for ( i = 0; i < numOfThreads - 1; ++i )
  {
    /* Wait for the async'ed thread (future) result and then get it. */
    struct result tmpResult = results[i].get();

    /* Get the max value among different partitions */
    if (tmpResult.max > result.max)
       result.max = tmpResult.max;
    /* Get the min value among different partitions */
    if (tmpResult.min < result.min)
       result.min = tmpResult.min;
    /* Get the total sum */
    result.sum += tmpResult.sum;
  } 

  gettimeofday( &t1, NULL ); // end time

  double parallelTime = t1.tv_sec - t0.tv_sec + 
                        (t1.tv_usec - t0.tv_usec)/1000000.0;

  (void) printf( "Squared Sum is: %lld\n", result.sum );
  (void) printf( "Min value is: %d\n", result.min );
  (void) printf( "Max value is: %d\n", result.max );
  (void) printf( "Completed in %f sec\n\n", parallelTime );

  (void) printf( "Speed-up: %f\n\n", seqTime / parallelTime );

  free(array);

  return 0;
}

/*
 * Function name: usage()
 * Function prototype: void usage( char* filename )
 * Description: Prints a brief usage message to stderr
 * Parameters: filename   name of this program, to be printed out in message
 * Side Effects: Prints message to stderr
 * Error Conditions: None.
 */
void usage(char* filename) {
  fprintf(stderr, "\nUsage: %s array_size\n", filename);
  fprintf(stderr, "   array_size  (must be positive integer)\n\n");
}
