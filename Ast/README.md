
# LAB02: Modificações no AST para Suporte a Conversão de Inteiros para Booleanos

Este README documenta as alterações recentes feitas no código para permitir a conversão automática de expressões inteiras (`int`) para expressões booleanas (`bool`) em construções lógicas e de controle de fluxo, como `if`, `while` e `dowhile`.

## Origem do Código Fonte

O [código fonte original](https://github.com/JudsonSS/Compiladores/tree/master/Labs/Lab10) deste projeto foi inspirado em material didático sobre análise semântica. As implementações de métodos e a estrutura geral foram adaptadas para incluir melhorias e funcionalidades adicionais, como o tratamento de comentários.

## Descrição Geral

O objetivo dessas modificações é facilitar o uso de expressões inteiras em contextos booleanos, onde valores `int` são tratados como `bool` de acordo com a convenção comum: `0` representa `false`, e qualquer outro valor inteiro representa `true`.

## Alterações no Código

As mudanças a seguir foram feitas para suportar a conversão implícita de `int` para `bool`:

### 1. Classe `Logical`

Na classe `Logical`, responsável pela avaliação de expressões lógicas binárias, foi adicionada uma verificação dos tipos de `expr1` e `expr2`. Agora, se uma dessas expressões for `int`, ela é convertida para `bool`, utilizando o valor `0` como `false` e qualquer outro valor como `true`. Um novo `Token` é criado para representar a expressão convertida, e o tipo é atualizado para `ExprType::BOOL`.

```cpp
if (expr1->type == ExprType::INT) {
    int int_value1 = std::stoi(expr1->Name());
    bool bool_value1 = (int_value1 != 0);
    Token *bool_token1 = new Token(*expr1->token);
    bool_token1->lexeme = bool_value1 ? "true" : "false";
    expr1 = new Expression(NodeType::LOG, ExprType::BOOL, bool_token1);
}
```