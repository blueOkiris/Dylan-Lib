// Literally just for an instantiation of the "dylanlib" struct
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

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

// Puts a copy of a char * onto the heap
void *heapCharArr(char *data) {
    int len = strlen(data);
    char *copy = (char *) malloc(sizeof(char) * (len + 1));
    memcpy(copy, data, len);
    copy[len] = '\0';

    return copy;
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

list *fscanlines(char *filename) {
    list *line_arr = newList();
    string *full_text = fscantext(filename);

    string *current_sub;
    int start_sub = 0;
    for(int i = 0; i < full_text->len; i++) {
        if(full_text->val[i] == '\n') {
            current_sub = substring(full_text, start_sub, i - start_sub);
            appendList(line_arr, heapCharArr(current_sub->val));

            start_sub = i + 1;
        }
    }

    current_sub = substring(full_text, start_sub, full_text->len - start_sub);
    appendList(line_arr, heapCharArr(current_sub->val));

    return line_arr;
}

void fprinttext(char *filename, string *text) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "%s", text->val);
    fclose(file);
}

void fappendtext(char *filename, string *text) {
    FILE *file = fopen(filename, "a");
    fprintf(file, "%s", text->val);
    fclose(file);
}

void fprintlines(char *filename, list *lines) {
    FILE *file = fopen(filename, "w");
    for(int i = 0; i < lines->length; i++)
        fprintf(file, "%s\n", (char *) accessList(lines, i));
    fclose(file);
}

void fappendlines(char *filename, list *lines) {
    FILE *file = fopen(filename, "a");
    for(int i = 0; i < lines->length; i++)
        fprintf(file, "%s\n", (char *) accessList(lines, i));
    fclose(file);
}

dylanlib dlib = { 
    &heapInt, &heapCharArr,
    &newList, &appendList, &deleteList, &accessList, &insertInList, &removeFromList, &debugPrintList, &changeList,
    &newString, &deleteString, &appendString, &insertString, &removeString, &substring,
    &newDict, &addToDict, &getFromDict, &deleteDict, &removeFromDict, &setDict,
    &fsize, &fscantext, &fscanlines, &fprinttext, &fprintlines, &fappendtext, &fappendlines
};
