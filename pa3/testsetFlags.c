/*
 * Filename: testsetFlags.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Nov. 18, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include <stdio.h>
#include "pa3.h"

    
    
int
main(int argc, char* argv[]){
    struct argsInfo tmp;
    printf( "Finished running tests on setFlags()\n" );
    
    tmp = setFlags(argc, argv+1);
    printf( "mode = 0x%02X, inputBase = %d, outputBases = 0x%llX, inFileStr = %s\n",\
            tmp.mode, tmp.inputBase,tmp.outputBases, tmp.inFileStr);
    printf( "Testing setFlags()\n");
    return 0;
}
