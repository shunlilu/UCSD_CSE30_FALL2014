/*
 * Filename: setFlags.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Nov. 16, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "pa3.h"
#include "strings.h"

/*
 * Function name: setFlags()
 * Function protorype:
 *      struct argsInfo setFlags( int argc, char* argv[] );
 * Description: Reads command line arguments and populates/returns a struct
 *              argsInfo that will be used to determine behavior in other 
*               functions.
 * Error Conditions: None.
 * Return Value: struct argsInfo.
 */



struct argsInfo setFlags( int argc, char* argv[] ){
    int option;
    long inputBase;
    long outputBase;
    char *savedptr;
    char *outputToken, *str1;
    struct argsInfo argsInfo;
    
    ptrError = EINVAL;
    
    /* Initialize the flags */
    argsInfo.mode = 0;
    argsInfo.inputBase = DEF_BASE;
    argsInfo.outputBases = 0;
    argsInfo.inFileStr = NULL;
    
    /* Check for sufficient arguments */
    if (argc <= 1){
        argsInfo.mode |= H_FLAG;
        (void) fprintf(stderr, STR_NO_INPUT_ERR);
        return argsInfo;
    }
    
    /*
     * Reads command line arguments, set the corresponding flags
     * and stores the desired value
     */
    while((option = getopt(argc, argv, STR_GETOPT_OPTIONS)) != -1){
        switch (option){
                
        /* Set print english flag */
        case 'e':
            argsInfo.mode |= E_FLAG;
            break;
                
        /* Set print binary flag */
        case 'b':
            argsInfo.mode |= B_FLAG;
            break;
                
        /* Set help flag */
        case 'h':
            argsInfo.mode = H_FLAG;
            break;
                
        /* Set input flag and store input base */
        case 'i':
            // Convert the input base to integer
            inputBase = strToLong(optarg, DEF_BASE);
            
            if (errno == 0){    // No conversion error
                
                /* Check for valid range */
                if (!checkRange(inputBase, MIN_BASE, MAX_BASE)){
                    argsInfo.mode |= H_FLAG;
                    (void) fprintf(stderr, STR_INBASE_BAD_RANGE, inputBase,\
                            MIN_BASE, MAX_BASE);
                    break;
                }
                
                argsInfo.mode |= I_FLAG;    // Set the input flag
                argsInfo.inputBase = inputBase; // Store input base
                break;
            } else if (errno == ptrError){    // endptr error
                (void) fprintf(stderr, STR_INBASE_ENDPTR_ERR, optarg);
                argsInfo.mode = H_FLAG;
                break;
            }else { // Conversion error
                perror(optarg);
                argsInfo.mode = H_FLAG;
                break;
            }
                
        /* Set the output flag and store the output bases */
        case 'o':
            // Reset the output bases from default base
            argsInfo.outputBases = 0;
                
            /* Loop to get all the tokens */
            for( str1 = optarg; ; str1 = NULL) {
                // Get a token every iteration
                outputToken = (char*) strtok_r(str1,\
                                               STR_OUTBASE_TOK_SEPARATOR,\
                                               &savedptr);
                /* Check if not last token */
                if (outputToken != NULL){
                    outputBase = strToLong(outputToken, DEF_BASE);
                } else{
                    break;
                }
                
                
                if (errno == 0){    // No conversion errors
                    /* Check for valid range */
                    if (!checkRange(outputBase, MIN_BASE, MAX_BASE)){
                        argsInfo.mode = H_FLAG;
                        (void) fprintf(stderr, STR_OUTBASE_BAD_RANGE, outputBase,\
                                MIN_BASE, MAX_BASE);
                        break;
                    }
                    // Store the output bases into a 64-bit value.
                    // Every single bit indicates an output base
                    argsInfo.outputBases |= BASE_MASK(outputBase);
                    // Set the output bases flag
                    argsInfo.mode |=  O_FLAG;
                } else if (errno == ptrError){ // endptr error
                    (void) fprintf(stderr, STR_OUTBASE_ENDPTR_ERR, outputToken);
                    argsInfo.mode = H_FLAG;
                    break;
                } else{ // Conversion errors
                    perror(outputToken);
                    argsInfo.mode = H_FLAG;
                    break;
                }
            }
            break;
                
        /* Set the file flag and store the file path string*/
        case 'f':
                
            /* Check if there are file and numbers at the same time */
            if (argv[optind] != NULL){
                (void) fprintf(stderr, STR_FILE_AND_ARGS_ERR);
                argsInfo.mode =  H_FLAG;
                break;
            }
            // Set the file flag
            argsInfo.mode |=  F_FLAG;
            // Store the file path stringß
            argsInfo.inFileStr = optarg;
            break;
                
        default:
            argsInfo.mode = H_FLAG;
            break;
        }
    }
    return argsInfo;
}
