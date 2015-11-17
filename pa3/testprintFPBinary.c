/*
 * Filename: testprintFPBinary.c
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
    printf( "Testing printFPBinary()\n");
    
    printFPBinary(0.0);
    (void) printf("\n");
    
    printFPBinary(23.56);
    (void) printf("\n");
    
    printFPBinary(104.5643);
    (void) printf("\n");
    
    printFPBinary(924.00042);
    (void) printf("\n");
    
    printFPBinary(-823.56);
    (void) printf("\n");
    
    printFPBinary(-0.0023);
    (void) printf("\n");
    
    printf( "Finished running tests on printFPBinary()\n" );
    return 0;
}