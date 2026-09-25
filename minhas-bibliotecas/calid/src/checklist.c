/*
   This sandbox simulates the use and flow of the checklist struct
 */

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "typing.h"



int create_checklist(CheckList *checkptr, ...) {
    
    int items_bytespace = sizeof(CheckItem) * checkptr->size;
    CheckItem *items = malloc(items_bytespace);
    if (items == NULL) {
        
        printf("Memory allocation error.\n");
        return 1;
    }
    checkptr->list = items;
    
    // add all the items
    va_list args;
    va_start(args, checkptr);
    for (int i = 0; i < checkptr->size; ++i) {
        
        CheckItem next_item = va_arg(args, CheckItem);
        checkptr->list[i] = next_item;
    }
    va_end(args);
    
    return 0;
}
