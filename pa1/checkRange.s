/*
 * Filename: checkRange.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: SPARC assembly routine to check if the argument
 *              is within particular range.
 *              Called from main()
 * Date: Oct. 14, 2014
 * Sources of Help: CSE30 course website.
 */
	.global checkRange

	.section ".text"

/*
 * Function name: checkRange()
 * Function prototype: int checkRange( long value, long minRange, long maxRange );
 * Description: Check if the 1st arg is within [minRange, maxRange]
 * Parameters:
 * arg 1: long value - number to be checked
 * arg 2: long minRange - lower bound of the range
 * arg 3: long maxRange - upper bound of the range
 *
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: 0 - arg 1 is not within the range
 *               1 - arg 1 is within the range
 * Registers Used:
 * %i0 - arg 1 - the number needs to be checked; also used to return the result.
 * %l0 - used to put the AND op result
 */

 checkRange:
        save    %sp, -96, %sp

        cmp     %i0, %i1
        bl      outRange
        nop

        cmp     %i0, %i2
        bg      outRange
        nop

        mov     1, %i0
        ret
        restore

outRange:
        mov     0, %i0
        ret
        restore
        