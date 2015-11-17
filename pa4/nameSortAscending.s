/*
 * Filename: nameSortAscending.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Dec. 5, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

	.global nameSortAscending
    	.section ".text"

/*
 * Function name: nameSortAscending()
 * Function prototype: 
 *      int nameSortAscending( const void *p1, const void *p2 );
 * Description: Sort the name of the two items in ascending order
 * Parameters:
 * arg 1: void * p1 -- item 1
 * arg 2: void * p2 -- item 2
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: None.
 *
 * Registers Used:
 * %o0 - arg 1 -- *p1
 * %o1 - arg 2 -- *p2
 * %o2 - iteration index i
 * %o3 - char pointed by p1
 * %o4 - char pointed by p2
 * %05 - maxNameLen
 */


nameSortAscending:
    	set     maxNameLen, %o5	! Get the maximum filename length
    	ld      [%o5], %o5

    	clr     %o2		! while (i <= maxNameLen)
    	cmp     %o2, %o5
    	bg      end_loop
    	nop

st_loop:
    	ldub    [%o0], %o3	! Dereference p1+i
    	ldub    [%o1], %o4    	! Dereference p2+i

    	cmp     %o3, '\0'	! Check if string ends
    	bne     compare
    	nop

    	cmp     %o4, '\0'       ! Check if string ends
    	be      end_loop
    	nop
compare:
    	cmp     %o3, %o4        ! Check if *p1 = *p2
    	bne     notEqual
    	nop	

    	inc     %o0             ! p1++
    	inc     %o1             ! p2++

    	inc     %o2             ! while (i <= maxNameLen)
    	cmp     %o2, %o5
    	ble     st_loop
    	nop

end_loop:
    	mov     0, %o0          ! p1 == p2, return 0
    	retl
    	nop


notEqual:
    	cmp     %o3, %o4
    	bg      greaterThan
    	nop

    	mov     -1, %o0         ! p1 < p2, return -1
    	retl
    	nop

greaterThan:
    	mov     1, %o0		! *p1 > *p2, return 1
    	retl
    	nop


