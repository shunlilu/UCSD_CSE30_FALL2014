/*
 * Filename: checkCmd.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: Check for the input command and return
 *              the corresponding integer number.
 * Date: Oct. 25, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pa2.h"
#include "strings.h"

/*
 * Function name: checkCmd()
 * Function protorype:
 * int checkCmd( const char * const cmdString, const char * const commands[])
 * Description: check the command in string and return the corresponding index
 * Error Conditions: None.
 * Return Value:  0 - set
 *                1 - clear
 *                2 - toggle
 *                3 - shift
 *                4 - rotate
 *                5 - ripple
 *                6 - help
 *                7 - quit
 *               -1 - indicating unsuccessful execution.
 */

int
checkCmd( const char * const cmdString, const char * const commands[]){
    int i =0;
    while (commands[i] != NULL) {
        // Check if the string matches the commands
        if (strcmp(cmdString, commands[i]) == 0 ) {
            return i;   // Returns the index
        }
        else{
            i++;
        }
    }
    return -1;
}
