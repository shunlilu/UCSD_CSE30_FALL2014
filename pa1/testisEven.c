/*
 * Filename: testisEven.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: Unit test program to test the function isEven.
 * Date: Oct. 14, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include "pa1.h"
#include "test.h"


void
testisEven(){
    printf( "Testing isEven()\n");
    
    TEST( isEven(1)==1);
    TEST( isEven(2)==1);
    TEST( isEven(-1)==0);
    TEST( isEven(0)==1);
    TEST( isEven(100)==1);
    TEST( isEven(-100)==1);
    
    printf( "Finished running tests on isEven()\n" );
}

int
main(){
    testisEven();
    
    return 0;
}
