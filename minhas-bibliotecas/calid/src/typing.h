
typedef int ( Validator )( void*, void* ); // TODO: Adicionar novo tipo para o tipo de variavel


typedef struct {
    Validator *verify;
    void *ref; // TODO: Adicionar novo tipo para o tipo de variavel
} CheckItem;

typedef struct {
    CheckItem *list;
    int size;
} CheckList;

typedef struct {
    char *question;
    char *msg_err;
    void **destiny_ptr; // TODO: Adicionar novo tipo para o tipo de variavel
    CheckList *checklist;
} Form;
