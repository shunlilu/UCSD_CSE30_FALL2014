/*
 * Filename: pa0.h
 * Author: Yuchun Li
 * Userid: Not be assigned yet
 * Description: Function prototypes and define for PA0
 * Date: Oct. 10, 2014
 * Source of Help: CSE30 Fall 2014 Lecture Handout
*/

#ifndef PA0_H
#define PA0_H

#define EXPECTED_ARGS 1

/* User_define types used in PA0 */

struct DueDate {
   const char *month;
   unsigned int day;
   unsigned int year;
};

/* Function prototypes for the C and assembly routines used in PA0 */

void printDueDate( const struct DueDate *dueDate);
void printWelcome( const char *string);

int squareNum( int num );

#endif /* PA0_H */
