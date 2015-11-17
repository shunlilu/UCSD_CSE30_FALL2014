/*
 * Filename: set.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: SPARC assembly routine to set the lightbank pattern
 * Date: Oct. 30, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

    .global set
    .section ".text"

/*
 * Function name: set();
 * Function prototype: 
 *          void set(unsigned int lightBank[], const unsigned int bank0, 
 *                   const unsigned int bank1);
 * Description: set the light bank pattern
 * Parameters:
 * arg 1: the arrary stored the light bank data
 * arg 2: the pattern specifying which bit of lightbank[0] need to be set
 * arg 3: the pattern specifying which bit of lightbank[1] need to be set
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: None.
 *
 * Registers Used:
 * %i0 - arg 1
 * %i1 - arg 2
 * %i2 - arg 3
 * %l0 - First light bank
 * %l1 - Second light bank
 * %l2 - new lightBank[0]
 * %l3 - new lightBank[1]
 */

set:
    save    %sp, -96, %sp   ! Save call's window

    ld      [%i0], %l0      ! Gets the actual of lightBank[0]
    ld      [%i0+4], %l1    ! Gets the actual of lightBank[1]

    or      %l0, %i1, %l2   ! lightBank[0] OR bank0
    or      %l1, %i2, %l3   ! lightBank[1] OR bank1

    st      %l2, [%i0]      ! Store the new value back
    st      %l3, [%i0+4]

    ret
    restore
    
