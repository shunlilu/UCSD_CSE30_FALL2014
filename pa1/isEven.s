/*
 * Filename: isEven.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: SPARC assembly routine to check if an integer argument
 *              is an even number.
 *              Called from main()
 * Date: Oct. 14, 2014
 * Sources of Help: CSE30 course website.
 */
	.global isEven

	.section ".text"

/*
 * Function name: isEven()
 * Function prototype: int isEven( long value );
 * Description: Check for even integer
 * Parameters:
 * arg 1: long value -- number to be checked
 *
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: 0 - arg 1 is not even 
 *		 1 - arg 1 is even
 * Registers Used:
 * %i0 - arg 1 - the number needs to be checked; also used to return the result.
 * %l0 - used to put the AND op result
 */

isEven:
	save    %sp, -96, %sp	! Save caller's window
	and     %i0, 1, %l1	! %i0 - arg 1; AND op with 1 to get LSB
    	cmp     %l1, 1		! Compare with 1.
    	
	bne     Even		! Branch if not equal to 1, and
				! that means arg 1 is even.
    	nop

    	mov     0, %i0		! return 0 - not even
    	ret
	restore
Even:
    	mov     1, %i0		! return 1 - even
    	ret
	restore
    

