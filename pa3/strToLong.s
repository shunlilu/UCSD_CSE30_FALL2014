/*
 * Filename: strToULong.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: SPARC assembly routine to convert the string
 *              to unsigned long integer
 * Date: Oct. 25, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

    .global strToLong
    .section ".text"

/*
 * Function name: strToULong()
 * Function prototype: 
 *      unsigned long strToULong( const char * str, const int base);
 * Description: Convert the string to unsigned long integer
 * Parameters:
 * arg 1: char * str -- the string need to be converted
 * arg 2: int base -- the base the number
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: None.
 *
 * Registers Used:
 * %i0 - arg 1 -- the address of the str need to be converted
 * %i1 - arg 2 -- the base of the str
 * %l0 - address of errno
 * %l2 - address of ptrError
 */

/* Constant */
PTRSIZ = 4
ptrOffset = 4

strToLong:
    save    %sp, -(92 + PTRSIZ) & -8, %sp    ! Save call's windows
                                        ! Allocate space for endptr

    set     errno, %l0      ! Set the address of errno into %l1
    st      %g0, [%l0]      ! errno = 0

    mov     %i0, %o0        ! Pass the str to strtol
    add     %fp, -ptrOffset, %o1    ! Generate the address of endptr
    mov     %i1, %o2        ! Pass the base to strtol
    call    strtol
    nop


    ld      [%fp-ptrOffset], %l1      ! Get the value of endptr
    ldub    [%l1], %l1      ! Get the value of the char pointed by endptr
    cmp     %l1, %g0          ! Check if *endptr = 0
    be      endptr_OK
    nop

    /* if statements */
    set     ptrError, %l2   ! Set the address of ptrError into %l2
    ld      [%l2], %l3      !
    st      %l3, [%l0]      ! Set the errno to ptrError

endptr_OK:
    mov     %o0, %i0        ! Return value
    ret
    restore
