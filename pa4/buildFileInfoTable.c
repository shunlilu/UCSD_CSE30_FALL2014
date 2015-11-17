/*
 * Filename: buildFileInfoTable.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Dec. 4, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#include "myls.h"
#include "strings.h"

/*
 * Function name: buildFileInfoTable()
 * Function protorype:
 *      int buildFileInfoTable( const char *filename,\
 *                              struct fileInfo ** const tablePtr );
 * Description: build a fileInfo table for a file or directory
 * Error Conditions: None.
 * Return Value: 0 - error - zero fileInfo entry
 *               int - # of fileInfo entries
 */

int
buildFileInfoTable( const char *filename, struct fileInfo ** const tablePtr ){
    int status;
    int filesCount = 0;
    char pathname[MAXNAMLEN];
    struct stat buf;
    struct dirent * direntPtr;
    DIR *dir;
    
    
    status = lstat(filename, &buf); // Get the information on filename
    
    /* Check if the filename is valid */
    if (status) {
        (void) printf("\n\t");
        (void) fprintf(stderr, STR_LSTAT_ERR);
        perror(filename);
        return 0;
    }
    
    if (!S_ISDIR(buf.st_mode)) {    // filename is a file
    
        // Allocate space for one struct fileInfo
        *tablePtr = malloc(sizeof(struct fileInfo));
        
        /* Check if allocation is successful */
        if (*tablePtr == NULL) {
            perror(STR_ALLOC_ERR);
            exit(1);
        }
        
        // Fill the memory with 0 before update the file name
        (void) memset((*tablePtr)->name, 0, MAXNAMLEN);
        
        /* Update the struct fileInfo */
        (void) strcpy((*tablePtr)->name, filename);
        (*tablePtr)->stbuf = buf;
        
        return 1;
    } else {    // filename is a directory
        
        (void) printf("%s:\n", filename);
        
        /* Check if the filename is valid */
        if ((dir = opendir(filename)) == NULL) {
            (void) fprintf(stderr, STR_OPENDIR_ERR);
            perror(filename);
            return 0;
        }
        
        // Keeps getting the files in the directory
        while ( (direntPtr = readdir(dir)) != NULL) {
            
            // One more file. Allocate space for one struct fileInfo
            *tablePtr = realloc(*tablePtr,\
                                  (filesCount+1) * sizeof(struct fileInfo));
            
            /* Check if allocation is successful */
            if (*tablePtr == NULL) {
                perror(STR_ALLOC_ERR);
                exit(1);
            }
            
            // Fill the memory with 0 before update the file name
            (void) memset((*tablePtr)[filesCount].name, 0, MAXNAMLEN);
            
            // Update the name of fileInfo
            (void) strcpy((*tablePtr)[filesCount].name, direntPtr->d_name);
            
            /* Create the full path name */
            (void) strcpy(pathname, filename);
            (void) strcat(pathname, "/");
            (void) strcat(pathname, direntPtr->d_name);
            
            // Get the information on pathname
            status = lstat(pathname, &buf);
            
            // Update the stbuf of fileInfo
            (*tablePtr)[filesCount].stbuf = buf;
            filesCount++;
        }
        return filesCount;  // Returns the number of entries of fileInfo
        
    }
}







