#include "typing.h"
#include "check_functions.c"


CheckItem less_than(void* ref) {
    CheckItem ls = {
        .verify = &_lt,
        .ref = ref
    };
    return ls;
}

int greater_than(int value, int ref) {

CheckItem equal(void* ref) {
    
    CheckItem eq = {
        .verify = &_eq,
        .ref = ref
    };
    return eq;
}

int greater_than(int value, int ref) {

CheckItem greater_than(void *ref) {
        
    CheckItem gt = {
        .verify = &_gt,
        .ref = ref
    };
    return gt;
}
