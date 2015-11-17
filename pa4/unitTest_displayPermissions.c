/*
 * Filename: unitTest_displayPermissions.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Dec. 6, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include <stdio.h>

#include "test.h"
#include "myls.h"

int main(){
    
    printf( "Testing displayPermissions()\n");
    
    struct fileInfo info1;
    
    /* Test 1 */
    info1.stbuf.st_mode = S_IRWXU;
    displayPermissions(info1.stbuf.st_mode);
    (void)printf("\n");
    
    /* Test 2 */
    
    info1.stbuf.st_mode = S_IRWXG;
    displayPermissions(info1.stbuf.st_mode);
    (void)printf("\n");
    
    /* Test 3 */
    info1.stbuf.st_mode = S_IRWXO;
    displayPermissions(info1.stbuf.st_mode);
    (void)printf("\n");
    
    /* Test 4 */
    info1.stbuf.st_mode = S_IRWXO+S_IRWXG;
    displayPermissions(info1.stbuf.st_mode);
    (void)printf("\n");
    
    /* Test 5 */
    info1.stbuf.st_mode = S_IRUSR+S_IXOTH+S_IWGRP;
    displayPermissions(info1.stbuf.st_mode);
    (void)printf("\n");

    
    printf( "Finished running tests on displayPermissions()\n" );
    
    return 0;
}
