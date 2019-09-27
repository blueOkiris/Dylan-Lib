/*
 * List of functions for modifying a string to (void *) dictionary
 */
#ifndef _DICT_H_
#define _DICT_H_

#include <dyllib.h>

dict *newDict(void);
dict *addToDict(dict *, const char *, void *);
void *getFromDict(dict *, const char *);
void deleteDict(dict *);
dict *removeFromDict(dict *, const char *);

#endif