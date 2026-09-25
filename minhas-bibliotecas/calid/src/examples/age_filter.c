#include "../scan.c"


// Example of filling a age field

int main() {
    
    
    // Variable and pointer to hold the data
    int user_age, *ptr_user_age = &user_age;
    
    Form *form = {.size = 1};
    
    // create checklist passing the number of items
    CheckList age_filters = {.size = 2};
    
    // add the filters to 'checklist'
    create_checklist(&age_filters, greater_than(18), less_than(70));
    
    // include fields on the same pointer, as a form
    add_field(&form, {
        .question = "Digite a sua idade: ";
        .invalid_msg = "por favor, insira uma idade válida: ",
        .ipt_target = &ptr_user_age,
        .checklist = &age_filters
    });
    
    // run the form
    apply(form);

    return 0;
}
