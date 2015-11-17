/*
 * Filename: testdisplayLights.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: Unit test program to test the function displayLights.
 * Date: Oct. 26, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include "pa2.h"
#include "test.h"


void
testdisplayLights(){
    int lightbanks[2];
    lightbanks[0] = 0xFFFFFFFF;
    lightbanks[1] = 0x00000000;
    
    printf( "Testing displayLights()\n");
    
    displayLights(lightbanks);

    printf( "Finished running tests on displayLights()\n" );
}

int
main(){

    testdisplayLights();
    
    return 0;
}