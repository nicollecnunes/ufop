#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int info;
}TADItem;

typedef struct{
    struct TADCelula *prev;
    struct TADCelula *next;
    TADItem item;
}TADCelula;

typedef struct{
    TADCelula *first;
    TADCelula *last;
}TADListaD;

void iniVazia(TADListaD *A){
    A->first = (TADCelula *) malloc(sizeof(TADCelula));
    A->last = (TADCelula *) malloc(sizeof(TADCelula));

    A->first->prev = NULL;
    A->last->next = NULL;
    A->first->next = A->last->next;
    A->last->prev = A->first->prev;
}

int ehVazia(TADListaD *A){
    if (A->first->next == A->last->next){
        printf("é vazia\n");
        return 0;
    }
    printf("nao e\n");
    return 1;

}

void inFirst(TADListaD *A, int x){
    TADCelula *novo = (TADCelula *) malloc(sizeof(TADCelula));
    novo->item.info = x;
    novo->next = A->first->next;
    novo->prev = NULL;
    A->first->prev = novo->prev;
}

void imprime(TADListaD *A){
    while(0<1){
        if(A->last->next == NULL){
            break;
        }
        printf("%d\n", A->first->next->item.info);
    }
}

int main(){

    TADListaD A;
    
    iniVazia(&A);
    ehVazia(&A);
    inFirst(&A, 5);
    imprime(&A);

    return 0;
}
