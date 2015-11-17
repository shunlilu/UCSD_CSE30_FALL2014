/*
 * Filename: sizeSOrtDescending.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Dec. 5, 2014
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

#include "myls.h"

/*
 * Function name: sizeSOrtDescending()
 * Function protorype:
 *      int nameSortDescending( const void *p1, const void *p2 );
 * Description: Sort the size of the two items in ascending order
 * Error Conditions: None.
 * Return Value:-1 - item 1 > item 2
 *               0 - item 1 = item 2
 *               1 - item 1 < item 2
 *
 */

int sizeSortDescending( const void *p1, const void *p2 ){
    if (((struct fileInfo*)p1)->stbuf.st_size == ((struct fileInfo *)p2)->stbuf.st_size)
        return 0;
    else if (((struct fileInfo *)p1)->stbuf.st_size > ((struct fileInfo *)p2)->stbuf.st_size)
        return -1;
    else
        return 1;
}
