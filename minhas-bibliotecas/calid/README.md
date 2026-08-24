# Calid: Validação de inputs sem preocupação

## Idealização

Desenvolver uma biblioteca em C capaz de receber um dado e validá-lo. A biblioteca deverá se capaz de pedir input ao usuário, validar e, se necessário, pedir novamente, até receber o valor certo, além de poder validar um vários valores com a mesma seleção de filtros.


## Tipos de filtros

- igual a
- maior que | menor que | 
- lista pré-selecionada (exclusão ou inclusão)


# Fluxo de utilização

1. Definir variável que receberá o valor validado
2. Definir pergunta ao usuário e mensagem de erro
3. Definir conjunto de filtros a serem aplicados
4. Chamar função para aplicar conectar filtros a sua variável
4. Chamar função para executar fluxo
