#ifndef ARVOREBESTRELA_H
#define ARVOREBESTRELA_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "arvBinaria.h"

#define MMestrela 10
#define Mestrela 5
#define ORDEM 4
#define STR1 1000
#define STR2 5000

typedef long TipoChaveEstrela;

typedef enum
{
    Interna,
    Externa
} TipoIntExtEstrela;

typedef struct TipoPaginaEstrela *TipoApontadorEstrela;

typedef struct TipoPaginaEstrela
{
    TipoIntExtEstrela Pt;
    union
    {
        struct
        {
            int ni;
            TipoChaveEstrela ri[MMestrela];
            TipoApontadorEstrela pi[MMestrela + 1];
        } U0;
        struct
        {
            int ne;
            int prox;
            TRegistro re[Mestrela];
        } U1;
    } UU;
} TipoPaginaEstrela;

void InicializaBEstrela(TipoApontadorEstrela *Arvore);

int PesquisaBEstrela(TRegistro *x, TipoApontadorEstrela Ap, Desempenho *d);

void InsereNaPaginaBEstrela(TipoApontadorEstrela Ap, int Registro, TipoApontadorEstrela ApDir, Desempenho *d);

int liberarArvoreBEstrela(TipoApontadorEstrela Ap);

void ImprimeBEstrela(TipoApontadorEstrela arvore);

int arvExternaBEstrela(TRegistro *Reg, int Situacao, int QuantidadeRegistros, Desempenho *d);

void insereBEstrela(TRegistro* Reg, TipoApontadorEstrela* Ap, Desempenho *d);

bool insereNaFolha (TRegistro* Reg, TipoApontadorEstrela NovaPagina, Desempenho *d);

void InsBEstrela(TRegistro* Reg, TipoApontadorEstrela Ap, short *cresceu, TRegistro *regRetorno, TipoApontadorEstrela *apRetorno, short *Cresceu_No, Desempenho *d);

#endif