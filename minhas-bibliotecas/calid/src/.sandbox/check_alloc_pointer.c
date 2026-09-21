#include <stdio.h>
#include <stdlib.h>

#include "../typing.h"



/*
   This sandbox simulates the use and flow of the checklist struct

   - a checklist dynamic space is allocated and returned using 'create_checklist'

   - to add items, the 'add_check' reads the size of the space using the value attribute
   on the first "dummy" element, realloc based on this, replaces old pointer and updates the
   new size
 */

Checklist* create_checklist() {
    // Create dynamic memory pointer to hold the validations
    Checklist *checklist_ptr = malloc(sizeof(Checklist) * 2);
    
    /*
    use index 0 to hold the size of the stack with
    the value property
    */
    Checklist size = {.value = 0};
    checklist_ptr[0] = size;
    return checklist_ptr;
}

int add_check(Checklist **check_ptr, int value) {
    
    // pointer confusion resolved: using parenthesis for operation precedence work as intended
    int actual_size = ( *check_ptr )->value;
    int new_size = actual_size + 1;
    
    // save copy of the pointer for safety
    Checklist *ptr_cpy = *check_ptr;
    *check_ptr = realloc(*check_ptr, sizeof(Checklist) * (new_size));

    // pointer check
    if ( *check_ptr == NULL) {
        printf("Allocation memory error\n");
        *check_ptr = ptr_cpy;
        return 1;
    }
    // safety measure
    free(ptr_cpy);
    ptr_cpy = NULL;
    
    // add new item
    Checklist new_item = {
        .value = value
    };
    ( *check_ptr )[new_size] = new_item;
    
    // update size of checklist
    ( *check_ptr )[0].value = new_size;
    
    return 0;
}


int main() {
    
    Checklist *checklist = create_checklist();
    
    add_check(&checklist, 3);
    add_check(&checklist, 4);
    add_check(&checklist, 23);
    add_check(&checklist, 201);
    
    printf("item: %d\n", (checklist[1].value));
    printf("item: %d\n", (checklist[2].value));
    printf("item: %i\n", (checklist[3].value));
    printf("item: %i\n", (checklist[4].value));
    return 0;
}
