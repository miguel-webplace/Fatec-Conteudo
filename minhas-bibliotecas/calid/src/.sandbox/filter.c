#include "check_alloc_pointer.c"

#define DEBUG
#define DEBUG_MAIN

int _lt(void* value, void* ref) {
    return *(int*)value <= *(int*)ref;
}

CheckItem less_than(void* ref) {
    CheckItem ls = {
        .verify = &_lt,
        .ref = ref
    };
    return ls;
}

// --------------------------------------------------

int _eq(void* value, void* ref) {
    return *(int*)value == *(int*)ref;
}

CheckItem equal(void* ref) {
    
    CheckItem eq = {
        .verify = &_eq,
        .ref = ref
    };
    return eq;
}

// --------------------------------------------------

int _gt(void* value, void* ref) {
    return *(int*)value >= *(int*)ref;
}

CheckItem greater_than(void *ref) {
        
    CheckItem gt = {
        .verify = &_gt,
        .ref = ref
    };
    return gt;
}

// --------------------------------------------------

#ifdef DEBUG_MAIN
int main() {
    int ipt_age_1 = 10, ipt_age_2 = 18, ipt_age_3 = 90;

    int AGE_18 = 18, AGE_90 = 80;
    
    // CheckList age_filter = create_checklist(2, greater_than(&AGE_18), less_than(&AGE_90));
    CheckList age_filter = {.size = 2};
    create_checklist(&age_filter, greater_than(&AGE_18), less_than(&AGE_90));
    
    printf(" --- DEBUG --- : 'greater_than' ref value: %d\n", *(int*) age_filter.list[0].ref);
    printf(" --- DEBUG --- : 'less_than' ref value: %d\n\n", *(int*) age_filter.list[1].ref);

    char verify_gt_1 = (age_filter.list[0].verify(&ipt_age_1, age_filter.list[0].ref)) ? 's' : 'n';
    char verify_gt_2 = (age_filter.list[0].verify(&ipt_age_2, age_filter.list[0].ref)) ? 's' : 'n';
    char verify_gt_3 = (age_filter.list[0].verify(&ipt_age_3, age_filter.list[0].ref)) ? 's' : 'n';

    char verify_lt_1 = (age_filter.list[1].verify(&ipt_age_1, age_filter.list[1].ref)) ? 's' : 'n';
    char verify_lt_2 = (age_filter.list[1].verify(&ipt_age_2, age_filter.list[1].ref)) ? 's' : 'n';
    char verify_lt_3 = (age_filter.list[1].verify(&ipt_age_3, age_filter.list[1].ref)) ? 's' : 'n';

    printf(" --- DEBUG --- : 'greater_than' verify age %d: %c\n", ipt_age_1, verify_gt_1);
    printf(" --- DEBUG --- : 'greater_than' verify age %d: %c\n", ipt_age_2, verify_gt_2);
    printf(" --- DEBUG --- : 'greater_than' verify age %d: %c\n\n", ipt_age_3, verify_gt_3);

    printf(" --- DEBUG --- : 'less_than' verify age %d: %c\n", ipt_age_1, verify_lt_1);
    printf(" --- DEBUG --- : 'less_than' verify age %d: %c\n", ipt_age_2, verify_lt_2);
    printf(" --- DEBUG --- : 'less_than' verify age %d: %c\n\n", ipt_age_3, verify_lt_3);
    return 0;
}
#endif
