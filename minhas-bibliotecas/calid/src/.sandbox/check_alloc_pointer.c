#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "../typing.h"
#define DEBUG


/*
   This sandbox simulates the use and flow of the checklist struct
 */


CheckList create_checklist(int size, ...) {
    // hanlding code for variadic args
    va_list args;
    va_start(args, size);
    
    CheckList check = {.size = size};
    
    // gets allocation size and verifies allocation
    int items_bytespace = sizeof(CheckItem) * size;
    CheckItem *item_ptr = malloc(items_bytespace);
    if (item_ptr == NULL) {
        
        printf("Memory allocation error.\n");
        check.size = -1;
        return check;
    }
    check.list = item_ptr;
    free(item_ptr); item_ptr = NULL;
    
    #ifdef DEBUG
    printf(" --- DEBUG --- : pointer allocation clear\n");
    #endif
    
    // Add all the items
    for (int i = 0; i < size; ++i) {
        
        CheckItem next_item = va_arg(args, CheckItem);
        #ifdef DEBUG
        printf(" --- DEBUG --- : next item ref value: %d\n", *(int*) next_item.ref);
        #endif
        check.list[i] = next_item;
    }
    va_end(args);
    #ifdef DEBUG
    printf(" --- DEBUG --- : adding items clear\n");
    #endif
    
    return check;
}

#ifdef DEBUG_WITH_MAIN
int main() {
    
    CheckList age_filters = {.size = 2};
    
    int value_1 = 36, value_2 = 600;
    CheckItem more_than = {.value = &value_1}, less_than = {.value = &value_2};
    create_checklist(&age_filters, more_than, less_than);
    
    int print_value_1 = *(int*) age_filters.list[0].value;
    printf("VALUE 1: %d\n", print_value_1);
    
    printf("VALUE 2: %d\n", *(int*) age_filters.list[1].value);
    return 0;
}
#endif
