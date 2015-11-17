/*
 * Filename: main.c
 * Author: Yuchun Li
 * Userid: cse30xlq
 * Description: main C file for pa1
 * Date: Oct. 10, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

/* Standard C Library headers */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/* Local headers */
#include "pa1.h"
#include "strings.h"

/*
 * Function name: main()
 * Function protorype:  int main( int argc, char *argv[] );
 *				or
 * 			int main( void): if no command line processing.
 * Description: Display the dersird X pattern
 * Error Conditions: None.
 * Return Value: 0 indicating successful execution.
 */

int
main( int argc, char *argv[]){
    long size;
    long xChar;
    long fillerChar;
    long borderChar;
    int  err_flag = 0;
    
    --argc;             /* Don't count the first argument */
    
    /* Check if arguments are enough */
    if (argc < 4){
        fprintf(stderr, STR_USAGE, argv[0],
               X_SIZE_MIN, X_SIZE_MAX,
               ASCII_MIN, ASCII_MAX,
               ASCII_MIN, ASCII_MAX,
               ASCII_MIN, ASCII_MAX);
        exit(1);
    }
    
    size = strToLong( argv[1], BASE);
    
    /* Check Validility for size */
    if (errno == 0) {
        
        /* Check the range of size */
        if (checkRange(size, X_SIZE_MIN, X_SIZE_MAX) == 0){
            fprintf(stderr, STR_ERR_XSIZE_RANGE, size, X_SIZE_MIN, X_SIZE_MAX);
            err_flag = 1;
        }
        
        /* Check if size is even */
        if (isEven(size) == 0){
            fprintf(stderr, STR_ERR_XSIZE_EVEN, size);
            err_flag = 1;
        }
    }
    else
        err_flag = 1;
    
    
    
    xChar = strToLong( argv[2], BASE);
    
    /* Check validility for xChar */
    if (errno == 0) {
        
        /* Check the range of xChar */
        if (checkRange(xChar, ASCII_MIN, ASCII_MAX) == 0){
            fprintf(stderr, STR_ERR_XCHAR_RANGE, xChar, ASCII_MIN, ASCII_MAX);
            err_flag = 1;
        }
    }
    else
        err_flag = 1;
    
    
    
    fillerChar = strToLong( argv[3], BASE);
    
    /* Check validility for fillerChar */
    if (errno == 0) {
        
        /* Check the range of fillerChar */
        if (checkRange(fillerChar, ASCII_MIN, ASCII_MAX) == 0){
            fprintf(stderr, STR_ERR_FILLERCHAR_RANGE, fillerChar, ASCII_MIN, ASCII_MAX);
            err_flag = 1;
        }
        
        /* Check if the fillerChar is the same as xChar */
        if (fillerChar == xChar){
            fprintf(stderr, STR_ERR_XCHAR_FILLERCHAR_DIFF, xChar, fillerChar);
            err_flag = 1;
        }
    }
    else
        err_flag = 1;

    
    
    borderChar = strToLong( argv[4], BASE);
    
    /* Check validility for borderChar */
    if (errno == 0) {
        
        /* Check the range of borderChar */
        if (checkRange(borderChar, ASCII_MIN, ASCII_MAX) == 0){
            fprintf(stderr, STR_ERR_BORDERCHAR_RANGE, borderChar, ASCII_MIN, ASCII_MAX);
            err_flag = 1;
        }
        
        /* Check if the borderChar is the same as the xChar */
        if (borderChar == xChar){
            fprintf(stderr, STR_ERR_XCHAR_BORDERCHAR_DIFF, xChar, borderChar);
            err_flag = 1;
        }
    }
    else
        err_flag = 1;
    
    /* Handle if any errors occured above */
    if (err_flag != 1)
        displayX(size, xChar, fillerChar, borderChar);
    else
        exit(1);
            
    
    return EXIT_SUCCESS;
    
}
