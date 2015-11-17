/*
 * Filename: main.c
 * Author: Yuchun Li
 * Userid: cse30xlq
 * Description: main C file for pa3
 * Date: Nov. 24, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

/* Standard C Library headers */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

/* Local headers */
#include "pa3.h"
#include "strings.h"

/*
 * Function name: main()
 * Function protorype:  int main( int argc, char *argv[] );
 * Description: Reads the input flags using setFlags, checking
 *              for errors, then reads the input strings from
 *              command line or file and processes each one.
 * Error Conditions: None.
 * Return Value: 0 indicating successful execution.
 */

int main(int argc, char* argv[]){
    FILE* fp;
    struct argsInfo info;
    char buf[BUF_MAX_SIZE] = {0};   // Buffer for reading file
    char* inStr;
    char* tmpStr;
    char* endptr;
    char* strTok;
    int numInputs = 0;
    int i;
    
    // Allocate heap memory for it
    char** inputStrings = malloc(sizeof(char*));
    
    // Check for successful memory allocation
    if (inputStrings == NULL) {
        (void) fprintf(stderr, STR_MALLOC_ERR);
        exit(1);
    }

    (void) setvbuf(stdout, NULL, _IONBF, 0);
    
    // Set the flags in info
    info = setFlags(argc, argv);
    
    /* Check for error flag and print out usage message*/
    if (info.mode & H_FLAG) {
        (void) fprintf(stderr, STR_USAGE_MSG, argv[0]);
        exit(1);
    }
    
    if (info.mode & F_FLAG) {   // File mode - reading numbers from file
        fp = fopen(optarg, "r");
        
        /* Check if file exists*/
        if (fp == NULL) {
            perror(optarg);
            exit(1);
        }
        
        /* Reading a line each iteration from file*/
        while (fgets(buf, BUF_MAX_SIZE, fp) != NULL) {
            
            /* Tokenize the string for every line*/
            for (tmpStr = buf; ; tmpStr = NULL) {
                strTok = (char*) strtok_r(tmpStr, STR_FILE_TOK_SEPARATOR,\
                                         &endptr);
                
                if (strTok != NULL) {
                    numInputs++;    // One more inputs
                } else if (numInputs == 0){
                    exit(0);    // No input strings in file
                } else{
                    break;  // Finish reading a line
                }
                
                // Allocate heap memory for a string token
                // plus 1 for terminating null character
                inStr = (char*) malloc(strlen(strTok)+1);
                
                // Check for successful memory allocation
                if (inStr == NULL) {
                    (void) fprintf(stderr, STR_MALLOC_ERR);
                    exit(1);
                }
                
                // Copy string from stack (strTok) to heap (inStr)
                (void) strcpy(inStr, strTok);
                
                // Reallocate memory for inputStrings since
                // there is one more input string
                inputStrings = realloc(inputStrings,\
                                       sizeof(char*) * numInputs);
                
                // Check for successful memory allocation
                if (inputStrings == NULL) {
                    (void) fprintf(stderr, STR_REALLOC_ERR);
                    exit(1);
                }
                
                inputStrings[numInputs-1] = inStr;
            }
            
        }
        (void) fclose(fp);
        
    } else {    // Command line mode - reading numbers from command line
        for(i = 0; argv[optind + i] != NULL; i++) {
            numInputs++;
            
            // Reallocate memory for inputStrings since
            // there is one more input string
            inputStrings = realloc(inputStrings,\
                                   sizeof(char*) * numInputs);
            
            // Check for successful memory allocation
            if (inputStrings == NULL) {
                (void) fprintf(stderr, STR_REALLOC_ERR);
                exit(1);
            }

            inputStrings[numInputs - 1] = argv[optind + i];
        }
    }
    
    /* No numbers specified */
    if (numInputs == 0) {
        (void) fprintf(stderr, STR_NO_INPUT_ERR);
        (void) fprintf(stderr, STR_USAGE_MSG, argv[0]);
        exit(1);
    }
    
    /* Prints out the number in given options*/
    for (i = 0; i < numInputs; i++) {
        (void) printf("\n%s\n", inputStrings[i]);
        
        /* For floating numbers*/
        if (strchr(inputStrings[i], '.') != NULL)
            processFPToken(inputStrings[i], info);
        /* For integer numbers*/
         else
            processIntToken(inputStrings[i], info);
        
        /* Deallocate memory for inputStrings[] */
        if (info.mode & F_FLAG)
            free(inputStrings[i]);
        
    }
    // Deallocate memory for inputStrings table
    free(inputStrings);
    
    return 0;

}

