/*
 * Class that contains a dynamic string
 * These are the functions that modify it
 */
#ifndef _STR_H_
#define _STR_H_

#include <dyllib.h>

string *newString(void);
void deleteString(string *);
void appendString(string *, char *);
void insertString(string *, int index, char *);
void removeString(string *, int, int);
string *substring(string *, int, int);

#endif