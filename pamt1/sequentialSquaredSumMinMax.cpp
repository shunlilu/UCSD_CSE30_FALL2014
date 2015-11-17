/*
 * Filename: main.cpp
 * Author: Yuchun Li
 * Userid: cse30xlq
 * Description: Calculates the sum of the quare of each elements in array
 * Date: Nov. 7, 2014
 */

#include "pamt1.h"

/*
 * Function name: sequentialSauaredSumMinMax()
 * Function prototype: 
 * 	struct result sequentialSquaredSumMinMax( char a[], int lo, int hi );
 * Description: Calculates the sum of the quare of each elements in array, 
 * 		from lo to hi( inclusive of lo, but exclusive of hi).
 * Parameters: char a[] - the array to be calculated
 * 		int lo - the starting index of the array
 * 		int hi - the ending index of the array
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: struct result.
 */
struct result sequentialSquaredSumMinMax( char a[], int lo, int hi ){
  int i;
  struct result result;
  
  /* initialize the struct result */
  result.sum = 0;
  result.min = a[lo];
  result.max = a[hi];
  
  for (i = 0; lo + i < hi; i++){
    /* Get the larger value */
    if (a[lo+i] > result.max)
      result.max = a[lo+i];
    /* Get the smaller value */
    if (a[lo+i] < result.min)
      result.min = a[lo+i];
    /* Get the suqared sum */
    result.sum += a[lo+i]*a[lo+i];
  }
  
  return result;
}
