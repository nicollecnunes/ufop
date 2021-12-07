#ifndef QUICKSORTEXTERNO_H
#define QUICKSORTEXTERNO_H

#include "Util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHOAREA 20
#define FALSE 0
#define TRUE 1

void quickSortExterno(FILE **arqLi, FILE **arqEi, FILE **arqLEs, int esq, int dir);

void leSuperior(FILE **arqLEs, Aluno *ultimoLido, int *ls, short *ondeLer);

void leInferior(FILE **arqLi, Aluno *ultimoLido, int *li, short *ondeLer);

void inserirArea(Aluno *area, Aluno *ultimoLido, int *nArea);

void escreveMax(FILE **arqLEs, Aluno *R, int *es);

void escreveMin(FILE **arqEi, Aluno *R, int *ei);

void retiraMax(Aluno *area, Aluno *R, int *nArea);

void retiraMin(Aluno *area, Aluno *R, int *nArea);

void particao(FILE **arqLi, FILE **arqEi, FILE **arqLEs, Aluno *area, int esq, int dir, int *i, int *j);

void criaAreaVazia(Aluno *area);

void insereItem(Aluno ultimoLido, Aluno *area);

int obterNumCelulasOcupadas(Aluno *area);

void retiraUltimo(Aluno *area, Aluno *R);

void retiraPrimeiro(Aluno *area, Aluno *R);

void imprimirArea(Aluno *area);

#endif






