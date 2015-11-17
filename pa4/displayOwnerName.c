/*
 * Filename: displayOwnerName.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Dec. 5, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

#include "myls.h"
#include "strings.h"

/*
 * Function name: displayOwnerName()
 * Function protorype:
 *      void displayOwnerName( const uid_t uid );
 * Description: display the owner name of file or directory.
 * Error Conditions: None.
 * Return Value: None
 *
 */

void displayOwnerName( const uid_t uid){
    struct passwd *pwd;
    pwd = getpwuid(uid);
    if (pwd != NULL)
        (void) printf(STR_PWNAME, pwd->pw_name);
    else
        (void) printf(STR_UID, uid);
}
