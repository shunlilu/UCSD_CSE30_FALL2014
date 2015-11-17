/*
 * Filename: ripple.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: SPARC assembly routine to display the lightbank pattern
                every single bit roatation
 * Date: Nov. 1, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

    .global ripple
    .section ".text"

/*
 * Function name: ripple();
 * Function prototype: 
 *          void ripple(unsigned int lightBank[], const int rippleCnt);
 * Description: left or right logice shift the lightBank
 * Parameters:
 * arg 1: the arrary stored the light bank data
 * arg 2: rotation count - positive number to rotate left
                         - negative number to rotate right
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: None.
 *
 * Registers Used:
 * %i0 - arg 1
 * %i1 - arg 2
 * %l0 - First light bank
 * %l1 - Second light bank
 * %l2 - MSB or LSB saver for lightBank[0]
 * %l3 - rotation count
 * %l4 - sign bit of rotation count
 * %l5 - MSB_MASK
 * %l6 - MSB or LSB saver for lightBank[1]
 */

 /* Constant */
 MSB_MASK    = 0x80000000       ! To save the MSB
 LSB_MASK    = 0x00000001       ! TO save the LSB
 SIXBIT_MASK = 0x3F             ! To get the lower 6 bits

ripple:
    save    %sp, -96, %sp   ! Save call's window

    ld      [%i0], %l0      ! Gets the actual of lightBank[0]
    ld      [%i0+4], %l1    ! Gets the actual of lightBank[1]

    set     MSB_MASK, %l5
    cmp     %i1, %g0        ! Check for left shift or right shift
    bl      rightRipple
    nop

    /* leftRipple */
    and     SIXBIT_MASK, %i1, %l3    ! Get the lower 6 bits of shiftCnt

    clr     %l4
    cmp     %l4, %l3
    bge     end_loop
    nop

st_loop:
    and     %l0, %l5, %l2   ! Save the MSB of lightBank[0]
    srl     %l2, 31, %l2    ! MSB of lightBank[0] now in LSB
    and     %l1, %l5, %l6   ! Save the MSB of lightBank[1]
    srl     %l6, 31, %l6    ! MSB of lightBank[0] now in LSB
    sll     %l0, 1, %l0     ! Left logic shift for lightBank[0]
    or      %l6, %l0, %l0   ! lightBank[0] has correct LSB
    sll     %l1, 1, %l1     ! Left logic shift for lightBank[1]
    or      %l2, %l1, %l1   ! lightBank[1] has correct LSB

    st      %l0, [%i0]      ! Store the new value back
    st      %l1, [%i0+4]

    mov     %i0, %o0       ! display the bank patterns
    call    displayLights
    nop

    inc     %l4
    cmp     %l4, %l3
    bl      st_loop
    nop
    
end_loop:
    ba      Done
    nop

rightRipple:
    neg     %i1, %l3                 ! Get the shift count in positive
    and     SIXBIT_MASK, %l3, %l3    ! Get the lower 6 bits of shiftCnt

    clr     %l4
    cmp     %l4, %l3
    bge     Done
    nop

st_loop1:
    and     %l0, LSB_MASK, %l2  ! Save the LSB of lightBank[0]
    sll     %l2, 31, %l2    ! LSB of lightBank[0] now in MSB
    and     %l1, LSB_MASK, %l6  ! Save the LSB of lightBank[1]
    sll     %l6, 31, %l6    ! LSB of lightBank[1] now in MSB
    srl     %l0, 1, %l0     ! Right logic shift for lightBank[0]
    or      %l6, %l0, %l0   ! lightBank[1] has a correct MSB
    srl     %l1, 1, %l1     ! Right logic shift for lightBank[1]
    or      %l2, %l1, %l1   ! lightBank[1] has a correct MSB

    st      %l0, [%i0]      ! Store the new value back
    st      %l1, [%i0+4]

    mov     %i0, %o0       ! display the bank patterns
    call    displayLights
    nop

    inc     %l4
    cmp     %l4, %l3
    bl      st_loop1
    nop

Done:
    ret
    restore