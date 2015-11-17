/*
 * Filename: printChar.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: SPARC assembly routine to print out a single character
 *		Called from main()
 * Date: Oct. 17, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

    .global printChar

    .section ".data"
fmt:
    .asciz  "%c"
    .section ".text"

/*
 * Function name: printChar()
 * Function prototype: void printChar( char ch );
 * Description: Prints out a single character
 * Parameters:
 *	arg 1: char ch -- the character to print
 *
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: None.
 *
 * Registers Used:
 *	%i0 - arg 1 -- the character (ch) passed in to this function
 * 	%o0 - param 1 to printf()
 */

printChar:
    save    %sp, -96, %sp   ! Save call's windows

    set     fmt, %o0
    mov     %i0, %o1        ! Copy of parameter to print
    call    printf          ! Make function call
    nop

    ret
    restore
