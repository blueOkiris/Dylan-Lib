// Literally just for an instantiation of the "dylanlib" struct
#include <list.h>
#include <dyllib.h>

dylanlib dlib = { &newList, &appendList, &deleteList, &accessList };
