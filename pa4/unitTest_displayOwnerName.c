/*
 * Filename: unitTest_displayOwnerName.c
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
    
    printf( "Testing displayOwnerName()\n");
    
    struct fileInfo info1;
    
    /* Test 1 */
    info1.stbuf.st_uid = 111;
    displayOwnerName(info1.stbuf.st_uid);
    (void)printf("\n");
    
    /* Test 2 */
    info1.stbuf.st_uid = 2;
    displayOwnerName(info1.stbuf.st_uid);
    (void)printf("\n");
    
    /* Test 3 */
    info1.stbuf.st_uid = 3333;
    displayOwnerName(info1.stbuf.st_uid);
    (void)printf("\n");
    
    /* Test 4 */
    info1.stbuf.st_uid = 44;
    displayOwnerName(info1.stbuf.st_uid);
    (void)printf("\n");
    
    /* Test 5 */
    info1.stbuf.st_uid = 55555;
    displayOwnerName(info1.stbuf.st_uid);
    (void)printf("\n");
    
    
    printf( "Finished running tests on displayOwnerName()\n" );
    
    return 0;
}
