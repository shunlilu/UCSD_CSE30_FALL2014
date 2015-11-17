/*
 * Filename: printEnglish.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Nov. 19, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

    .global printEnglish
    .section ".data"
zero:
    .asciz "zero "
one:
    .asciz "one "
two:
    .asciz "two "
three:
    .asciz "three "
four:
    .asciz "four "
five:
    .asciz "five "
six:
    .asciz "six "
seven:
    .asciz "seven "
eight:
    .asciz "eight "
nine:
    .asciz "nine "

digitsArr:
    .word zero, one, two, three, four, five
    .word six, seven, eight, nine

    .section ".text"

/*
 * Function name: printEnglish();
 * Function prototype: 
 *          void printEnglish( long num );
 * Description: print the value in english
 * Parameters:
 * arg 1: long num - the number need to be converted to english
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

printEnglish:
    save    %sp, -(92 + 4) & -8, %sp    ! Save caller's window
                                        ! Allocate 4 bytes on stack to
                                        ! store the LSD

    mov     %i0, %o0    ! Extract LSD
    mov     10, %o1
    call    .rem        ! num % 10
    nop
    mov     %o0, %l1

    st      %l1, [%fp - 4]  ! Store LSD on stack

    mov     %i0, %o0    ! Extract Remaining digits
    mov     10, %o1
    call    .div        ! num / 10
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











