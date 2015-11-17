/*
 * Filename: unitTest_setDisplayMode.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Dec. 2, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include <stdio.h>

#include "test.h"
#include "myls.h"
#include "strings.h"


int main(){
    
    printf( "Testing setDisplayMode()\n");
 
    int argc = 2;
    char * argv[] = { "myls", "-a"};
    TEST(setDisplayMode(argc, argv) == AFLAG);
    
    int argc1 = 2;
    char * argv1[] = { "myls", "-l"};
    optind = 1;
    optarg = NULL;
    TEST(setDisplayMode(argc1, argv1) == LFLAG);
    
    int argc2 = 2;
    char * argv2[] = { "myls", "-r"};
    optind = 1;
    optarg = NULL;
    TEST(setDisplayMode(argc2, argv2) == RFLAG);
    
    int argc6 = 3;
    char * argv6[] = { "myls", "-S", "-B"};
    optind = 1;
    optarg = NULL;
    TEST(setDisplayMode(argc6, argv6) == SFLAG + BFLAG);
    
    int argc3 = 3;
    char * argv3[] = { "myls", "-F", "-R"};
    optind = 1;
    optarg = NULL;
    TEST(setDisplayMode(argc3, argv3) == FFLAG + BRFLAG);
    
    int argc4 = 1;
    char * argv4[] = {"myls"};
    optind = 1;
    optarg = NULL;
    TEST(setDisplayMode(argc4, argv4) == 0);
    
    int argc5 = 2;
    char * argv5[] = {"myls", "-t"};
    optind = 1;
    optarg = NULL;
    TEST(setDisplayMode(argc5, argv5) == ERR_FLAG);
    
    printf( "Finished running tests on setDisplayMode()\n" );
    return 0;
}
