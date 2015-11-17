/*
 * Filename: testprintBase.c
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
    
    printf( "Start testing printBase()\n");
    
    for (i=2; i <= 36; i++) {
        printBase(100,i);
        printf("\n");
    }

    printf( "Finished running tests on printBase()\n" );
    return 0;
}
