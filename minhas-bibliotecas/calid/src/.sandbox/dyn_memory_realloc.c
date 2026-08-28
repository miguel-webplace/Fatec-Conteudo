#include <stdio.h>
#include <stdlib.h>


void clear_buffer();

int main() {

    // ask for inintal size
    int size;
    printf("Digite com quantas letras quer comecar: ");
    scanf("%d", &size);
    clear_buffer();

    // allocate space
    char *pLetters = calloc(size, sizeof(*pLetters));

    // check if was sucessfull
    if (pLetters == NULL) {
        printf("Falha ao alocar memoria\n");
        return 0;
    }

    printf("Insira quantas letras quiser. Quando terminar, digite '0' na proxima letra\n");


    int idx = 0;
    while (1) {
        printf("--> ");
        char nxt_letter = getchar();
        while (getchar() != '\n');
        printf("\n");

        // stop with data insertion
        if (nxt_letter == '0') break;

        // when the allocated memory is full...
        if (idx == (size)) {

            // allocate more memory
            printf("Realocando memoria...\n");
            size += 5;
            char *ptr_try = realloc(pLetters, size * sizeof(*pLetters)); // temporary pointer for safety

            // always check if it was sucessfull
            if (ptr_try == NULL) {
                printf("Realocacao falhou.\n");
                return 0;
            }
            

            pLetters = ptr_try; // replace old pointer
            printf("Realocacao concluida\n");
            free(ptr_try); // freee old pointer for good measure
        }

        pLetters[idx] = nxt_letter;
        idx++;
    }

    // showing letters
    for (int i = 0; i < size; i++) {
        printf("LETRA: %c\n", pLetters[i]);
    }


    free(pLetters); // ALWAYS free the pointer when end using it
    printf("Execucao concluida");

    return 0;
}


void clear_buffer() {
    while (getchar() != '\n');
    return;
}