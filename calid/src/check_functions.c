int _lt(void* value, void* ref) {
    return *(int*)value <= *(int*)ref;
}

int _eq(void* value, void* ref) {
    return *(int*)value == *(int*)ref;
}

int _gt(void* value, void* ref) {
    return *(int*)value > *(int*)ref;
}

int _gt_e(void* value, void* ref) {
    return *(int*)value >= *(int*)ref;
}


int _not_e(void*value, void *ref) {
    return *(int*)value != *(int*)ref;
}

int _range(void* value, void* ref) {
    
    int _value = *(int*) value;
    if (_value > 90) _value -= 32;
    
    int start = ((char*)ref)[0], end = ((char*)ref)[1];
    if (start > 90) start -= 32;
    if (end > 90) end -= 32;
    
    return ( !( _value < start || _value > end ) );
}


int strequal(void* value, void* ref) {
    return 0; // TODO
}
