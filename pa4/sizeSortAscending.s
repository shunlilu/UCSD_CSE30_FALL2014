/*
 * Filename: sizeSortAscending.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Oct. 25, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

 	.global sizeSortAscending
	.section ".text"

/*
 * Function name: sizeSortAscending()
 * Function prototype: 
 *      int sizeSortAscending( const void *p1, const void *p2 );
 * Description: Sort the size of the two items in ascending order
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
 * %o2 - sizeOffset
 * %o3 - bufOffset
 * %o4 - sizeOffset + bufOffset
 */

sizeSortAscending:

	set	sizeOffset, %o2		! Get the value of global
    	ld	[%o2], %o2          	! variable sizeOffset

    	set	bufOffset, %o3      	! Get the value of global
    	ld	[%o3], %o3          	! variable bufOffset

    	add	%o2, %o3, %o4       	! sizeOffset + bufOffset

    	add	%o0, %o4, %o0       	! p1 + sizeOffset + bufOffset
    	add	%o1, %o4, %o1       	! p2 + sizeOffset + bufOffset

    	ld	[%o0], %o0          	! Get st_size of *p1
    	ld	[%o1], %o1          	! Get st_size of *p2

    	cmp	%o0, %o1            	! Compare st_size
    	bg	greaterThan
    	nop

    	cmp	%o0, %o1
    	be      equalTo
    	nop

    	mov	-1, %o0             	! *p1 < *p2, return -1
    	retl
    	nop

equalTo:
    	mov	0, %o0              	! *p1 = *p2, return 0
    	retl
    	nop

greaterThan:
    	mov	1, %o0              	! *p1 > *p2, return 1
    	retl
    	nop







