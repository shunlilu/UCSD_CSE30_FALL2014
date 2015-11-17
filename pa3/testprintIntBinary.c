/*
 * Filename: testsetFlags.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Nov. 18, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include "strings.h"
#include "pa3.h"
#include "test.h"

int
main(){
    printf( "Testing setFlags()\n");
    printIntBinary(0);
    printIntBinary(7);
    printIntBinary(0xffffffff);
    printf( "Finished running tests on setFlags()\n" );
    return 0;
}
