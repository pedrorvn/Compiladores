
# Lab03 - Implementação do Laço `while` no Gerador de Código Intermediário

Este projeto expande o gerador de código intermediário, adicionando suporte para o laço `while`. 

## Origem do Código Fonte

O código fonte original deste projeto pode ser encontrado [aqui](https://github.com/JudsonSS/Compiladores/tree/master/Labs/Lab11).

## Alterações Realizadas

### 1. Criação da Classe `While`

Foi adicionada a classe `While`, herdando de `Statement`, para representar a estrutura do laço `while` no código intermediário. Esta classe possui:

- **Atributos**:
  - `expr`: expressão condicional do laço `while`.
  - `stmt`: corpo do laço, representado por uma instância de `Statement`.
  - `start` e `end`: rótulos para o início e o fim do loop.

### 2. Construtor da Classe `While`

O construtor `While(Expression *e, Statement *s)` inicializa os atributos `expr` e `stmt`, além de definir os rótulos `start` e `end` com valores únicos usando a função `NewLabel()`.

#### Código do Construtor

```cpp
While::While(Expression *e, Statement *s) 
    : Statement(NodeType::WHILE_STMT), expr(e), stmt(s) 
{
    start = NewLabel();  // Rótulo para o início do loop
    end = NewLabel();    // Rótulo para o final do loop
}
```

### 3. Método `Gen()` da Classe `While`

O método `Gen()` gera o código intermediário para o loop `while`, com a seguinte lógica:

1. **Início do Loop**: Imprime o rótulo `L<start>`.
2. **Avaliação da Condição**: Gera o código da condição. Se `false`, salta para `L<end>`.
3. **Corpo do Laço**: Chama `Gen()` para gerar o código do corpo.
4. **Retorno ao Início**: Salta para `L<start>` para reavaliar a condição.
5. **Fim do Loop**: Imprime `L<end>` para marcar o fim do laço.

#### Código do Método `Gen()`

```cpp
void While::Gen()
{
    cout << "L" << start << ":" << endl;  // Início do loop
    Expression *cond = Rvalue(expr);      // Avalia a condição
    cout << "	ifFalse " << cond->ToString() << " goto L" << end << endl;  // Salta para o fim se falso
    stmt->Gen();                          // Gera o código para o corpo do loop
    cout << "	goto L" << start << endl;   // Volta ao início para reavaliar
    cout << "L" << end << ":" << endl;     // Fim do loop
}
```


### Exemplo de Teste

Para testar, o repositório já conta com arquivos de teste, basta rodar o executável `tradutor` com algum dos arquivos na pasta `/Testes`, o `teste4.cpp` é o que testa a adição da lógica `while'.

# Desenvolvedor

- [Pedro Rêgo Vilar Neto](https://github.com/pedrorvn)