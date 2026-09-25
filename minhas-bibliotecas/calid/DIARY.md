### 23/08/2026 -- Reescrita da biblioteca

- Nova definição de utilização
- Structs `Form`, `Checklist` e `Validator` adicionadas

---

#### *Próximos passsos*
- Resolução para interface com os três possíveis tipos de dados
- Primeiros testes e handlers com alocação dinâmica de memória

---

### 28/08/2026 -- Estudando sobre dynamic memory
- Pasta sandbox separada para estudos e testes

- Adicionado comentários para relembrar

- Criado arquivo sandbox para testar ideia de lidar com tipos dentro dos filtros

---

# 01/09/2026
- Criação de teste para pointeiro que segura as funções de validação.
PROBLEMA: Algum desentendimento com ponteiros para ponteiros, rever a ordem de dereferenciação

---

# 20/09/2026
- Problema de ponteiro duplo resolvido
- Problema de erro de segmentação resolvido
- Isolamento `check_alloc_pointer` testado

---

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

---

# 23/09/2026
O suposto erro de `va_arg` foi encontrado, e não era sobre o `stdarg.h`.

As funções responsáveis por validar o input [ `_gt`, `_lt` ] fazem
parte de um alias de função `Validator`, que retorna `int` e recebe dois void pointers.

Minha teoria é que, ao chamar o handler `greater_than`, com a referência passada por cópia,
o valor repassado por referência a função validadora de alguma forma é salvo no nível do alias
em vez do implemento, fazendo com que todos os itens ficassem com o valor do primeiro
handler chamado.

Verifiquei se havia algum sentido trocando a ordem dos handlers, o que de fato mudou o valor
repetido.

Ao analisar com Claude -- antes de notar o problema -- encontrei erros ao liberar memória
do ponteiro acidentalmente e o uso do `va_start` cedo de forma desnecesaŕia, o necessitava
usar `va_end` no fluxo opcional da função.

*Próximos desafios:*
- Testar lógica semelhante do `CheckList` em `Form`
- Desenvolver lógica para salvar o input validado em variável não-genérica

---

# 24/09/2026

 Sabendo que a lógica do armazenamento da estrutura `Form` é semelhante a `ChekcList`, sua
 implementação foi simples e fluida por já conhecer os erros e o caminho certo.

 Todo o código de `.sandbox` que funciona como deveria foi colocado também nos arquivos definitivos
 da biblioteca. Ordem de importações, estrutura de arquivos e detalhes do tipo serão resolvidos
 no futuro. Nesse processo, as funções que realizam a validação e o handler que cria a estrutura
 `CheckList` foram separadas em arquivos diferentes
