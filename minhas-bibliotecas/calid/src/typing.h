
typedef int ( *Validator )(int, int); // TODO: Adicionar novo tipo para o tipo de variavel


typedef struct {
    Validator *verify;
    int value; // TODO: Adicionar novo tipo para o tipo de variavel
} Checklist;


typedef struct {
    char *question;
    char *question_err;
    int **destiny_ptr; // TODO: Adicionar novo tipo para o tipo de variavel
    Checklist *checklist;
} Form;
