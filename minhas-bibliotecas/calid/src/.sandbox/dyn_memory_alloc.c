#include <stdio.h>
#include <stdlib.h>


void clear_buffer();

int main() {

    // ask for initial memory size
    int size;
    printf("Digite com quantas letras quer comecar: ");
    scanf("%d", &size);

    printf("=======  size: %d =========\n", size);
    clear_buffer();

    // alloc memory for specified size
    char *pLetters = calloc(size, sizeof(*pLetters));

    // check if was sucessfully allocated
    if (pLetters == NULL) {
        printf("Falha ao alocar memoria\n");
        return 0;
    }

    // ask for letters and save it on dynamic allocated pointer
    for (int i = 0; i < size; i++) {
        printf("Letra: ");
        scanf("%c", (pLetters + i));
        clear_buffer();
    }

    // show letters
    for (int i = 0; i < size; i++) {
        printf("Letra %d: %c\n", i + 1, pLetters[i]);
    }

    // freeing the pointer (essential)
    free(pLetters);
    printf("Execucao concluida\n");

    return 0;
}


void clear_buffer() {
    while (getchar() != '\n');
    return;
}