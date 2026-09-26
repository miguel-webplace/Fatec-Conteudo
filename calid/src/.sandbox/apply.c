#include "stdio.h"
#include "../typing.h"
#include <string.h>



void resolve_format(DataType data_type, char *fmt) {
    
    switch (data_type) {
        
        case INT:
            strcpy(fmt, "%d");
            break;
            
        case FLOAT:
            strcpy(fmt, "%f");
            
        case CHAR:
            strcpy(fmt, "%c");
            
        case STR:
            strcpy(fmt, "%s");
    }
}


int passtrough(void* ipt, CheckList *checklist) {
    return 0; //
}


int apply(Form *form) {

    Field *fields = form->field_list;
    for (int i_fld = 0; i_fld < form->size; ++i_fld) {
        
        Field field = fields[i_fld];
        void *ipt;
        
        printf("%s\n---> ", field.question);

        char fmt[3]; resolve_format(field.data_type, fmt);

        scanf(fmt, ipt);

        int check_passed = passtrough(ipt, field.checklist);
        if (check_passed) {
            field.ipt_target = ipt;
        } else {
            
            while (!check_passed) {
                scanf(fmt, ipt);
                check_passed = passtrough(ipt, field.checklist);
            }
        }
    }
    return 0;
}
