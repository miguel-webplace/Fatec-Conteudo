### 23/08/2026 -- Reescrita da biblioteca

- Nova definição de utilização
- Structs `Form`, `Checklist` e `Validator` adicionadas

#### *Próximos passsos*

- Resolução para interface com os três possíveis tipos de dados
- Primeiros testes e handlers com alocação dinâmica de memória


### 28/08/2026 -- Estudando sobre dynamic memory

- Pasta sandbox separada para estudos e testes

- Adicionado comentários para relembrar

- Criado arquivo sandbox para testar ideia de lidar com tipos dentro dos filtros


# 01/09/2026

- Criação de teste para pointeiro que segura as funções de validação.
PROBLEMA: Algum desentendimento com ponteiros para ponteiros, rever a ordem de dereferenciação

# 20/09/2026

- Problema de ponteiro duplo resolvido
- Problema de erro de segmentação resolvido
- Isolamento `check_alloc_pointer` testado

# 22/09/2026

Ao continuar com os os testess fechados, dessa vez nos filtros, percebi que
precisava alterar o código do checklist com o pointer. Primeiro porque o teste
usava valores int, e segundo porque utilizar o primeiro item da lista de
memória dinâmica apenas para guardar o tamanho não é ideal.

Criei uma nova estrutura, que envolve os "itens" como um ponteiro
de memória dinâmica e inclui a informação do tamanho, o que tornou mais simples
a manipulação.

Para lidar com os diversos tipos de variáveis propostos, fiz testes com
void pointers para entender como generalizar e informar sobre o tipo do outro lado
do código.

Além disso, reescrevi a interface, descrita em 'age_filter.c' para facilitar a
escrita de itens do checklist, utilizando argumento variádico.

 Por fim, adicionei logs que podem ser ativados com o `define` para melhor
 processo de debug.

*Próximo desafio:** `va_arg`, dentro de `create_checklist` não funciona como
deveria: Em vez de passar para o próximo item, todas os itens `CheckItem`
recebem o mesmo valor de `ref`, no caso o valor do primeiro argumento
variádico.
