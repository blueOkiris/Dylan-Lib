/*
 * The main hub where all the libraries meet
 * In here there is a global instance that gets created whenever the library is used.
 * It contains function references to all the other libraries
 */
#ifndef _DYLLIB_H_
#define _DYLLIB_H_

#include <stdint.h>

// The individual nodes of our linked list.
typedef struct LINKED_LIST_CELL {
    void *value;

    int index;

    struct LINKED_LIST_CELL *previous;
    struct LINKED_LIST_CELL *next;
} list_cell;

typedef struct LINKED_LIST {
    list_cell *head;
    list_cell *tail;

    int length;
} list;

typedef struct STRING {
    int len;
    char *val;
} string;

typedef struct DICTIONARY {
    list *keys;
    list *values;

    int length;
} dict;

typedef struct DYLAN_LIB {
    // Move regular data types to heap
    void *(*heapInt) (uint64_t data);

    // Linked list functions
    list *(*newList) (void);
    list *(*appendList) (list *lst, void *data);
    void (*deleteList) (list *lst);
    void *(*accessList) (list *lst, int index);
    list *(*insertInList) (list *lst, int index, void *data);
    list *(*removeFromList) (list *lst, int index);
    void (*debugPrintList) (list *lst);
    list *(*changeList) (list *lst, int index, void *new_data);

    // String functions
    string *(*newString) (void);
    void (*deleteString) (string *str);
    string *(*appendString) (string *str, char *value);
    string *(*insertString) (string *str, int, char *value);
    string *(*removeString) (string *str, int start, int len);
    string *(*substring) (string *str, int start, int len);

    // Dictionary functions
    dict *(*newDict) (void);
    dict *(*addToDict) (dict *dct, const char *key, void *value);
    void *(*getFromDict) (dict *dct, const char *key);
    void (*deleteDict) (dict *dct);
    dict *(*removeFromDict) (dict *dct, const char *key);
    dict *(*setDict) (dict *dct, const char *key, void *new_data);
} dylanlib;

extern dylanlib dlib; 

#endif