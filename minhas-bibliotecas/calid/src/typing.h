
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
    char *invalid_msg;
    void **ipt_target; // TODO: Adicionar novo tipo para o tipo de variavel
    CheckList *checklist;
} Field;


typedef struct {
    int size;
    Field *field_list;
} Form;
