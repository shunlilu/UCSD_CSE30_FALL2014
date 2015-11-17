/*
 * Filename: testrotate.c
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
testrotate(){
    int lightBank[] = {0xffffffff, 0x00000000};
    
    printf( "Testing rotate()\n");
    
    rotate(lightBank,-4);
    printf("%x, %x\n", lightBank[0], lightBank[1]);
    rotate(lightBank,4);
    printf("%x, %x\n", lightBank[0], lightBank[1]);
    rotate(lightBank,-32);
    printf("%x, %x\n", lightBank[0], lightBank[1]);
    rotate(lightBank,32);
    printf("%x, %x\n", lightBank[0], lightBank[1]);
    rotate(lightBank,32);
    printf("%x, %x\n", lightBank[0], lightBank[1]);
    
    
    
    printf( "Finished running tests on rotate()\n" );
}

int
main(){
    testrotate();
    
    return 0;
}
