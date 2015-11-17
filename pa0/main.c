/*
 * Filename: main.c
 * Author: Yuchun Li
 * Userid: Not be assigned yet
 * Description: Example C program for pa0. It calls a couple of functions
 *		written in assembly and C as examples of function calls and
 *		parameter passing in C and SPARC assembly (also know as 
 *		the language's and architecture's calling conventions).
 * Date: Oct. 10, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

/*
 * Header files included here.
 * Std C Lib header files first, then local headers.
 */

/* Standcard C Library headers use angle brackets <> */
#include <stdlib.h>
#include <stdio.h>

/* Local header use double quotes "" */
#include "pa0.h"
#include "strings.h"

/*
 * Function name: main()
 * Function protorype:  int main( int argc, char *argv[] );
 *				or
 * 			int main( void): if no command line processing.
 * Description: C main driver which calls C and SPARC assembly routines to
 *		print a greeting, assgnment due date, and the square of the
 *		number entered at the command line.
 * Parameters: int containing the number to square
 * Side Effects: Outputs greeting, assgnment due date, and square of a number
 * Error Conditions: None.
 * Return Value: 0 indicating successful execution.
 */

int
main( int argc, char *argv[] ) {
   struct DueDate dueDate;   /* Structure to hold assignment due date */
   int argVal = 0;	     /* Value to square form command line */

   /*
    * We decrement argc because the name of the program is the first
    * argument which we do not want to count.
    */
   --argc;

   if ( argc != EXPECTED_ARGS ) {
     
     /* Error messages are printed to stderr */
     (void ) fprintf(
	      stderr,
        argc < EXPECTED_ARGS ? STR_ERR_MISSING_ARG : STR_ERR_EXTRA_ARG,
        argv[0] );

     (void) fprintf( stderr, STR_ERR_USAGE, argv[0] );

     return EXIT_FAILURE;
   }

   /*
    * strtol() offers error checking/handling. See: man strtol
    */
   argVal = atol( argv[1] );

   /*
    * Assignments due date.
    */
   dueDate.day    = 10;
   dueDate.year   = 2014;
   dueDate.month  = "October";

   /*
    * Print the greeting message
    */
   printWelcome( STR_WELCOME_QUARTER );

   /*
    * Print assignment due date
    * printDueDate() takes the address of the DueDate Struct
    * (a pointer to the DueDate struct)
    */
   printDueDate( &dueDate );

   /*
    * Now suare the input and print the result
    */
   (void) printf( STR_SQUARENUM, argVal, squareNum (argVal ) );

   return EXIT_SUCCESS;
}
