#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "typing.h"


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
