/*
 * Filename: numOfDigits.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: SPARC assembly routine to get the number of
 *              digit of the input
 *              Called from main()
 * Date: Oct. 17, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

        .global numOfDigits
        .section ".text"

/* Constants fine */
        MIN_BASE = 2
        MAX_BASE = 36
/*
 * Function name: numOfDitigs()
 * Function prototype: int numOfDigits( long num, int base);
 * Description: Count the number of digit of the argument num
 * Parameters:
 *	arg 1: long num -- the number need to be counted
 *  arg 2: int base -- the base of the arg 1
 *
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: the number of the digit of the arg 1
 *
 * Registers Used:
 * %i0 - arg 1 -- the number (num) passed in to this function
 * %i1 - arg 2 -- the base of the arg 1
 * %o0 - param 1 to .div
 * %o1 - param 2 to .div
 * %l0 - result of the division calculation
 * %l1 - number of digits counter
 */

numOfDigits:
        save    %sp, -96, %sp   ! Save call's window

        mov     %i1, %o0        ! Pass base to checkRange
        mov     MIN_BASE, %o1   ! Pass the lower bound to checkRange
        mov     MAX_BASE, %o2   ! Pass the upper bound to checkRange

        call    checkRange
        nop

        cmp     %o0, 0          ! Check for errors returned from checkRange
        be      OutRange
        nop

        mov     %i0, %l0        ! Copy of arg 1 to local variable
        mov     %i1, %o1        ! Copy of arg 2 to 2nd parameter of div.
        mov      1,  %l1        ! Counter starts with 1

        cmp     %i0, 0          ! Check for 0
        be      Done            ! Done if arg 1 is 0 - negative logic
        nop
        clr     %l1             ! Counter starts with 0 if arg 1 is not 0
Start:
        inc     %l1             ! Increase the counter for each iteration
        mov     %l0, %o0        ! Copy of arg 1 to .div

        call    .div
        nop

        mov     %o0, %l0        ! Keep the result

        cmp     %l0, 0          ! Check for 0
        bne     Start           ! loop if result is not 0 - positive logic
        nop
Done:
        mov     %l1, %i0        ! Put return value in %i0
        ret
        restore

OutRange:
        mov     -1, %i0         ! Returns -1
        ret
        restore

        
