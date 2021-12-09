#include "heap.h"

#ifndef SUBBLOCK_H
#define SUBBLOCK_H

void mainSubBlock(AlunoMarcas *v1, FitasPrimeiroMetodo *fitas, int quantidade, Analise *a);

void readInitialBlock(AlunoMarcas *v1, Analise *a);

void readNextAluno(Aluno next, int pointer, Analise *a);

int isAllMarked(AlunoMarcas *v1, Analise *a);

void compareNewAluno(AlunoMarcas *v1, AlunoMarcas oldAluno, Analise *a);

#endif