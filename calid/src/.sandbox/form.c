#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "../typing.h"

#define DEBUG
#define DEBUG_MAIN



int add_field(Form *formptr, ...) {
    
    int field_bytespace = sizeof(Field) * formptr->size;
    Field *fields = malloc(field_bytespace);
    if (fields == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }
    formptr->field_list = fields;
    #ifdef DEBUG
    printf(" --- DEBUG --- : pointer allocation clear\n");
    #endif
    
    va_list args;
    va_start(args, formptr);
    for (int i = 0; i < formptr->size; ++i) {
        Field nxt_field = va_arg(args, Field);
        formptr->field_list[i] = nxt_field;
    }
    va_end(args);

    return 0;
}


#ifdef DEBUG_MAIN
int main() {
    
    Form form = {.size = 2};
    
    add_field(&form,
        (Field) {
            .question = "Qual é o nome do batman indiano?",
            .invalid_msg = "Sera memo?",
        },
        (Field) {
            .question = "Tu vens, tu vais?",
            .invalid_msg = "AAAAAAAAAAAA"
        }
    );
    
    #ifdef DEBUG
    printf(" --- DEBUG ---> first field question: %s\n", form.field_list[0].question);
    #endif
    
    #ifdef DEBUG
    printf(" --- DEBUG ---> first field invalid input: %s\n", form.field_list[0].invalid_msg);
    #endif
    
    #ifdef DEBUG
    printf(" --- DEBUG ---> second field question: %s\n", form.field_list[1].question);
    #endif
    
    #ifdef DEBUG
    printf(" --- DEBUG ---> second field invalid input: %s\n", form.field_list[1].invalid_msg);
    #endif
    
    
    return 0;
}
#endif
