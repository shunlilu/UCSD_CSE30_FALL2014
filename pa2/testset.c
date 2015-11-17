/*
 * Filename: testset.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: Unit test program to test the function set.
 * Date: Oct. 30, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include "pa2.h"
#include "test.h"


void
testset(){
    int lightBank[] = {0x00000000, 0x11111111};
    
    printf( "Testing set()\n");
    
    set(lightBank, 0x11112222, 0x12341234);
    printf("%x, %x\n", lightBank[0], lightBank[1]);

    
    printf( "Finished running tests on set()\n" );
}

int
main(){
    testset();
    
    return 0;
}
