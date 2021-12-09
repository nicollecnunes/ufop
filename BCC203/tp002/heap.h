#include "Util.h"

#ifndef HEAP_H
#define HEAP_H

void heapRefaz(AlunoMarcas *v, int esq, int dir, Analise *a);

void heapConstroi(AlunoMarcas *v, int n, Analise *a);

void heapSort(AlunoMarcas *v, int n, Analise *a);

#endif