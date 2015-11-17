/*
 * Filename: displayX.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: SPARC assembly routine to display X pattern
 *              Called from main()
 * Date: Oct. 19, 2014
 * Sources of Help: CSE30 course website.
 */
        .global displayX

        .section ".text"

/*
 * Function name: displayX()
 * Function prototype: void displayX( long size, long xChar,
 *                                    long fillerChar, long borderChar)
 * Parameters:
 * arg 1: long size -
 * arg 2: long xChar - 
 * arg 3: long fillerChar - 
 *
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: 0 - arg 1 is not within the range
 *               1 - arg 1 is within the range
 * Registers Used:
 * %i0 - arg 1 - long size
 * %i1 - arg 2 - long xChar
 * %i2 - arg 3 - long fillerChar
 * %i3 - arg 4 - long borderChar
 * %l0 - row counter
 * %l1 - column counter
 * %l2 - border counter
 * %l3 - number of digits of size
 * %l4 - numOfDigits(size, BASE)*2 +size
 * %l5 - size - col - 1
 */

 
/* Constant */
    BASE = 10
    NL = 10


displayX:
        save    %sp, -96, %sp


        mov     %i0, %o0        ! Get the number of digits of size
        mov     BASE, %o1
        call    numOfDigits
        nop
        mov     %o0, %l3        ! Pass the result to %l3

        mov       2, %o1        ! Calculate numOfDigits(size, BASE)*2 +size
        call    .mul
        nop
        add     %o0, %i0, %l4   ! Pass the result to %l4

/*
 * Display the top border
 *
 */
        clr     %l0
        cmp     %l0, %l3
        bge     end_loop1       ! loop1 negative logic
        nop
st_loop1:

        clr     %l1
        cmp     %l1, %l4
        bge     end_loop2       ! loop2 negative logic
        nop

st_loop2:
        mov     %i3, %o0        ! Print the borderChar
        call    printChar
        nop

end_loop2:
        inc     %l1             ! loop2 positive logic
        cmp     %l1, %l4
        bl      st_loop2
        nop

        set     NL, %o0         ! Print the new line
        call    printChar
        nop

end_loop1:
        inc     %l0
        cmp     %l0, %l3
        bl      st_loop1        ! loop1 positive logic
        nop

/*
 * Display the X patter with border on either side of the X
 *
 */

        clr     %l0
        cmp     %l0, %i0
        bge     end_loop3
        nop

st_loop3:
        clr     %l2
        cmp     %l2, %l3
        bge     end_loop4
        nop

st_loop4:
        mov     %i3, %o0        ! Print borderChar
        call    printChar
        nop

end_loop4:
        inc     %l2             ! Increase border counter
        cmp     %l2, %l3
        bl      st_loop4
        nop

        clr     %l1
        cmp     %l1, %i0
        bge     end_loop5
        nop

st_loop5:
        /* If statememt begins */
        cmp     %l0, %l1        ! Check for row = column
        bne     Condition2
        nop

        /* Print the xChar */
xChar:
        mov     %i1, %o0
        call    printChar
        nop

        ba      end_loop5
        nop

Condition2:
        sub     %i0, %l1, %l5
        dec     %l5             ! Check for %l5 = size - col -1
        cmp     %l0, %l5
        be      xChar
        nop

else:
        /* Print the fillerChar */
        mov     %i2, %o0
        call    printChar
        nop

/*Label end_if as well*/
end_loop5:
        inc     %l1
        cmp     %l1, %i0
        bl      st_loop5
        nop

        clr     %l2
        cmp     %l2, %l3
        bge     end_loop6
        nop

st_loop6:
        /* print the borderChar */
        mov     %i3, %o0
        call    printChar
        nop

end_loop6:
        inc     %l2
        cmp     %l2, %l3
        bl      st_loop6
        nop

        /* Print the new line */
        mov     NL, %o0
        call    printChar
        nop

end_loop3:
        inc     %l0             ! Increse row counter
        cmp     %l0,%i0
        bl      st_loop3
        nop

/*
 * Display the bottom border
 *
 */
        clr     %l0
        cmp     %l0, %l3
        bge     end_loop7       ! loop1 negative logic
        nop
st_loop7:

        clr     %l1
        cmp     %l1, %l4
        bge     end_loop8       ! loop2 negative logic
        nop

st_loop8:
        mov     %i3, %o0        ! Print the borderChar
        call    printChar
        nop

end_loop8:
        inc     %l1             ! loop2 positive logic
        cmp     %l1, %l4
        bl      st_loop8
        nop

        set     NL, %o0         ! Print the new line
        call    printChar
        nop

end_loop7:
        inc     %l0
        cmp     %l0, %l3
        bl      st_loop7        ! loop1 positive logic
        nop

        ret
        restore























