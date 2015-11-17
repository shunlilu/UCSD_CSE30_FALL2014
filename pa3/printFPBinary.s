/*
 * Filename: printIntBinary.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Nov. 19, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

    .global printFPBinary
    .section ".data"
fmt:
    .asciz  "%c"
    .section ".text"

/*
 * Function name: printFPBinary();
 * Function prototype: 
 *          void printFPBinary( float num );
 * Description: print the floating value in binary representation
 * Parameters:
 * arg 1: long num - the number need to be converted to 
 *                   binary representation
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: None.
 *
 * Registers Used:
 * %i0 - arg 1
 * %l0 - Loop index i
 * %l2 - Masker
 */

MASKER  = 0x80000000
ZERO = '0'
ONE = '1'
SPACE = ' '
NEWLINE = '\n'

printFPBinary:
    save    %sp, -96, %sp       ! Save caller's windows

    set     MASKER, %l2

    andcc   %i0, %l2, %l3        ! Extract the sign bit
    bne     signOne
    nop

signZero:
    set     fmt, %o0            ! Print sign bit of zero
    mov     ZERO, %o1
    call    printf
    nop

    ba      signDone
    nop

signOne:
    set     fmt, %o0            ! Print sign bit of one
    mov     ONE, %o1
    call    printf
    nop

signDone:
    srl     %l2, 1, %l2         ! MASKER logic right shifts 1 bit
    set     fmt, %o0            ! Print a space after the
    mov     SPACE, %o1          ! sign bit
    call    printf
    nop

    clr     %l0
    cmp     %l0, 8              ! Loop 8 times for the exp. bits
    bge     expDone
    nop

expStart:
    andcc   %i0, %l2, %l3        ! Extract a exp bit
    bne     expOne
    nop

expZero:
    set     fmt, %o0            ! Print exp bit of zero
    mov     ZERO, %o1
    call    printf
    nop

    ba      expLoop
    nop

expOne:
    set     fmt, %o0            ! Print exp bit of one
    mov     ONE, %o1
    call    printf
    nop

expLoop:
    srl     %l2, 1, %l2         ! MASKER logic right shifts 1 bit
    inc     %l0
    cmp     %l0, 8
    bl      expStart
    nop

expDone:
    clr     %l0
    cmp     %l0, 23              ! Loop 23 times for the mantissa bits
    bge     mantDone
    nop

    set     fmt, %o0            ! Print a space after the
    mov     SPACE, %o1          ! exp. bits
    call    printf
    nop

mantStart:
    andcc   %i0, %l2, %l3        ! Extract a mantissa bit
    bne     mantOne
    nop

mantZero:
    set     fmt, %o0            ! Print exp bit of zero
    mov     ZERO, %o1
    call    printf
    nop

    ba      mantLoop
    nop

mantOne:
    set     fmt, %o0            ! Print exp bit of one
    mov     ONE, %o1
    call    printf
    nop

mantLoop:
    srl     %l2, 1, %l2         ! MASKER logic right shifts 1 bit
    inc     %l0
    cmp     %l0, 23
    bl      mantStart
    nop

mantDone:
    ret
    restore
































