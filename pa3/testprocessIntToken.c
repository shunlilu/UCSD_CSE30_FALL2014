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
    int argc = 8;
    char * argv[] = { "foo", "-e", "-i", "2", "-o", "2", "--", "-100"};
    
    printf( "Start testing processIntToken()\n");
    
    info = setFlags(argc, argv);
    processIntToken("-a100abc", info);
    processIntToken("999999999999999999999999999999", info);
    processIntToken(argv[7], info);
   
    printf("\n");
    
    int argc1 = 6;
    char * argv1[] = { "foo", "-e", "-o", "8", "--", "-235"};
    optarg = NULL;
    optind = 1;
    info = setFlags(argc1, argv1);
    processIntToken(argv1[5], info);

    printf("\n");
    
    int argc2 = 5;
    char * argv2[] = { "foo", "-e", "-o", "10", "397"};
    optarg = NULL;
    optind = 1;
    info = setFlags(argc2, argv2);
    processIntToken(argv2[4], info);
    
    printf("\n");
    
    int argc3 = 8;
    char * argv3[] = { "foo", "-e", "-i", "16", "-o",\
                       "10", "--", "-fea12"};
    optarg = NULL;
    optind = 1;
    info = setFlags(argc3, argv3);
    processIntToken(argv3[7], info);
    
    
    printf( "Finished running tests on processIntToken()\n" );
    return 0;
}
