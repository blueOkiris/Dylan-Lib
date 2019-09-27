/*
 * Implementation of string manipulation functions
 */
#include <stdlib.h>

#include <str.h>
#include <dyllib.h>

string *newString(void) {
    string *new_str = (string *) malloc(sizeof(string));

    new_str->len = 0;
    new_str->val = (char *) malloc(sizeof(char));
    new_str->val[0] = '\0';

    return new_str;
}

void deleteString(string *str) {
    free(str->val);
    free(str);
}