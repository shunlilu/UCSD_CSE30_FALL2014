/*
 * Filename: teststrToULong.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: Unit test program to test the function strToULong.
 * Date: Oct. 26, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include <errno.h>
#include "pa2.h"
#include "test.h"

int ptrError = EINVAL;

void
teststrToULong(){
    
    printf( "Testing strToULong()\n");
    
    TEST( strToULong("999", 10)== 999);
    TEST( strToULong("123",10)== 123);
    TEST( strToULong("123ab",10)== 1);
    TEST( strToULong("999999999999999999",10)== 1);

    
    printf( "Finished running tests on strToULong()\n" );
}

int
main(){
    
    teststrToULong();
    
    return 0;
}