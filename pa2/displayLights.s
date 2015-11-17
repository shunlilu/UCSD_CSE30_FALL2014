/*
 * Filename: displayLights.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: SPARC assembly routine to display the light banks
 * Date: Oct. 25, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

    .global displayLights
    .section ".text"

/*
 * Function name: displayLights()
 * Function prototype: 
 *      void displayLights(const unsigned int lightBank[]);
 * Description: display te light banks
 * Parameters:
 * arg 1:
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: None.
 *
 * Registers Used:
 * %i0 - arg 1 -- the address of the str need to be converted
 * %i1 - arg 2 -- the base of the str
 * %l0 - First light bank
 * %l1 - Second light bank
 * %l2 - Masker
 * %l3 - tmp
 * %l4 - loop1 index i
 * %l5 - loop2 index j
 * %l6 - loop3 index k
 */

 /* Constant */
 MASKER  = 0x80000000
 ASCII_DASH = 45
 ASCII_STAR = 42
 ASCII_SPACE = 32
 NEWLINE = "\n"
 NUM_OF_BANKS = 2

displayLights:
    save    %sp, -96 , %sp       ! Save caller's windows

    set     MASKER, %l2
    ld      [%i0], %l0          ! Get the first light bank
    ld      [%i0+4], %l1        ! Get the second light bank

    clr     %l4                 ! Loop1 starts
    cmp     %l4, NUM_OF_BANKS
    bge     end_loop1
    nop

st_loop1:
    clr     %l5                 ! Loop2 starts
    cmp     %l5, 8
    bge     end_loop2
    nop

st_loop2:                       ! Loop3 starts
    clr     %l6
    cmp     %l6, 4
    bge     end_loop3
    nop

st_loop3:
    andcc   %l0, %l2, %l3       ! Extract the particular bit
    bne     star                ! Check for zero condition bit
    nop

    mov     ASCII_DASH, %o0     ! Light is off
    call    printChar           ! Print a dash
    nop
    ba      printDone
    nop


star:
    mov     ASCII_STAR, %o0     ! Light is on
    call    printChar           ! Print a star
    nop


/* end_loop3:*/
printDone:
    srl     %l2, 1, %l2         ! Logic right shift 1 bit

    inc     %l6                 ! Loop3 check
    cmp     %l6,4
    bl      st_loop3
    nop

end_loop3:
    mov     ASCII_SPACE, %o0    ! Print a space
    call    printChar
    nop

/* end_loop3: */
    inc     %l5                 ! Loop2 Check
    cmp     %l5, 8
    bl      st_loop2
    nop


end_loop2:
    mov     %l1 , %l0           ! Get the second bank light from %l1
    set     MASKER, %l2         ! Reset the MASKER
    inc     %l4                 ! Loop1 Check
    cmp     %l4, NUM_OF_BANKS
    bl      st_loop1
    nop

    mov     NEWLINE, %o0        ! Print a new line
    call    printChar
    nop

end_loop1:
    ret
    restore














