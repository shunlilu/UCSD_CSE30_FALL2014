/*
 * Filename: printDueDate.c
 * Author: Yuchun Li
 * Userid: Not be assigned yet
 * Description: Example C routine to print out the due date info
 *		(month day, year) using a pointer to a structur.
 * 		Called from main()
 * Date: Oct. 10, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

#include <stdio.h>
#include "pa0.h"
#include "strings.h"

/*
 * Function name: printDueDate()
 * Function prototype:
 *	void printDueDate( const struct DueDate *dueDate );
 * Description: Prints to stdout the month, day, and year members of a 
 * 		struct DueDate node.
 * Parameters: 
 *	arg1: struct DueDate *dueDate -- pointer to the
 *	      DueDate struct which should be printed.
 * Side effects: Outputs the due date of the assignment
 * Error Conditions: Checks to make sure arg1 is not NULL
 *		     No checks to ensure struct data are correct type/values.
 * Return Value: none.
 */

void
printDueDate( const struct DueDate *dueDate ) {
   if ( dueDate != NULL ){
      (void) printf( STR_DUEDATE, dueDate -> month, dueDate -> day, dueDate -> year );
   }
}
