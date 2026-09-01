#include <stdio.h>
#include <stdlib.h>

#include "typing.h"

Checklist* create_checklist() {
    // Create dynamic memory pointer to hold the validations
    Checklist *checklist_ptr = malloc(sizeof(Checklist));
    
    /*
    use index 0 to hold the size of the stack with
    the value property
    */
    Checklist size = {.value = 0};
    checklist_ptr[0] = size;
    return checklist_ptr;
}

void add_check(Checklist **check_ptr, Checklist new) {
    int actual_size = *(check_ptr + 0)->value; // possible point of failure
    // the 'plus 2' is counting for the first dummy element 
    Checklist *temp_ptr = realloc(*check_ptr, sizeof(Checklist) * (actual_size + 2));
    
    if ( temp_ptr == NULL) {
        printf("Allocation memory error\n");
        return;    
    }

    check_ptr = temp_ptr;
    check_ptr[actual_size + 1] = new;

    return;
}


int main() {


    return 0;
}