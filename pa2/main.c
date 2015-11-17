/*
 * Filename: main.c
 * Author: Yuchun Li
 * Userid: cse30xlq
 * Description: main C file for pa1
 * Date: Nov. 2, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

/* Standard C Library headers */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

/* Local headers */
#include "pa2.h"
#include "strings.h"

/*
 * Function name: main()
 * Function protorype:  int main( int argc, char *argv[] );
 *				or
 * 			int main( void): if no command line processing.
 * Description: Display the lightBank in file mode and interactive mode
 * Error Conditions: None.
 * Return Value: 0 indicating successful execution.
 */

int ptrError = EINVAL;

int
main (int argc, char *argv[]){
    
    FILE *fp;
    char buf1[BUFSIZ] = {0};    // buffer for user's input
    char buf2[BUFSIZ] = {0};    // buffer for the error message
    // Token for command, argument 1 and argument 2
    const char *cmdTok, *argOneTok, *argTwoTok;
    // Stores all the expected commands
    const char *commands[] = {COMMANDS, NULL};
    unsigned int lightBank[2] = {0, 0};
    // the index of the commands;
    int cmdNum, prompt;
    // post-conversion argument 1 and argument 2
    long arg1, arg2;
    
    // Turn off buffering in stdout
    (void) setvbuf(stdout, NULL, _IONBF, 0);
    
    --argc;     // Don't count the firt argument
    
    if (argc == 0 || argc == 1) {
        
        // argc == 1 - file mode
        if (argc == 1) {
            prompt = FALSE;     // Turn off the prompt
            fp = fopen(argv[1], "r");   // Read file mode
            // Read file error
            if (fp == NULL) {
                perror(argv[1]);
                exit(0);
            }
        }else{
            // argc == 0 - interactive mode
            prompt = TRUE;  // Turn on the prompt
            fp = stdin;
        }
        
        // Display the the initial lightBank
        set(lightBank, 0, 0);
        displayLights(lightBank);
    
        for (DISPLAY_PROMPT; fgets(buf1, BUFSIZ, fp); DISPLAY_PROMPT){
            
            // Get the cmd token
            cmdTok = strtok(buf1, TOKEN_SEPARATORS);
            
            // Check for null cmd token
            if (cmdTok != NULL) {
                cmdNum = checkCmd(cmdTok, commands);
            }else
                continue;
            
            // Check for unexptected commands
            if (cmdNum == -1) {
                fprintf(stderr, STR_BAD_CMD);
                continue;
            }else if (cmdNum == QUIT) {
                // Exit the program
                exit(0);
            }else if (cmdNum == HELP){
                // Print the usage message
                fprintf(stderr, STR_HELP_MSG);
                continue;
            }
            
            // Get the arg 1 token and arg 2 token
            argOneTok = strtok(NULL, TOKEN_SEPARATORS);
            argTwoTok = strtok(NULL, TOKEN_SEPARATORS);
            
            // Check for null arg 1 token
            if (argOneTok == NULL){
                fprintf (stderr, STR_ARGS_REQ);
                continue;
            }else{
                // Convert the arg 1 token to long type
                arg1 = strToULong(argOneTok, 0);
                // arg 1 token is not integer
                if (errno == ptrError ) {
                    fprintf(stderr, STR_STRTOLONG_NOTINT,argOneTok);
                    continue;
                }else if (errno != 0){  // arg 1 token is too long
                    snprintf(buf2, BUFSIZ , STR_STRTOLONG_CONVERTING,
                             argOneTok, 0);
                    perror(buf2);
                    continue;
                }
            }
            
            // Check for null arg 2 token
            if (argTwoTok == NULL){
                // arg 2 is required for set, clear and toggle
                if (cmdNum == SET || cmdNum == CLEAR || cmdNum == TOGGLE) {
                    fprintf (stderr, STR_TWO_ARGS_REQ);
                    continue;
                }
            }else{
                // Convert the arg 2 token to long type
                arg2 = strToULong(argTwoTok, 0);
                // arg 2 is not integer
                if (errno == ptrError ) {
                    fprintf(stderr, STR_STRTOLONG_NOTINT,argTwoTok);
                    continue;
                }else if (errno != 0){  // arg 2 token is too long
                    snprintf(buf2, BUFSIZ , STR_STRTOLONG_CONVERTING,
                             argTwoTok, 0);
                    perror(buf2);
                    continue;
                }
            }
            
            // Call specified routines based on the command index
            switch (cmdNum) {
                case SET:
                    set(lightBank, arg1, arg2);
                    displayLights(lightBank);
                    break;
                case CLEAR:
                    clear(lightBank, arg1, arg2);
                    displayLights(lightBank);
                    break;
                case TOGGLE:
                    toggle(lightBank, arg1, arg2);
                    displayLights(lightBank);
                    break;
                case SHIFT:
                    shift(lightBank, arg1);
                    displayLights(lightBank);
                    break;
                case ROTATE:
                    rotate(lightBank, arg1);
                    displayLights(lightBank);
                    break;
                case RIPPLE:
                    ripple(lightBank, arg1);
                    break;
                default:
                    fprintf(stderr, STR_BAD_CMD);
                    break;
            }
        }
    }else{  // print pa2 usage
        fprintf(stderr, STR_USAGE_MSG, argv[0]);
    }
    return 0;
}
