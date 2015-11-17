/*
 * Filename: myls.c
 * Author: Yuchun Li
 * Userid: cse30xlq
 * Description: main C file for pa4
 * Date: Dec. 10, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

/* Standard C Library headers */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/* Local headers */
#include "myls.h"
#include "strings.h"

/*
 * Function name: main()
 * Function protorype:  int main( int argc, char *argv[] );
 * Description: Reads the display options from the command
 *              line, and display the file info appropriately
 * Error Conditions: None.
 * Return Value: 0 indicating successful execution.
 */

int main( int argc, char *argv[] ){
    unsigned int displayMode;
    int entries;
    struct fileInfo ** table_ptr =\
                (struct fileInfo**) malloc(sizeof(struct fileInfo**));
    
    /* Check if allocation is successful*/
    if (table_ptr == NULL) {
        perror(STR_ALLOC_ERR);
        exit(1);
    }
    
    *table_ptr = (struct fileInfo*) malloc(sizeof(struct fileInfo*));
    
    /* Check if allocation is successful*/
    if (*table_ptr == NULL) {
        perror(STR_ALLOC_ERR);
        exit(1);
    }
    
    // Set display mode
    displayMode = setDisplayMode(argc, argv);
    
    /* Check for error flag of display mode*/
    if (displayMode & ERR_FLAG) {
        (void) fprintf(stderr, STR_USAGE, argv[0]);
        exit(1);
    }
    
    
    if (argv[optind] == NULL) { // No files specified in command line
        
        // Build the file info table and the number of entries
        entries = buildFileInfoTable(".", table_ptr);
        // Display the file info
        displayFileInfo(*table_ptr, entries, displayMode);
        free(*table_ptr);
    } else {    // files specified in command line
        while (argv[optind] != NULL) {  // Keeps reading multiple files
            entries = buildFileInfoTable(argv[optind++], table_ptr);
            displayFileInfo(*table_ptr, entries, displayMode);
            free(*table_ptr);
        }
    }
    free(table_ptr);
    return 0;
}
