int main()
{
    int i; int j; int k; int vet[10]; bool flag;
    i = 0;
    j = 9;
    k = 1;
    flag = false;

    do
    {
        // Testa a conversão de inteiros para booleanos (i e k)
        while (i)  // Aqui i = 0, então não deve entrar no loop até i ser alterado
        {
            i = i + 1;
        }
        i = 1;  // Altera i para testar a conversão para true
        while (i)  // Agora i = 1, então deve entrar no loop
        {
            i = 0;  // Isso termina o loop
        }

        // Testa operadores lógicos com a conversão de j, k e flag
        while (j && k || !flag)  // j = 9, k = 1, ambos são true; flag = false
        {
            j = j - 1;  // Continua o loop até j ser 0
        }

        // Teste de array (vet) e operadores booleanos no if
        vet[0] = 2;
        vet[1] = 4;
        if (vet[i])  // Verifica se vet[i] não é zero
        {
            vet[i] = vet[i - 1] * 2;  // Cálculo com vet
        }

        flag = true;  // Atualiza flag para verificar o impacto no próximo loop
    }
    while (i < j);  // i = 0, j será atualizado, então isso pode parar o loop quando i >= j


}
