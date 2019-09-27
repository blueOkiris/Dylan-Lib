/*
 * Implementations of dictionary modifying functions
 */
#include <stdlib.h>

#include <dyllib.h>
#include <dict.h>

dict *newDict(void) {
    dict *new_dict = (dict *) malloc(sizeof(dict));

    new_dict->length = 0;
    new_dict->keys = dlib.newList();
    new_dict->values = dlib.newList();

    return new_dict;
}

dict *addToDict(dict *_dict, string *key, void *value) {
    
    return _dict;
}
