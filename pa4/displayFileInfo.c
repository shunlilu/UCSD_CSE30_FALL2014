/*
 * Filename: displayFileInfo.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Dec. 9, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mkdev.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#include "myls.h"
#include "strings.h"

/*
 * Function name: displayFileInfo()
 * Function protorype:
 *      void displayFileInfo( struct fileInfo * const table, 
                              const int entries,
                              const unsigned int displayMode );
 * Description: display the file info accoring to the displaymode
 * Error Conditions: None.
 * Return Value: None
 */

void displayFileInfo( struct fileInfo * const table, const int entries,
                     const unsigned int displayMode ) {
    char * modTime;
    char * timeTok;
    char * strStart;
    char * strEnd;
    char * linkname = (char*) malloc(MAXNAMLEN*sizeof(char));
    time_t timer;
    int i, j;
    int count;
    
    if (displayMode & SFLAG) {  // Sort by size
        if (displayMode & RFLAG)
            // Reverse - ascending size
            qsort(table, entries, sizeof(struct fileInfo),\
                  sizeSortAscending);
        else
            // Default - descending size
            qsort(table, entries, sizeof(struct fileInfo),\
                  sizeSortDescending);

    } else {    // Default - sort by name
        if (displayMode & RFLAG)
            // Reverse - Desending name
            qsort(table, entries, sizeof(struct fileInfo),\
                  nameSortDescending);
        else
            // default - Ascending name
            qsort(table, entries, sizeof(struct fileInfo),\
                  nameSortAscending);
    }
    
    if (displayMode & LFLAG) {  // Long format
        for (i = 0; i < entries; i++) {
            
            /* Check if display hidden files or not */
            if (!(displayMode & AFLAG)) {
                if (table[i].name[0] == '.') {
                    continue;
                }
            }
            
            /* Check if display backup files or not */
            if (displayMode & BFLAG) {
                if (strrchr(table[i].name, '~') != NULL) {
                    continue;
                }
            }
            // Display permissions
            displayPermissions(table[i].stbuf.st_mode);
            
            // Print number of link
            (void) printf(STR_NLINK, table[i].stbuf.st_nlink);
            
            // Print owner of the file
            displayOwnerName(table[i].stbuf.st_uid);
            
            // Print the group of file
            displayGroupName(table[i].stbuf.st_gid);
            
            
            if (S_ISBLK(table[i].stbuf.st_mode) ||\
                S_ISCHR(table[i].stbuf.st_mode)) {
                // Print major and minor number for block and character device
                (void) printf(STR_MAJOR_MINOR,\
                              major(table[i].stbuf.st_rdev),\
                              minor(table[i].stbuf.st_rdev));
            } else {    // Print the size for other types of files
                (void) printf(STR_SIZE, table[i].stbuf.st_size);
            }
            // Calculate the current time
            timer = time(NULL);
            
            // Get the last modified time
            modTime = ctime(&table[i].stbuf.st_mtime);
            
            if (table[i].stbuf.st_mtime < timer - 15724800) {
                // Last modified time is longer than 6 months
                strEnd = strrchr(modTime, '\n');
                *strEnd = '\0';
                // Tokenize the modTime to get month, day, and year
                timeTok = strtok(modTime, " ");
                for (j = 0; timeTok != NULL; j++) {
                    if (j == 1) {   // Print month
                        (void) printf("%s ", timeTok);
                    }
                    if (j == 2) {   // Print day
                        (void) printf("%2s ", timeTok);
                    }
                    if (j == 4) {   // Print year
                        (void) printf(" %s ", timeTok);
                    }
                    timeTok = strtok(NULL, " ");
                }
            } else {
                // Print Mmm dd hh:mm
                strStart = strchr(modTime, ' ') + 1;
                strEnd = strrchr(modTime, ':');
                *strEnd = '\0';
                (void) printf("%s ", strStart);
            }
            
            // Print the name of the file
            (void) printf("%s", table[i].name);
            
            /* -F option enable */
            if (displayMode & FFLAG){
                
                /* Print / after the directory */
                if (S_ISDIR(table[i].stbuf.st_mode)){
                    (void) printf("/");
                }
                
                /* Print link target after the link file */
                if (S_ISLNK(table[i].stbuf.st_mode)){
                    count = readlink(table[i].name, linkname, MAXNAMLEN);
                    if (count != -1){
                        linkname[count] = '\0';
                        (void) printf(" -> %s", linkname);
                    }
                }
                
                /* Print * after executable files*/
                if (S_ISREG(table[i].stbuf.st_mode)){
                    if (strchr(table[i].name, '.') == NULL){
                        (void) printf("*");
                    }
                }
            }
                
            (void) printf("\n");
            
            /* Recursively list subdirectories encountered */
            if ((displayMode & BRFLAG) && S_ISDIR(table[i].stbuf.st_mode)) {
                int entries;
                // Create a new table pointer for encountered subdirectories
                struct fileInfo ** table_ptr =\
                (struct fileInfo**) malloc(sizeof(struct fileInfo**));
                
                (void) printf("\n");
                
                if (table_ptr == NULL) {
                    perror(STR_ALLOC_ERR);
                    exit(1);
                }
                
                // Create a new table for encountered subdirectories
                *table_ptr = (struct fileInfo*) malloc(sizeof(struct fileInfo*));
                
                if (*table_ptr == NULL) {
                    perror(STR_ALLOC_ERR);
                    exit(1);
                }
                
                entries = buildFileInfoTable(table[i].name, table_ptr);
                displayFileInfo(*table_ptr, entries, displayMode);
                (void) printf("\n");
                free(*table_ptr);
                free(table_ptr);
            }
        }
    } else {    // Display filename only
        for (i = 0; i < entries; i++) {
            
            /* Check if display hidden files or not */
            if (!(displayMode & AFLAG)) {
                if (table[i].name[0] == '.') {
                    continue;
                }
            }
            
            /* Check if display backup files or not */
            if (displayMode & BFLAG) {
                if (strrchr(table[i].name, '~') != NULL) {
                    continue;
                }
            }
            
            // Print the filenames
            (void) printf("%s", table[i].name);
            
            /* -F options enabled */
            if (displayMode & FFLAG) {
                if (S_ISDIR(table[i].stbuf.st_mode)){
                    (void) printf("/");
                }
                    
                if (S_ISLNK(table[i].stbuf.st_mode)){
                    (void) printf("@");
                }
                    
                if (S_ISREG(table[i].stbuf.st_mode)){
                    if (strchr(table[i].name, '.') == NULL ){
                        (void) printf("*");
                    }
                }
    
            }
            (void) printf("\n");
            
            /* Recursively list subdirectories encountered */
            if ((displayMode & BRFLAG) && S_ISDIR(table[i].stbuf.st_mode)) {
                int entries;
                struct fileInfo ** table_ptr =\
                (struct fileInfo**) malloc(sizeof(struct fileInfo**));
                
                (void) printf("\n");
                
                if (table_ptr == NULL) {
                    perror(STR_ALLOC_ERR);
                    exit(1);
                }
                
                *table_ptr = (struct fileInfo*) malloc(sizeof(struct fileInfo*));
                
                if (*table_ptr == NULL) {
                    perror(STR_ALLOC_ERR);
                    exit(1);
                }
                
                entries = buildFileInfoTable(table[i].name, table_ptr);
                displayFileInfo(*table_ptr, entries, displayMode);
                (void) printf("\n");
                free(*table_ptr);
                free(table_ptr);
            }

        }
    }
}
