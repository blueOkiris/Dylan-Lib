/*
 * Implementation of string manipulation functions
 */
#include <stdlib.h>
#include <string.h>

#include <str.h>
#include <dyllib.h>

string *newString(void) {
    string *new_str = (string *) malloc(sizeof(string));

    new_str->len = 0;
    new_str->val = (char *) malloc(sizeof(char));
    new_str->val[0] = '\0';

    return new_str;
}

void appendString(string *str, char *value) {
    int len = strlen(value);                            // Accessing passed in values into realloc creates mem leak. Store parameter as temp
    char *temp = malloc(sizeof(char) * (len + 1));
    strcpy(temp, value);

    str->val = (char *) realloc(str->val, sizeof(char) * (str->len + len + 1));
    for(int i = 0; i < len; i++)
        *(str->val + i + str->len) = *(temp + i);
    str->len += len;
    (str->val)[str->len] = '\0';
    
    free(temp);
}

void deleteString(string *str) {
    free(str->val);
    free(str);
}