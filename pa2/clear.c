/*
 * Filename: clear.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Description: clear the particular bit of light bank pattern
 * Date: Nov. 1, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

#include <stdlib.h>
#include <stdio.h>

/*
 * Function name: clear()
 * Function protorype:  
 *  void clear( unsigned int lightBank[], const unsigned int bank0,
 *              const unsigned int bank1)
 * Description: clear the lightbank with given patterns.
 * Error Conditions: None.
 * Return Value: None.
 */

void
clear( unsigned int lightBank[], const unsigned int bank0,
       const unsigned int bank1)
{

    lightBank[0] = lightBank[0] & ~bank0;
    lightBank[1] = lightBank[1] & ~bank1;
}
