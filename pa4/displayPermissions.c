/*
 * Filename: displayPermissions.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Dec. 5, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */
#include <stdlib.h>
#include <stdio.h>

#include "myls.h"

/*
 * Function name: displayPermissions()
 * Function protorype:
 *      void displayPermissions( const mode_t mode );
 * Description: display the permissions of file or directory.
 * Error Conditions: None.
 * Return Value: None
 *
 */
static void printOneChunk (int oneChunkMode);

void displayPermissions( const mode_t mode ){
    
    /* Print for directroy */
    if (S_ISDIR(mode))
        (void) printf("d");
    else if (S_ISLNK(mode))
        (void) printf("l");
    else if (S_ISBLK(mode))
        (void) printf("b");
    else if (S_ISCHR(mode))
        (void) printf("c");
    else if (S_ISREG(mode))
        (void) printf("-");
    
    /* Print user's permissions */
    if (mode & S_IRWXU)
        printOneChunk(mode & S_IRWXU);
    else
        (void) printf("---");
    
    /* Print group's permissions */
    if (mode & S_IRWXG)
        printOneChunk(mode & S_IRWXG);
    else
        (void) printf("---");
    
    /* Print other's permissions */
    if (mode & S_IRWXO)
        printOneChunk(mode & S_IRWXO);
    else
        (void) printf("---");
}

/*
 * Function name: printOneChunk()
 * Function protorype:
 *      void printOneChunk (int oneChunkMode);
 * Description: print one chunk of permissions
 * Error Conditions: None.
 * Return Value: None
 *
 */

static void printOneChunk (int oneChunkMode){
    
    /* Print a read permission*/
    if (oneChunkMode & S_IRUSR || oneChunkMode & S_IRGRP \
        || oneChunkMode & S_IROTH) {
        (void) printf("r");
    } else
        (void) printf("-");
    
    /* Print a write permission */
    if (oneChunkMode & S_IWUSR || oneChunkMode & S_IWGRP \
        || oneChunkMode & S_IWOTH) {
        (void) printf("w");
    } else
        (void) printf("-");
    
    /* Print a execute permission */
    if (oneChunkMode & S_IXUSR || oneChunkMode & S_IXGRP \
        || oneChunkMode & S_IXOTH) {
        (void) printf("x");
    } else {
        (void) printf("-");
    }
}
