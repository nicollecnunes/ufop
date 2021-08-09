#include "ordenacao.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX_STR 1200

int main(){
    TPais *P;
    P = NULL;
    int qtd;

    lerQuantidade(&qtd);
    P = alocaPaises(P, qtd);
    lerLista(P, qtd);
    ordenaTudo(P, qtd);
    imprimePaises(P, qtd);
    P = desalocaPaises(P);


    return 0;
}