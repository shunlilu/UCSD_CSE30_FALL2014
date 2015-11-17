/*
 * Filename: unitTest_displayGroupName.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Dec. 7, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include <stdio.h>

#include "test.h"
#include "myls.h"

int main(){
    
    printf( "Testing displayGroupName()\n");
    
    struct fileInfo info1;
    
    /* Test 1 */
    info1.stbuf.st_gid = 111;
    displayGroupName(info1.stbuf.st_gid);
    (void)printf("\n");
    
    /* Test 2 */
    info1.stbuf.st_gid = 2;
    displayGroupName(info1.stbuf.st_gid);
    (void)printf("\n");
    
    /* Test 3 */
    info1.stbuf.st_gid = 3333;
    displayGroupName(info1.stbuf.st_gid);
    (void)printf("\n");
    
    /* Test 4 */
    info1.stbuf.st_gid = 44;
    displayGroupName(info1.stbuf.st_gid);
    (void)printf("\n");
    
    /* Test 5 */
    info1.stbuf.st_gid = 55555;
    displayGroupName(info1.stbuf.st_gid);
    (void)printf("\n");
    
    
    printf( "Finished running tests on displayGroupName()\n" );
    
    return 0;
}
