#ifndef sequencial_h
#define sequencial_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "desempenho.h"

typedef struct
{
  int indice;
  int chave;
} TIndice;

typedef struct
{
  int chave;
  long int dado1;
  char dado2[1000];
  char dado3[5000];
} TRegistro;

int busca_sequencial(int chave, TRegistro *registro, Desempenho *d, int situacao);

int calcula_tamanho_arquivo(Desempenho *d);

void gerar_tabela_indices(int n, TIndice *indices, Desempenho *d);

#endif