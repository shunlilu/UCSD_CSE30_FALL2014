/*
 * Filename: testnumOfDigits.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: Unit test program to test the function numOfDigits.
 * Date: Oct. 17, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include "pa1.h"
#include "test.h"


void
testnumOfDigits(){
    printf( "Testing numOfDigits()\n");
    
    TEST( numOfDigits(123,10) == 3);
    TEST( numOfDigits(0,10) == 1);
    TEST( numOfDigits(4,8) == 1);
    TEST( numOfDigits(345,6) == 4);
    
    printf( "Finished running tests on numOfDigits()\n" );
}

int
main(){
    testnumOfDigits();
    
    return 0;
}
