#include "../calid.h"


/*
   Subscription form to test all the possible filters
   and to localize possible shortcuts and simplifications.
   
   
   FORM:
   |      Field     |         Filtering         |
   |       Name     |   Cannot contains spaces  |
   |       Age      |       >= 18 ; < 60        |
   |  Chair column  |       only 'B' to K'      |
   |    Chair row   |         only '45'         |
   |    Show date   |    not '26', '28', '30'   |
 */



int main() {
    
    // limiters reference
    char name_exclude_char = ' ';
    int age_min = 18, age_max = 60;  // min: >=  max: <
    char chair_column_range[2] = "BK";
    int chair_row_only = 45;
    int show_dates_exclude[] = {26, 28, 30};

    // input targets
    char name[25];
    int age;
    char chair_column;  int chair_row;
    int show_date;


    // form
    Form subscription_form = {.size = 3};

    // CheckList name_filters = {.size = 1};
    // create_checklist(&name_filters, notequal(&name_exclude_char));
    
    CheckList age_filters = {.size = 2};
    create_checklist(&age_filters, more_or_equal(&age_min), less_than(&age_max));

    CheckList chair_column_filters = {.size = 1};
    create_checklist(&chair_column_filters, in_range(&chair_column_range));

    CheckList chair_row_filters = {.size = 1};
    create_checklist(&chair_row_filters, equal(&chair_row_only));

    // CheckList show_date_filters = {.size = 1};
    // create_checklist(&show_date_filters, without(&show_dates_exclude));
    
    
    add_field(&subscription_form,
        // (Field) {
        //     .question = "Qual é o seu nome?",
        //     .invalid_msg = "Insira apenas o nome, sem espaços",
        //     .checklist = &name_filters,
        //     .data_type = STR,
        //     .ipt_target = &name
        // },
        (Field) {
            .question = "Qual é sua idade?",
            .invalid_msg = "Você não tem idade para o show",
            .checklist = &age_filters,
            .data_type = INT,
            .ipt_target = &age
        },
        (Field) {
            .question = "Choose a chair column",
            .invalid_msg = "The chair column must be in range of 'B' to 'K'",
            .checklist = &chair_column_filters,
            .data_type = CHAR,
            .ipt_target = &chair_column
        },
        (Field) {
            .question = "Choose a chair row",
            .invalid_msg = "The chair row can only be 45",
            .checklist = &chair_row_filters,
            .data_type = INT,
            .ipt_target = &chair_row
        }//,
        // (Field) {
        //     .question = "Choose a date",
        //     .invalid_msg = "Days '26', '28', and '30' are not available",
        //     .checklist = &show_date_filters,
        //     .data_type = INT,
        //     .ipt_target = &show_date
        // }
    );
    
    
    apply(&subscription_form);


    printf(
"Age: %d\n \
Chair column: %c\n \
Chair row: %d\n \
", age, chair_column, chair_row);
    
    return 0;
}
