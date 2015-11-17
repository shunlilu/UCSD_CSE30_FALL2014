/*
 * Filename: testprintChar.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: Unit test program to test the function printChar.
 * Date: Oct. 14, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include "pa1.h"
#include "test.h"


void
testprintChar(){
    printf( "Testing printChar()\n");
    
    TEST( printChar(35));
    TEST( printChar("\n"));
    
    printf( "Finished running tests on printChar()\n" );
}

int
main(){
    testprintChar();
    
    return 0;
}
