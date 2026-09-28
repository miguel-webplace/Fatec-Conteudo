#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
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





int add_field(Form *formptr, ...) {
    
    int field_bytespace = sizeof(Field) * formptr->size;
    Field *fields = malloc(field_bytespace);
    if (fields == NULL) {
        
        printf("Memory allocation error.\n");
        return 1;
    }
    formptr->field_list = fields;
    
    va_list args;
    va_start(args, formptr);
    for (int i = 0; i < formptr->size; ++i) {
        
        Field nxt_field = va_arg(args, Field);
        formptr->field_list[i] = nxt_field;
    }
    va_end(args);
    
    return 0;
}
