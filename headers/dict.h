/*
 * List of functions for modifying a string to (void *) dictionary
 */
#ifndef _DICT_H_
#define _DICT_H_

#include <dyllib.h>

dict *newDict(void);
dict *addToDict(dict *, const char *, void *);
void deleteDict(dict *);

#endif