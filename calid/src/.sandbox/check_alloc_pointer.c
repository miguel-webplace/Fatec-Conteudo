#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "../typing.h"

#define DEBUG
// #define DEBUG_MAIN

/*
   This sandbox simulates the use and flow of the checklist struct
*/


int create_checklist(CheckList *checkptr, ...) {
    // hanlding code for variadic args
    
    int items_bytespace = sizeof(CheckItem) * checkptr->size;
    CheckItem *items = malloc(items_bytespace);
    if (items == NULL) {
        
        printf("Memory allocation error.\n");
        return 1;
    }
    checkptr->list = items;
    #ifdef DEBUG
    printf(" --- DEBUG --- : pointer allocation clear\n");
    #endif
    
    // add all the items
    va_list args;
    va_start(args, checkptr);
    for (int i = 0; i < checkptr->size; ++i) {
        
        CheckItem next_item = va_arg(args, CheckItem);
        #ifdef DEBUG
        printf(" --- DEBUG --- : next item ref value: %d\n", *(int*) next_item.ref);
        #endif
        checkptr->list[i] = next_item;
    }
    va_end(args);
    
    /*  ---- Testing ----
    check.list[0] = va_arg(args, CheckItem);
    check.list[1] = va_arg(args, CheckItem);
    -------- Testing ---- */
    
    #ifdef DEBUG
    printf(" --- DEBUG --- : adding items clear\n");
    #endif
    
    return 0;
}

#ifdef DEBUG_MAIN
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
