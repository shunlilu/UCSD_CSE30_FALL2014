/*
 * Filename: testshift.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: Unit test program to test the function shift.
 * Date: Oct. 30, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include "pa2.h"
#include "test.h"


void
testshift(){
    int lightBank[] = {0xffffffff, 0x00000000};
    
    printf( "Testing shift()\n");
    
    shift(lightBank,-32);
    printf("%x, %x\n", lightBank[0], lightBank[1]);
    shift(lightBank,32);
    printf("%x, %x\n", lightBank[0], lightBank[1]);
    shift(lightBank,32);
    printf("%x, %x\n", lightBank[0], lightBank[1]);
   
    
    
    printf( "Finished running tests on shift()\n" );
}

int
main(){
    testshift();
    
    return 0;
}
