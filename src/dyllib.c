// Literally just for an instantiation of the "dylanlib" struct
#include <stdlib.h>
#include <stdint.h>

#include <list.h>
#include <str.h>
#include <dyllib.h>

// Create an integer on the heap so it gets free from a linked list later
void *heapInt(uint64_t data) {
    uint64_t *newInt = (uint64_t *) malloc(sizeof(uint64_t));
    *newInt = data;

    return newInt;
}

dylanlib dlib = { 
    &newList, &appendList, &deleteList, &accessList, &insertInList, &removeFromList, &heapInt, &debugPrintList,
    &newString, &deleteString
};
