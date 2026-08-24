#include <stdio.h>
#include <stdlib.h>

#define EX02


#ifdef EX01
// Playing with dynamic memory


void clear_buffer();

int main() {

    int size;

    printf("Digite com quantas letras quer comecar: ");
    scanf("%d", &size);

    printf("=======  size: %d =========\n", size);
    clear_buffer();

    char *pLetters = calloc(size, sizeof(*pLetters));

    if (pLetters == NULL) {
        printf("Falha ao alocar memoria\n");
        return 0;
    }

    for (int i = 0; i < size; i++) {
        printf("Letra: ");
        scanf("%c", (pLetters + i));
        clear_buffer();
    }

    for (int i = 0; i < size; i++) {
        printf("Letra %d: %c\n", i + 1, pLetters[i]);
    }

    free(pLetters);
    printf("Execucao concluida");

    return 0;
}


void clear_buffer() {
    while (getchar() != '\n');
    return;
}

#endif



#ifdef EX02
// Playing with dynamic memory


void clear_buffer();

int main() {

    int size;

    printf("Digite com quantas letras quer comecar: ");
    scanf("%d", &size);
    clear_buffer();

    char *pLetters = calloc(size, sizeof(*pLetters));

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

        if (nxt_letter == '0') break;

        if (idx == (size)) {

            printf("Realocando memoria...\n");
            size += 5;
            char *ptr_try = realloc(pLetters, size * sizeof(*pLetters));

            if (ptr_try == NULL) {
                printf("Realocacao falhou.\n");
                return 0;
            }
            
            pLetters = ptr_try;
            printf("Realocacao concluida\n");
            free(ptr_try);
        }

        pLetters[idx] = nxt_letter;
        idx++;
    }


    for (int i = 0; i < size; i++) {
        printf("LETRA: %c\n", pLetters[i]);
    }


    free(pLetters);
    printf("Execucao concluida");

    return 0;
}


void clear_buffer() {
    while (getchar() != '\n');
    return;
}

#endif