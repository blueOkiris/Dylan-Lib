// Literally just for an instantiation of the "dylanlib" struct
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <dict.h>
#include <list.h>
#include <str.h>
#include <dyllib.h>

// Create an integer on the heap so it gets free from a linked list later
void *heapInt(uint64_t data) {
    uint64_t *newInt = (uint64_t *) malloc(sizeof(uint64_t));
    *newInt = data;

    return newInt;
}

int fsize(char *filename) {
    FILE *file = fopen(filename, "r");
    fseek(file, 0, SEEK_END);
    
    int file_size = ftell(file);

    fclose(file);
    return file_size;
}

string *fscantext(char *filename) {
    int file_size = fsize(filename);
    FILE *file = fopen(filename, "r");
    string *file_text = newString();

    char character[2] = { 'A', '\0' };
    for(int i = 0; i < file_size; i++) {
        character[0] = fgetc(file);
        appendString(file_text, character);
    }
    fclose(file);

    return file_text;
}

dylanlib dlib = { 
    &heapInt,
    &newList, &appendList, &deleteList, &accessList, &insertInList, &removeFromList, &debugPrintList, &changeList,
    &newString, &deleteString, &appendString, &insertString, &removeString, &substring,
    &newDict, &addToDict, &getFromDict, &deleteDict, &removeFromDict, &setDict,
    &fsize, &fscantext
};
