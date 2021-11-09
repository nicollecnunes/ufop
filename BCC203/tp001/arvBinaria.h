#ifndef arvBinaria_h
#define arvBinaria_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sequencial.h"
#include "desempenho.h"

typedef TRegistro TItem;

typedef struct
{
    TItem item;
    int esq;
    int dir;
} TNo;

#include "arvBinaria.h"

TRegistro *rCriarArray(int n);

TNo arvBinariaCriarNo(TItem *item);

int arvBinariaExterna(TItem *itemPesquisa, int situacao, Desempenho *d);

int arvBinariaInserir(FILE *arv, TItem *item, int pos, Desempenho *d);

int arvBinariaOrdenadaInserir(FILE *arv, TItem *item, int pos, Desempenho *d);

int arvBinariaPesquisa(FILE *arv, TItem *itemPesq, Desempenho *d);

void arvBinariaPrint();

#endif