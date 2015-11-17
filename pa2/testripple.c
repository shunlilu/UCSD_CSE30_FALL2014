/*
 * Filename: testripple.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: Unit test program to test the function rotate.
 * Date: Nov. 1, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include "pa2.h"
#include "test.h"


void
testripple(){
    int lightBank[] = {0xffffffff, 0x00000000};
    
    printf( "Testing ripple()\n");
    
    ripple(lightBank,-4);
    ripple(lightBank,4);
    ripple(lightBank, 32);
    ripple(lightBank, -20);

    
    
    
    printf( "Finished running tests on ripple()\n" );
}

int
main(){
    testripple();
    
    return 0;
}
