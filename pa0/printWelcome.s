/*
 * Filename: printWelcome.s
 * Author: Yuchun Li
 * Userid: Not be assigned yet
 * Description: Example SPARC assembly routine to print out a greeting followed
 *		by a string (student's name) passed in as an argument
 * 		to this function
 *		Called from main()
 * Date: Oct. 10, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

	.global printWelcome	! Declares the symbol to be globally visible so
				! we can call this function form other modules.

	.section ".data"	! The data segment begins here
fmt:				! Formatted string used for printf()
	.asciz	"Welcome to CSE 30, %s\n"


	.section ".text"	! The text segment begins here


/*
 * Function name: printWelcome()
 * Function prototype: void printWelcome( const char *str );
 * Description: Prints to stdout a greeting string and the argument
 *		with a terminating newline via printf()
 * Parameters:
 *	arg 1: char *str -- the string to print after the greeting
 *
 * Side Effects: Outputs greeting with string supplied as argument.
 * Error Conditions: None. [Arg 1 is not checked to ensure it is not NULL.]
 * Return Value: None
 *
 * Registers Used:
 *	%i0 - arg 1 -- the string (char *) passed in to this function
 * 	%o0 - param 1 to printf() -- format string
 *	%01 - param 2 to printf() -- copy of arg 1 being passed in
 */


printWelcome:
	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value was calculated.

	set	fmt, %o0	! Format string
	mov	%i0, %o1	! Copy of formal parameter to print
	call	printf		! Make function call
	nop			! Delay slot for call instruction

	ret			! Return rom subroutine
	restore			! Restore caller's window; in "ret" delay slot

