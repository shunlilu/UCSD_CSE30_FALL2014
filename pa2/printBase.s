/*
 * Filename: printBase.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Nov. 19, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

    .global printBase
    .section ".data"

Arr:
    .byte '0', '1', '2', '3', '4', '5', '6', '7'
    .byte '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
    .byte 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N'
    .byte 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'
    .byte 'W', 'X', 'Y', 'Z', '\0'

    .section ".text"

/*
 * Function name: printBase();
 * Function prototype: 
 *          void printBase( long num, int base );
 * Description: recursively print a long integer in the given base.
 * Parameters:
 * arg 1: long num - the number need to be converted
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: None.
 *
 * Registers Used:
 * %i0 - num
 * %l0 - i
 * %l1 - Least significant digit
 * %l2 - Remaining digits
 * %l3 - index of the digitsArr for LSD
 * %l4 - address of digitsArr
 * %l5 - address of the desired digit
 */

printBase:
    save    %sp, -(92 + 4) & -8, %sp    ! Save caller's window
                                        ! Allocate 4 bytes on stack to
                                        ! store the LSD

    mov     %i0, %o0    ! Extract LSD
    mov     %i1, %o1
    call    .rem        ! num % base
    nop
    mov     %o0, %l1

    st      %l1, [%fp - 4]  ! Store LSD on stack

    mov     %i0, %o0    ! Extract Remaining digits
    mov     %i1, %o1
    call    .div        ! num / base
    nop
    mov     %o0, %l2

    cmp     %l2, %g0    ! Check for base case
    be      base
    nop

    mov     %l2, %o0    ! Copy of remaining digits to printEnglish
    call    printEnglish    ! Recursively call printEnglish
    nop

base:
    ld      [%fp -4], %o0   ! Get the LSD on stack
    mov     4, %o1
    call    .mul            ! Compute LSD*4, which is the offset
    nop                     ! of the corresponding number in
    mov     %o0, %l3        ! digitsArr

    set     digitsArr, %l4
    add     %l4, %l3, %l5   ! Compute digitsArr + offset
    ld      [%l5], %o0      ! Load the desired number in English

    call    printf
    nop

    ret
    restore
