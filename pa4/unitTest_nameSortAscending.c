/*
 * Filename: unitTest_nameSortAscending.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Dec. 5, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#include "test.h"
#include "myls.h"

int main(){
    
    printf( "Testing nameSortAscending()\n");
    
    struct fileInfo info1;
    struct fileInfo info2;
    
    /* Test 1 - less than */
    memset(info1.name, 0, MAXNAMLEN);
    strcpy(info1.name, "foan");
    memset(info2.name, 0, MAXNAMLEN);
    strcpy(info2.name, "fooo");
    TEST(nameSortAscending(&info1, &info2) == -1);
    
    /* Test 2 - equal to */
    memset(info1.name, 0, MAXNAMLEN);
    strcpy(info1.name, "farrrrrr");
    memset(info2.name, 0, MAXNAMLEN);
    strcpy(info2.name, "farrrrrr");
    TEST(nameSortAscending(&info1, &info2) == 0);
    
    /* Test 3 - greater than */
    memset(info1.name, 0, MAXNAMLEN);
    strcpy(info1.name, "fur");
    memset(info2.name, 0, MAXNAMLEN);
    strcpy(info2.name, "aaaaaaaa");
    TEST(nameSortAscending(&info1, &info2) == 1);
    
    printf( "Finished running tests on nameSortAscending()\n" );
    
    return 0;
}
