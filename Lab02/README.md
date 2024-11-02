# Lab02 - Analisador Léxico com comentários

Este projeto implementa uma versão de um analisador léxico simples que reconhece tokens de um código fonte, incluindo números, palavras-chave e identificadores. O objetivo desse laboratório é de fazer modificações para permitir que o analisador ignore comentários de linha e comentários de bloco.

## Origem do Código Fonte

O código fonte original deste projeto foi inspirado em material didático sobre análise léxica e sintática. As implementações de métodos e a estrutura geral foram adaptadas para incluir melhorias e funcionalidades adicionais, como o tratamento de comentários.

## Funcionalidades

- **Reconhecimento de Tokens**: O analisador reconhece números, palavras-chave (`true`, `false`) e identificadores.
- **Ignorar Comentários**: Agora, o analisador ignora:
  - Comentários de linha (iniciados por `//`)
  - Comentários de bloco (iniciados por `/*` e terminados por `*/`)

## Modificações Realizadas

### 1. Ignorar Comentários de Linha

A função `skipLineComment` foi adicionada para ignorar todos os caracteres até o final da linha quando um comentário de linha é detectado:

```cpp
void Lexer::skipLineComment() {
    while (peek != '\n' && peek != EOF) {
        peek = cin.get();
    }
}
```

### 2. Ignorar Comentários de Bloco

A função `skipBlockComment` foi criada para lidar com comentários de bloco, que podem se estender por várias linhas:

```cpp
void Lexer::skipBlockComment() {
    while (true) {
        peek = cin.get();
        if (peek == EOF) return; // Para evitar loop infinito
        if (peek == '*') {
            peek = cin.get();
            if (peek == '/') return; // Final do comentário de bloco
        }
    }
}
```

### 3. Modificações na Função `Scan`

A função `Scan` foi modificada para incluir a lógica de ignorar comentários. Quando um `/` é encontrado, o analisador verifica se é o início de um comentário de linha ou de bloco:

```cpp
if (peek == '/') {
    char next_char = cin.get(); // Lê o próximo caractere sem perder 'peek'
    if (next_char == '/') {
        skipLineComment(); // Ignora até o final da linha
        return Scan(); // Chama novamente para processar a próxima parte
    } else if (next_char == '*') {
        skipBlockComment(); // Ignora até encontrar */
        peek = cin.get();   // Avança após o comentário de bloco
        return Scan(); // Chama novamente para processar a próxima parte
    } else {
        // Caso seja um caractere '/' isolado
        Token t {'/'};
        peek = next_char;
        cout << "<" << char(t.tag) << "> ";
        return t;
    }
}
```

# Desenvolvedor

- [Pedro Rêgo Vilar Neto](https://github.com/pedrorvn)
