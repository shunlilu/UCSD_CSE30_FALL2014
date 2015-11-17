#ifndef PAMT2_H    /* Macro Guard */
#define PAMT2_H


/* 
 * The number of concurrent threads that the current machine can support.
 */

const int numOfThreads = std::thread::hardware_concurrency();

/*
 * Local function prototypes for PAMT2
 */

bool isPrime( long long n, long long lo, long long hi );

#endif

