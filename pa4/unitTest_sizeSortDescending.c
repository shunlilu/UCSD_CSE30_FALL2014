/*
 * Filename: unitTest_sizeSortDescending.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Dec. 5, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include <stdio.h>

#include "test.h"
#include "myls.h"

int main(){
    
    printf( "Testing sizeSortDescending()\n");
    
    struct fileInfo info1;
    struct fileInfo info2;
    
    /* Test 1 - less than */
    info1.stbuf.st_size = 1;
    info2.stbuf.st_size = 2;
    TEST(sizeSortDescending(&info1, &info2) == 1);
    
    /* Test 2 - equal to */
    info1.stbuf.st_size = -755;
    info2.stbuf.st_size = -755;
    TEST(sizeSortDescending(&info1, &info2) == 0);
    
    /* Test 3 - greater than */
    info1.stbuf.st_size = 4;
    info2.stbuf.st_size = -1001;
    TEST(sizeSortDescending(&info1, &info2) == -1);
    
    printf( "Finished running tests on sizeSortDescending()\n" );
    
    return 0;
}

