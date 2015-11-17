/*
 * Filename: teststrToLong.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: Unit test program to test the function strToLong.
 * Date: Oct. 14, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include "pa1.h"
#include "test.h"


void
teststrToLong(){
    printf( "Testing strToLong()\n");
    
    TEST( strToLong("1aba1",10));
    TEST( strToLong("123",10)==123);
    TEST( strToLong("a",10));
    TEST( strToLong("999999999999999",10));
    
    printf( "Finished running tests on teststrToLong()\n" );
}

int
main(){
    teststrToLong();
    
    return 0;
}