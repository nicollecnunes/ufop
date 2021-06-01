#include "matriz.h"
#include<stdio.h>

int main()
{
    double M[12][12], resultado;
    char operacao;

    lerOperacao(&operacao);
    lerMatriz(M);
    resultado = somaMatriz(M); //ok

    if(operacao == 'M')
      resultado = media(resultado); //ok

    printResultado(resultado); //ok

    return 0;//nao remova
}
