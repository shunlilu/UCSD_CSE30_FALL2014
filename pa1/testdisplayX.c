/*
 * Filename: testdisplayX.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: Unit test program to test the function printChar.
 * Date: Oct. 19, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include "pa1.h"
#include "test.h"

void
testdisplayX(){
    printf( "Testing displayX()\n");
    
    displayX(8, 32, 45,35);
    displayX(16, 55, 44,66);
    
    printf( "Finished running tests on displayX()\n" );
}

int
main(){
    testdisplayX();
    
    return 0;
}
