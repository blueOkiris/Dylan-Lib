#ifndef _MAP_H_
#define _MAP_H_

#ifndef DEFAULT_BUCKET_SIZE
#define DEFAULT_BUCKET_SIZE 40
#endif

#define DEFINE_MAP_TYPE( key_type, key_type_name, value_type, value_type_name ) \
typedef struct key_type_name##2##value_type_name##bucket {\
    key_type key;\
    value_type value;\
    struct key_type_name##2##value_type_name##bucket *next;\
} key_type_name##2##value_type_name##bucket;\
\
typedef struct key_type_name##2##value_type_name##map {\
    key_type_name##2##value_type_name##bucket *buckets;\
    int length;\
} key_type_name##2##value_type_name##map;\
\
void key_type_name##2##value_type_name##map_put( key_type_name##2##value_type_name##map *, key_type , value_type );\
value_type key_type_name##2##value_type_name##map_get( key_type_name##2##value_type_name##map *, key_type );\
key_type_name##2##value_type_name##map * key_type_name##2##value_type_name##map_new(void);

#define IMPLEMENT_MAP_TYPE( key_type, key_type_name, value_type, value_type_name, hash_function, compare_function ) \
void key_type_name##2##value_type_name##map_put( key_type_name##2##value_type_name##map *hashmap, key_type key, value_type value) {\
    int index = hash_function(key) % hashmap->length;\
    \
    key_type_name##2##value_type_name##bucket *current_loc = &(hashmap->buckets[index]);\
    \
    while(current_loc->key != NULL && compare_function(current_loc->key, key) != 0) {\
        current_loc = current_loc->next;\
    }\
    \
    if(current_loc->key == NULL)\
        current_loc->next = ( key_type_name##2##value_type_name##bucket *) malloc(sizeof( key_type_name##2##value_type_name##bucket ));\
    \
    current_loc->key = key;\
    current_loc->value = value;\
}\
\
value_type key_type_name##2##value_type_name##map_get( key_type_name##2##value_type_name##map *hashmap, key_type key) {\
    int index = hash_function(key) % hashmap->length;\
    \
    key_type_name##2##value_type_name##bucket *current_loc = &(hashmap->buckets[index]);\
    \
    if(current_loc->key == NULL)\
        return NULL;\
    \
    while(compare_function(current_loc->key, key) != 0) {\
        current_loc = current_loc->next;\
        \
        if(current_loc->key == NULL)\
            return NULL;\
    }\
    \
    return current_loc->value;\
}\
\
key_type_name##2##value_type_name##map * key_type_name##2##value_type_name##map_new(void) {\
    key_type_name##2##value_type_name##map *new_map = ( key_type_name##2##value_type_name##map *) malloc(sizeof( key_type_name##2##value_type_name##map ));\
    \
    new_map->buckets = ( key_type_name##2##value_type_name##bucket *) malloc(sizeof( key_type_name##2##value_type_name##bucket ) * DEFAULT_BUCKET_SIZE);\
    new_map->length = DEFAULT_BUCKET_SIZE;\
    \
    for(int i = 0; i < DEFAULT_BUCKET_SIZE; i++) {\
        new_map->buckets[i].key = NULL;\
        new_map->buckets[i].value = NULL;\
        new_map->buckets[i].next = NULL;\
    }\
    \
    return new_map;\
}

#endif
