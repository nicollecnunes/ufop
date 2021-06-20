#include "fib.h"
#include<stdio.h>

int main()
{
    TADfib *f;
    int qtd;

    f = NULL;

    lerQuantidade(&qtd);
    f = alocaFib(f, qtd);
    lerCasos(f, qtd);
    imprimir(f, qtd);
    f = desalocaFib(f);
    //fazer a leitura do numero de casos de teste
    //ler o caso de teste e processar antes de ler o proximo
    //imprimir a resposta no formato adequado
    return 0;//nao remova
}
