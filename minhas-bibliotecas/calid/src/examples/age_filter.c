#include "../scan.c"


// Example of filling a age field

int main() {


    // Variable and pointer to hold the data
    int user_age, *ptr_user_age;

    Form form = create_form();

    // Create a stack in dynamic memory for all the validations
    Checklist age_filters = create_checklist();

    // Allocating (or reallocating) memory for the filters
    add_check(age_filters, greater_than(18));
    add_check(age_filters, less_than(70));

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
