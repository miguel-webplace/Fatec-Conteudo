

typedef enum {
    INT,
    FLOAT,
    CHAR,
    STR
} DataType;

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
    DataType data_type;
    CheckList *checklist;
    char *invalid_msg;
    void *ipt_target; // TODO: Adicionar novo tipo para o tipo de variavel
} Field;


typedef struct {
    int size;
    Field *field_list;
} Form;
