/*
 * Filename: processIntToken.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Nov. 23, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "pa3.h"
#include "strings.h"

/*
 * Function name: processIntToken()
 * Function protorype:
 *      void processIntToken( char* inStr, struct argsInfo info );
 * Description: process one integer token and prints it out in
 *              correct format(s)
 * Error Conditions: None.
 * Return None.
 */

void processIntToken( char* inStr, struct argsInfo info ){
    long intToken;
    int i;
    
    ptrError = EINVAL;
    
    // Convert string to long
    intToken = strToLong(inStr, info.inputBase);
    
    /* Check for non-integer errors */
    if (errno == ptrError) {
        (void) fprintf(stderr, STR_INT_ENDPTR_ERR, inStr,\
                       info.inputBase);
        return;
    }
    
    /* Check for conversion errors */
    if (errno) {
        perror(inStr);
        return;
    }
    
    /* Print English mode */
    if (info.mode & E_FLAG) {
        
        /* Check for negative numbers */
        if (intToken < 0) {
            (void) printf(STR_MINUS);   // Print out minus sign
        }
        printEnglish(abs(intToken));
        (void) printf(STR_NEWLINE);
    }
    
    /* Print out the numbers in the given bases*/
    for (i = MIN_BASE; i <= MAX_BASE; i++) {
        
        // Get the actual base value based on the given flags
        int realBase = getRealBase(BASE_MASK(i) & info.outputBases);
        
        switch (realBase) {
            case 0:
                break;
                
            /* Print in binary representation*/
            case 2:
                printIntBinary(intToken);
                break;
            
            /* Print out prefix 0 and number in base 8 */
            case 8:
                
                /* Print out negative sign if negative number */
                if (intToken < 0) {
                    (void) printf(STR_NEG_PREFIX);
                }
                (void) printf(STR_OCT_PREFIX);
                printBase(abs(intToken), realBase);
                (void) printf(STR_NEWLINE);
                break;
            
            /* Print out prefix 0x and number in base 16 */
            case 16:
                
                /* Print out negative sign if negative number */
                if (intToken < 0) {
                    (void) printf(STR_NEG_PREFIX);
                }
                (void) printf(STR_HEX_PREFIX);
                printBase(abs(intToken), realBase);
                (void) printf(STR_NEWLINE);
                break;
            
            /* Print out number in given bases without prefixes */
            default:
                if (intToken < 0) {
                    (void) printf(STR_NEG_PREFIX);
                }
                printBase(abs(intToken), realBase);
                (void) printf(STR_NEWLINE);
                break;
        }
    }
}

/*
 * Function name: getRealBase()
 * Function protorype:
 *      int getRealBase( long long outputBase);
 * Description: get the real base value based on the given 
 *              bit-format value
 * Error Conditions: None.
 * Return: 0  - no base specified
 *         realBase - the real base 
 */

int getRealBase( long long outputBase){
    // Set the mask into the minimum base
    long long mask = BASE_MASK(MIN_BASE);
    int realBase;
    
    /* Current base is not specified */
    if (outputBase == 0) {
        return 0;
    }
    
    /* Loop through every bit in outputBase to get the actual base */
    for (realBase = MIN_BASE ; realBase <= MAX_BASE; realBase++) {
        if (outputBase == mask) {
            return realBase;
        } else{
            mask = mask << 1;
        }
    }
    return 0;
}
