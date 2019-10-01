/*
 * Structure and function definitions for a linked list
 * Uses "void *" for data to be generic.
 * This means the data placed in must ALWAYS be a reference
 */
#ifndef _LIST_H_
#define _LIST_H_

#include <dyllib.h>

list *newList(void);
list *appendList(list *, void *);
void deleteList(list *);
void *accessList(list *, int);
list *insertInList(list *, int, void *);
list *removeFromList(list *, int);
void debugPrintList(list *);
list *changeList(list *, int, void *);

#endif