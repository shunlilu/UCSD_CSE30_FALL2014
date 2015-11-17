/*
 * Filename: printIntBinary.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Nov. 19, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

    .global printIntBinary
    .section ".data"
fmt:
    .asciz  "%c"
    .section ".text"

/*
 * Function name: printIntBinary();
 * Function prototype: 
 *          void printIntBinary( long num );
 * Description: print the value in binary representation
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
 * %l1 - Loop index j
 * %l2 - Masker
 * %l3 - tmp
 */

MASKER  = 0x80000000
ZERO = '0'
ONE = '1'
SPACE = ' '
NEWLINE = '\n'


printIntBinary:
    save    %sp, -96 , %sp       ! Save caller's windows

    set     MASKER, %l2

    clr     %l0                 ! Loop starts
    cmp     %l0, 8
    bge     end_loop1
    nop

st_loop1:                        ! Loop2 starts
    clr     %l1
    cmp     %l1, 4              ! A space every 4 bits
    bge     end_loop2
    nop

st_loop2:
    andcc   %i0, %l2, %l3       ! Extract the particular bit
    bne     printOne            ! Check for zero condition bit
    nop

    set     fmt, %o0
    mov     ZERO, %o1           ! Print zero
    call    printf
    nop

    ba      printDone
    nop

printOne:
    set     fmt, %o0
    mov     ONE, %o1            ! Print one
    call    printf
    nop

printDone:
    srl     %l2, 1, %l2         ! Logic right shift 1 bit

    inc     %l1                 ! Loop2 check
    cmp     %l1,4
    bl      st_loop2
    nop

end_loop2:
    set     fmt, %o0
    mov     SPACE, %o1          ! Print a space every 4 bits
    call    printf
    nop

    inc     %l0                 ! Loop1 Check
    cmp     %l0, 8
    bl      st_loop1
    nop

end_loop1:
    set     fmt, %o0
    mov     NEWLINE, %o1        ! Print a new line
    call    printf
    nop

    ret
    restore