#include <string.h>
#include "filters.c"

// #define DEBUG

void resolve_format(DataType data_type, char *fmt) {
    
    switch (data_type) {
        
        case INT:
            strcpy(fmt, "%d");  break;
            
        case FLOAT:
            strcpy(fmt, "%f");  break;
            
        case CHAR:
            strcpy(fmt, "%c");  break;
            
        case STR:
            strcpy(fmt, "%s");  break;
    }
    return;
}


int passtrough(void* ipt, CheckList *checklist) {
    
    for (int i_chk = 0; i_chk < checklist->size; ++i_chk) {
        
        CheckItem chk = checklist->list[i_chk];
        int pass = chk.verify(ipt, chk.ref);
        if (!pass) {
            return 0;
        }
    }
    return 1;
}


void ipt_target_resolver(void *ipt_target, void *ipt, DataType type) {
    
    switch (type) {
        case INT:
            *(int*)(ipt_target) = *(int*)ipt;  break;
            
        case FLOAT:
            *(float*)(ipt_target) = *(float*)ipt;  break;
            
        case CHAR:
            *(char*)(ipt_target) = *(char*)ipt;  break;
            
        case STR:
            *(char**)(ipt_target) = (char*)ipt;
            
    }
}


int apply(Form *form) {

    char fmt[3];
    Field *fields = form->field_list;
    
    int mem_alloc[30]; void *ipt = &mem_alloc;
    for (int i_fld = 0; i_fld < form->size; ++i_fld) {
        
        Field field = fields[i_fld];
        resolve_format(field.data_type, fmt);
        
        printf("%s\n---> ", field.question);
        
        
        #ifdef DEBUG
        printf("\n --- DEBUG ---> passed 'resolve_format'\n");
        #endif

        scanf(fmt, ipt);
        while (getchar() != '\n');
        
        #ifdef DEBUG
        printf(" --- DEBUG ---> passed 'scanf'\n");
        #endif
        
        
        
        int check_passed = passtrough(ipt, field.checklist);
        
        #ifdef DEBUG
        printf(" --- DEBUG ---> passed 'passtrough' function\n");
        #endif
        
        
        while (!check_passed) {
            printf("ERRO --> %s\n", field.invalid_msg);
            printf("-->  ");
            scanf(fmt, ipt);
            while (getchar() != '\n');
            check_passed = passtrough(ipt, field.checklist);
        }
        ipt_target_resolver(field.ipt_target, ipt, field.data_type);
        
        
        free(field.checklist->list); field.checklist->list = NULL;
    }
    free(form->field_list); form->field_list = NULL;
    return 0;
}
