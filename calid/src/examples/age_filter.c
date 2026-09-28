#include "../calid.h"


// Example of filling a age field

int main() {
    
    int min_children_age = 3, max_children_age = 17;
    int min_adult_age = 18, max_adult_age = 69;
    
    // Variable and pointer to hold the data
    int adult_age, *ptr_adult_age;
    int children_age, *ptr_children_age;
    
    Form form = {.size = 2};
    
    // create checklist passing the number of items
    CheckList adult_filter = {.size = 2};
    CheckList children_filter = {.size = 2};
    
    // add the filters to 'checklist'
    create_checklist(&adult_filter, greater_than(&min_adult_age), less_than(&max_adult_age));
    create_checklist(&children_filter, greater_than(&min_children_age), less_than(&max_children_age));
    
    // include fields on the same pointer, as a form
    add_field(&form, (Field) {
        .question = "Digite a sua idade [ ADULTO ]",
        .invalid_msg = "Isso não é idade de adulto",
        .ipt_target = &adult_age,
        .data_type = INT,
        .checklist = &adult_filter
        },
        (Field) {
            .question = "Digite a sua idade [ CRIANÇA ]",
            .invalid_msg = "Isso não é idade de criança",
            .ipt_target = &children_age,
            .data_type = INT,
            .checklist = &children_filter
        });
    
    // run the form
    apply(&form);
    
    
    printf("Idade do adulto: %d\n", adult_age);
    printf("Idade da criança: %d\n", children_age);
    return 0;
}
