/*
 * Filename: setDisplayMode.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Dec. 2, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "myls.h"
#include "strings.h"

/*
 * Function name: setDisplayMode()
 * Function protorype:
 *      unsigned int setDisplayMode(int argc, char* argv[]);
 * Description: Reads command line options and set the 
 *              appropriate flags
 * Error Conditions: None.
 * Return Value: none.
 */

unsigned int setDisplayMode(int argc, char* argv[]){
    int option;
    unsigned int displayMode = 0;
    
    while ((option = getopt(argc, argv, STR_GETOPT_OPTIONS)) != -1) {
        switch (option) {
            /* List all entries */
            case 'a':
                displayMode |= AFLAG;
                break;
            
            /* List in long format */
            case 'l':
                displayMode |= LFLAG;
                break;
            
            /* Reverse order */
            case 'r':
                displayMode |= RFLAG;
                break;
            
            /* Sort by file size */
            case 'S':
                displayMode |= SFLAG;
                break;
            
            /* Ignore backups */
            case 'B':
                displayMode |= BFLAG;
                break;
                
            case 'F':
                displayMode |= FFLAG;
                break;
                
            case 'R':
                displayMode |= BRFLAG;
                break;
                
            default:
                if (argc == 1) {
                    break;
                } else {
                    displayMode = ERR_FLAG;
                    break;
                }
                
        }
    }
    return displayMode;
}
