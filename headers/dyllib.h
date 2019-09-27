/*
 * The main hub where all the libraries meet
 * In here there is a global instance that gets created whenever the library is used.
 * It contains function references to all the other libraries
 */
#ifndef _DYLLIB_H_
#define _DYLLIB_H_

#include <list.h>

typedef struct DYLAN_LIB {
    list (*newList)(void);
} dylanlib;

extern dylanlib dlib; 

#endif