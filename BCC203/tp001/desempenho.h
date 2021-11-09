#ifndef desempenho_h
#define desempenho_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
  int transferencias0; //pre
  int transferencias1; //pos

  int comparacoes0;
  int comparacoes1;

  double tempo0;  
  double tempo1;

  clock_t hora0;
  clock_t hora1;
} Desempenho;


void inicializarAnalise(Desempenho *d);

void iniciaTimer(Desempenho *d);
void paraTimer(Desempenho *d);

void attTransferencias0(Desempenho *d, int n);
void attTransferencias1(Desempenho *d, int n);

void attComparacoes0(Desempenho *d, int n);
void attComparacoes1(Desempenho *d, int n);

void attTempo0(Desempenho *d);
void attTempo1(Desempenho *d);

void resultadoDesempenho(Desempenho *d);


#endif