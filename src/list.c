/*
 * Functions for setup and manipulation of the linked list
 */
#include <stdlib.h>

#include <list.h>

// Create a new list (on the stack)
list newList(void) {
    return (list) { (struct LINKED_LIST_CELL) { NULL, -1, NULL, NULL} };
}