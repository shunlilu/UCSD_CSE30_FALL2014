/*
 * Filename: strings.h
 * Author: Yuchun Li
 * Userid: Not be assigned yet
 * Description: Strings used in PA0 output
 * Date: Oct. 10, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

#ifndef STRINGS_H
#define STRINGS_H

/*
 * Normal output messages
 */
#define STR_WELCOME_QUARTER   "Fall 2014"
#define STR_DUEDATE   "PA0 is due on %s %d, %d\n"
#define STR_SQUARENUM  "The square of %d is %d\n"

/*
 * Error message
 */
#define STR_ERR_USAGE		"Usage: %s [INTEGER]\n  Interger value to square\n"
#define STR_ERR_MISSING_ARG	"%s: missing interger arg\n"
#define STR_ERR_EXTRA_ARG	"%s: too many arguments\n"

#endif /* STRINGS_H */

