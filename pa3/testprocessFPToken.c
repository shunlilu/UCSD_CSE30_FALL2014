/*
 * Filename: testprocessIntToken.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Nov. 23, 2014
 * Sources of Help: none.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "pa3.h"


int
main(){
    struct argsInfo info;
    int argc = 4;
    char * argv[] = { "foo", "-eb", "--", "-100.0"};
    
    printf( "Start testing processIntToken()\n");
    
    info = setFlags(argc, argv);
    processFPToken("-a100.abc", info);
    processFPToken(argv[3], info);
    (void) printf("\n");
    
    int argc1 = 4;
    char * argv1[] = { "foo", "-eb", "--", "-1.05"};
    optarg = NULL;
    optind = 1;
    info = setFlags(argc1, argv1);
    processFPToken(argv1[3], info);
    (void) printf("\n");
    
    int argc2 = 4;
    char * argv2[] = { "foo", "-eb", "--", "234.65709"};
    optarg = NULL;
    optind = 1;
    info = setFlags(argc2, argv2);
    processFPToken(argv2[3], info);
    (void) printf("\n");
    
    int argc3 = 4;
    char * argv3[] = { "foo", "-eb", "--", "-0.05"};
    optarg = NULL;
    optind = 1;
    info = setFlags(argc3, argv3);
    processFPToken(argv3[3], info);
    (void) printf("\n");
    
    printf( "Finished running tests on processIntToken()\n" );
    return 0;
}