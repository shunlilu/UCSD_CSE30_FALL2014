/*
 * Filename: displayGroupName.s
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Dec. 5, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */
 	.global displayGroupName
    	.section ".data"
STR_GNAME:
    	.asciz "%-8s "
STR_GID:
    	.asciz "%-8ld "
    	.section ".text"

/*
 * Function name: displayGroupName()
 * Function prototype: 
 *      void displayGroupName( const gid_t gid );
 * Description: display the group name of file or directory
 * Parameters:
 * arg 1: const gid_t gid
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: None.
 * Registers Used:
 * %i0 - arg 1
 */

 displayGroupName:
    	save    %sp, -96, %sp		! Save caller's window

    	mov     %i0, %o0               	! getgrgid(uid)
    	call    getgrgid
    	nop

    	cmp     %o0, %g0            	! check if it is NULL
    	be      printNumerical
    	nop

    	ld      [%o0], %o1              ! get gr_name
    	set     STR_GNAME, %o0          ! print the group name
    	call    printf
    	nop

    	ret
    	restore

printNumerical:
    	set     STR_GID, %o0            ! Cannot get group name
    	mov     %i0, %o1                ! print the gid
    	call    printf
    	nop

    	ret
    	restore

