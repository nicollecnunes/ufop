#ifndef ARVOREB_H
#define ARVOREB_H

#include <stdlib.h>
#include <stdio.h>
#include "arvBinaria.h"
#include "desempenho.h"

#define M 2
#define MM (2 * M)

typedef struct TipoPagina *TipoApontador;

typedef struct TipoPagina
{
    short n;
    TRegistro r[MM];
    TipoApontador p[MM + 1];
} TipoPagina;

void Inicializa(TipoApontador *Arvore);

int Pesquisa(TRegistro *x, TipoApontador Ap, Desempenho *d);

int arvBExterna(TRegistro *reg, int quantidadeRegistros, Desempenho *d);

void Imprime(TipoApontador arvore, Desempenho *d);

void InsereNaPagina(TipoApontador Ap, TRegistro Reg, TipoApontador ApDir, Desempenho *d);

void Ins(TRegistro Reg, TipoApontador Ap, short *Cresceu, TRegistro *RegRetorno, TipoApontador *ApRetorno, Desempenho *d);

void Insere(TRegistro Reg, TipoApontador *Ap, Desempenho *d);

int liberarArvore(TipoApontador Ap);


#endif