/*
 * Filename: testtoggle.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: Unit test program to test the function toggle.
 * Date: Oct. 30, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include "pa2.h"
#include "test.h"


void
testtoggle(){
    int lightBank[] = {0x10101010, 0x11111111};
    
    printf( "Testing toggle()\n");
    
    toggle(lightBank, 0x10101010, 0x80808080);
    printf("%x, %x\n", lightBank[0], lightBank[1]);
    
    
    printf( "Finished running tests on toggle()\n" );
}

int
main(){
    testtoggle();
    
    return 0;
}
