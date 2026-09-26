#include <stdio.h>
#include "form.c"


#define DEBUG
#define DEBUG_MAIN

int main() {
    // define references
    int children_min_limit = 110, children_max_limit = 152;
    int adult_min_limit = 178, adult_max_lmit = 205;

    // target variables for the final input
    int children_ipt = 148;
    int adult_ipt = 187;

    // set checklist
    CheckList age_filter_children = {.size = 2};
    create_checklist(&age_filter_children, less_than(&children_min_limit), greater_than(&children_max_limit));
    
    CheckList age_filter_adult = {.size = 2};
    create_checklist(&age_filter_adult, less_than(&adult_min_limit), greater_than(&adult_max_lmit));

    // define form
    Form height = {.size = 2};
    add_field(&height,
        (Field) {
            .question = "Qual é a sua idade? [ criança ] --> ",
            .checklist = &age_filter_children,
            .ipt_target = &children_ipt
        },
        (Field) {
            .question ="Qual é a sua idade? [ adulto ] -> ",
            .checklist = &age_filter_adult,
            .ipt_target = &adult_ipt
        }
    );
    
    #ifdef DEBUG
    printf(" --- DEBUG ---> input target children: %d\n", *(int*)height.field_list[0].ipt_target);
    #endif
    
    #ifdef DEBUG
    printf(" --- DEBUG ---> input target adult: %d\n", *(int*)height.field_list[1].ipt_target);
    #endif

    return 0;
}
