/*
 * Filename: strToLong.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: Convert the string to the integer.
 * Date: Oct. 10, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "pa1.h"
#include "strings.h"

long
strToLong( char *str, int base ){
    
    char *endptr;
    long num;
    char buf[BUF_MAX_SIZE]; /* BUF_MAX_SIZE = 50 */
    
    errno = 0;
    num = strtol( str, &endptr, base);
    
    /* Check for strtol conversion errors */
    if (errno != 0){
        snprintf( buf, BUF_MAX_SIZE , STR_STRTOLONG_CONVERTING, str, base);
        perror(buf);
    }
    
    /* Check for non-integer error */
    if (*endptr != 0){
        fprintf( stderr, STR_STRTOLONG_NOTINT, str);
        errno = -1;
    }
    
    return num;
}
