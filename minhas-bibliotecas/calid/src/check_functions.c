
int _lt(void* value, void* ref) {
    return *(int*)value <= *(int*)ref;
}

int _eq(void* value, void* ref) {
    return *(int*)value == *(int*)ref;
}

int _gt(void* value, void* ref) {
    return *(int*)value >= *(int*)ref;
}
