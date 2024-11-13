#include "parser.h"
#include "tokens.h"
#include <iostream>
using std::cout;
using std::string;


string unescapeString(const string& str) {
    string result;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '\\' && (i + 1) < str.length()) {
            // Verifica o próximo caractere
            switch (str[i + 1]) {
                case '"': result += '"'; ++i; break; // Aspas
                case '\\': result += '\\'; ++i; break; // Barra invertida
                default: result += str[i]; break; // Se não for um caractere de escape conhecido, adiciona o atual
            }
        } else {
            result += str[i]; // Adiciona o caractere normal
        }
    }
    return result;
}

void Parser::Start()
{
    // enquanto não atingir o fim da entrada
    while ((lookahead = scanner.yylex()) != 0)
    {
        // trata o token recebido do analisador léxico
        switch(lookahead)
        {
            case IF: cout << "IF\n"; break;
            case THEN: cout << "THEN\n"; break;
            case ELSE: cout << "ELSE\n"; break;
            case WHILE: cout << "WHILE\n"; break;
            case ID: cout << "ID: " << scanner.YYText() << "\n"; break;
            case NUM: cout << "NUM: " << scanner.YYText() << "\n"; break;
            case RELOP: cout << "RELOP: " << scanner.YYText() << "\n";; break;
            case STRING: 
                {
                    string unescaped = unescapeString(scanner.YYText());
                    cout << "STRING: " << unescaped << "\n";
                }
                break;
        }
    }
}
