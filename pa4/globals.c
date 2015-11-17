/*
 * Filename: globals.c
 * Author: Yuchun Li
 * Userid: cs30xlq
 * Date: Dec. 4, 2014
 * Decription: All global variables of pa4 defined here
 * Sources of Help: CSE30 Fall 2014 Lecture Handout
 */

#include <stddef.h>
#include "myls.h"

int sizeOffset = (int)offsetof(struct stat, st_size);
int bufOffset = (int)offsetof(struct fileInfo, stbuf);
int maxNameLen = MAXNAMLEN;
