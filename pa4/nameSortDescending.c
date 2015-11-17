/*
 * Filename: nameSortDescending.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Dec. 5, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

#include "myls.h"

/*
 * Function name: nameSortDescending()
 * Function protorype:
 *      int nameSortDescending( const void *p1, const void *p2 );
 * Description: Sort the name of the two items in ascending order
 * Error Conditions: None.
 * Return Value:-1 - item 1 > item 2
 *               0 - item 1 = item 2
 *               1 - item 1 < item 2
 *
 */

int nameSortDescending( const void *p1, const void *p2 ){
    
    int i = 0;
    
    for (i = 0; i <= MAXNAMLEN; i++) {
        // Check if both string end
        if (((struct fileInfo *)p1)->name[i] == '\0' &&\
            ((struct fileInfo *)p2)->name[i] == '\0')
            return 0;
        
        if (((struct fileInfo *)p1)->name[i] == ((struct fileInfo *)p2)->name[i])
            continue;
        else if (((struct fileInfo *)p1)->name[i] > ((struct fileInfo *)p2)->name[i])
            return -1;
        else
            return 1;
    }
    
    return 0;
}
