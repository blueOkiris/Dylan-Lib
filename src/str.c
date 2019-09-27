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

string *appendString(string *str, char *value) {
    int len = strlen(value);                                // Accessing passed in values into realloc creates mem leak. Store parameter as temp
    char *temp = (char *) malloc(sizeof(char) * (len + 1));
    strcpy(temp, value);

    str->val = (char *) realloc(str->val, sizeof(char) * (str->len + len + 1));
    for(int i = 0; i < len; i++)
        *(str->val + i + str->len) = *(temp + i);
    str->len += len;
    (str->val)[str->len] = '\0';

    free(temp);

    return str;
}

string *insertString(string *str, int index, char *value) {
    if(index >= str->len)
        return str;

    int len = strlen(value);
    char *temp = (char *) malloc(sizeof(char) * (len + 1));
    strcpy(temp, value);

    char *end_of_str = (char *) malloc(sizeof(char *) * (str->len - index + 1));
    strcpy(end_of_str, str->val + index);

    str->val = (char *) realloc(str->val, sizeof(char) * (str->len + len + 1));
    memcpy(str->val + index + len, end_of_str, strlen(end_of_str));
    memcpy(str->val + index, value, len);

    str->len += len;
    (str->val)[str->len] = '\0';

    free(end_of_str);
    free(temp);

    return str;
}

string *removeString(string *str, int start, int len) {
    memcpy(str->val + start, str->val + start + len, str->len - len);
    str->val = (char *) realloc(str->val, sizeof(char) * (str->len - len + 1));
    str->len -= len;
    str->val[str->len] = '\0';
    return str;
}

string *substring(string *str, int start, int len) {
    string *sub_str = newString();
    sub_str->val = (char *) realloc(sub_str->val, sizeof(char) * (len + 1));

    memcpy(sub_str->val, str->val + start, len);
    sub_str->len = len;
    sub_str->val[sub_str->len] = '\0';

    return sub_str;
}

void deleteString(string *str) {
    free(str->val);
    free(str);
}