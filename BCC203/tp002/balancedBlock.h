#ifndef BALANCED_BLOCK_H
#define BALANCED_BLOCK_H

#include <stdio.h>
#include "quickSortInterno.h"

void mainBlock(Aluno *v1, FitasPrimeiroMetodo *fitas, int quantidade, Analise *a);

void readBlocks(Aluno *v1, int pointer, Analise *a);

void ordenateBlocks(Aluno *v1, Analise *a);

void preencheFitasBlocosPrimeiroMetodo(Aluno *v1, FitasPrimeiroMetodo *fitas, int quantidade, Analise *a);

#endif