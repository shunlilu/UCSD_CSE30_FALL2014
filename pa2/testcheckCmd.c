/*
 * Filename: testcheckCmd.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: Unit test program to test the function checkCmd.
 * Date: Oct. 25, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include <string.h> 
#include "pa2.h"
#include "test.h"


void
testcheckCmd(){
    const char * commands[] = {COMMANDS};
    int tmp;
    
    printf( "Testing checkCmd()\n");
    
    TEST( checkCmd("set",commands)== 0);
    TEST( checkCmd("clear",commands)== 1);
    TEST( checkCmd("toggle",commands)== 2);
    TEST( checkCmd("shift",commands)== 3);
    TEST( checkCmd("rotate",commands)== 4);
    TEST( checkCmd("ripple",commands)== 5);
    TEST( checkCmd("help",commands)== 6);
    TEST( checkCmd("quit",commands)== 7);
    tmp = checkCmd("\n",commands);
    tmp = checkCmd("", commands);
    
    printf( "Finished running tests on checkCmd()\n" );
}

int
main(){
    testcheckCmd();
    
    return 0;
}