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

void insere(TADListaD *A, TADItem *X){
    TADCelula *novo = (TADCelula *) malloc(sizeof(TADCelula));

    novo->next = A->last->next;
    novo->prev = A->first->prev;

    A->first->next = novo->next;
    A->last->prev = novo->prev;
    novo->item = *X;
}
