#include <stdio.h>

void resolveType(char type, void *value, char **result);

int main() {
    
    int some_num = 23;
    char some_char = 'w';
    float some_float = 3.14;
    char *some_string = "uhuulll!!";
    
    char *first_type, *second_type, *third_type, *fourth_type;
    
    resolveType('i', &some_num, &first_type);
    resolveType('c', &some_char, &second_type);
    resolveType('f', &some_float, &third_type);
    resolveType('s', some_string, &fourth_type);
    // printf("%s", first_type);
    // printf("%s\n", second_type);
    // printf("%s\n", third_type);
    return 0;
}



void resolveType(char type, void *value, char **result) {
    
    
    switch (type) {
        case 'i':
            printf("This is an integer: %d\n", *(int*)value);
            break;
        case 'f':
            printf("This is a float: %f\n", *(float*)value);
            break;
        case 'c':
            printf("This is a char: %c\n", *(char*)value);
            break;
        case 's':
            printf("This is a string: %s\n", (char*)value);
            break;
    }
    return;
}
