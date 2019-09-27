/*
 * Implementations of dictionary modifying functions
 */
#include <stdlib.h>
#include <string.h>

#include <dyllib.h>
#include <dict.h>

dict *newDict(void) {
    dict *new_dict = (dict *) malloc(sizeof(dict));

    new_dict->length = 0;
    new_dict->keys = dlib.newList();
    new_dict->values = dlib.newList();

    return new_dict;
}

dict *addToDict(dict *_dict, const char *key, void *value) {
    int key_len = strlen(key);
    char *key_str = (char *) malloc(sizeof(char) * (key_len + 1));
    memcpy(key_str, key, key_len);
    key_str[key_len] = '\0';

    dlib.appendList(_dict->keys, key_str);
    dlib.appendList(_dict->values, value);
    _dict->length++;

    return _dict;
}

void *getFromDict(dict *_dict, const char *key) {
    for(int i = 0; i < _dict->length; i++) {
        if(!strcmp((char *) dlib.accessList(_dict->keys, i), key))
            return dlib.accessList(_dict->values, i);
    }

    return NULL;
}

void deleteDict(dict *_dict) {
    dlib.deleteList(_dict->keys);
    dlib.deleteList(_dict->values);

    free(_dict);
}
