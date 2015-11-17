/*
 * Filename: testclear.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: Unit test program to test the function set.
 * Date: Nov. 1, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include "pa2.h"
#include "test.h"


void
testclear(){
    int lightBank[] = {0xffffffff, 0xffffffff};
    
    printf( "Testing clear()\n");
    
    clear(lightBank, 0xffff0000, 0xAAAAAAAA);
    printf("%x, %x\n", lightBank[0], lightBank[1]);
    
    
    printf( "Finished running tests on clear()\n" );
}

int
main(){
    testclear();
    
    return 0;
}
