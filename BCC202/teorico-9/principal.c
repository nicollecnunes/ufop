#include "arrays.h"
#include<stdio.h>

void concatena(TADLista *A, TADLista *B){
    int j=0;
    for (int i = A->last; i<=(A->last + B->last - 1); i++){
        A->item[i].key = B->item[j].key;
        printf("A na posicao [%d] recebe o numero %d que estava na posicao %d de B\n", i, B->item[j].key, j);
        j++;
    }
    A->last = A->last + B->last;
}

void imprime(TADLista *A){
    for (int i = A->first; i< A->last; i++){
        printf("[%d] = %d\n", i, A->item[i].key);
    }
}


int main()
{
    TADLista A, B;
    printf("linha 21\n");

    A.first = 0;
    A.last = 5;
    printf("O LAST EH%d\n", A.last);


    A.item[0].key = 0;
    A.item[1].key = 1;
    A.item[2].key = 2;
    A.item[3].key = 3;
    A.item[4].key = 4;

    imprime(&A);


    B.first = 0;
    B.last = 5;

    B.item[0].key = 5;
    B.item[1].key = 6;
    B.item[2].key = 7;
    B.item[3].key = 8;
    B.item[4].key = 9;

    concatena(&A, &B);

    imprime(&A);

    return 0;//nao remova
}
