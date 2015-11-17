/*
 * Filename: processFPToken.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Nov. 24, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "pa3.h"
#include "strings.h"

/*
 * Function name: processFPToken()
 * Function protorype:
 *      processFPToken( char* inStr, struct argsInfo info);
 * Description: process one input string (with a '.') and
 *              prints it out in correct format(s).
 * Error Conditions: None.
 * Return None.
 */



void processFPToken( char* inStr, struct argsInfo info){
    float fpToken;
    long preDotNum, postDotNum;
    char* dotPtr;
    char* str;
    char* endptr;
    
    ptrError = EINVAL;

    errno = 0;
    // Conver string to floating number
    fpToken = strtod(inStr, &endptr);
    
    /* Check for invalid floating numbers */
    if (*endptr != 0) {
        (void) fprintf(stderr, STR_FLOAT_ENDPTR_ERR, inStr);
        return;
    }
    
    /* Check for conversion errors */
    if (errno) {
        perror(inStr);
        return;
    }
    
    /* Print English mode */
    if (info.mode & E_FLAG) {
        /* Print out minus sign for negative number */
        if (fpToken < 0) {
            (void) printf(STR_MINUS);
        }
        /* Create another string in heap memory to store
         * inStr, and thus it can be modified
         */
        str = (char*) malloc(strlen(inStr)+1);
        // Check for successful memory allocation
        if (str == NULL) {
            (void) fprintf(stderr, STR_MALLOC_ERR);
            exit(1);
        }
        (void) strcpy(str, inStr);
        // Looking for the .
        dotPtr = strchr(str, '.');
        // Seperate the folating number into two parts by '\0'
        *dotPtr = '\0';
        
        /* Print out the pre-dot portion */
        preDotNum = strToLong(str, DEF_BASE);
        printEnglish(abs(preDotNum));
        
        // Print out the dot
        (void) printf(STR_DOT);
        
        /* Print out the leading zeros after the dot if necessary */
        while (*(++dotPtr) == '0') {
            (void) printf(STR_ZERO);
        }
        /* Print out the post-dot portion */
        postDotNum = strToLong(dotPtr, DEF_BASE);
        if (postDotNum) {
            printEnglish(postDotNum);
        }
        
        (void) printf(STR_NEWLINE);
        
        // Deallocate the space of str
        free(str);
    }
    
    /* Print out the number in IEEE standard floating format*/
    if (info.mode & B_FLAG) {
        printFPBinary(fpToken);
        (void) printf(STR_NEWLINE);
    }
    
    
}
