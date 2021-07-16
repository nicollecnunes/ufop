#include "ordenacao.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX_STR 1200

int main(){
    TLista lista;
    int qtd;

    listaInicia(&lista);
    lerQuantidade(&qtd);

    lerLista(&lista, qtd);

    TLista_Imprime(&lista);

    return 0;
}