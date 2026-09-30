#include "dyn_adders.c"
#include "check_functions.c"


CheckItem less_than(void* ref) {
    CheckItem ls = {
        .verify = &_lt,
        .ref = ref
    };
    return ls;
}


CheckItem equal(void* ref) {
    
    CheckItem eq = {
        .verify = &_eq,
        .ref = ref
    };
    return eq;
}


CheckItem greater_than(void *ref) {
        
    CheckItem gt = {
        .verify = &_gt,
        .ref = ref
    };
    return gt;
}


CheckItem more_or_equal(void *ref) {
    CheckItem gt_e = {
        .verify = &_gt_e,
        .ref = ref
    };
    return gt_e;
}

CheckItem notequal(void *ref) {
    CheckItem not_e = {
        .verify = &_not_e,
        .ref = ref
    };
    return not_e;
}

CheckItem in_range(void *ref) {
    CheckItem range = {
        .verify = &_range,
        .ref = ref
    };
    return range;
}

// CheckItem without(void *ref) {
//     CheckItem without = {
//         .verify = &_without,
//         .ref = ref
//     };
//     return without;
// }
