#include "../scan.c"


// Example of filling a age field

int main() {
    
    
    // Variable and pointer to hold the data
    int user_age, *ptr_user_age = &user_age;
    
    Form *form = create_form();
    
    // create checklist passing the number of items
    CheckList age_filters = {.size = 2};
    
    // add the filters to 'checklist'
    create_checklist(&age_filters, greater_than(18), less_than(70));
    
    // include fields on the same pointer, as a form
    add_field(
        &form,
        "Digite a sua idade: ",
        "por favor, insira uma idade válida: ",
        &ptr_user_age,
        &age_filters
    );

    // run the form
    apply(form);

    return 0;
}
