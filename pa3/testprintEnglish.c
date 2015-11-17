/*
 * Filename: testprintEnglish.c
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
    
    printf( "Start testing printEnglish()\n");
    
    printEnglish(58234);
    printf("\n");
    printEnglish(99);
    printf("\n");
    printEnglish(10800);
    printf("\n");
    
    printf( "Finished running tests on printEnglish()\n" );
    return 0;
}