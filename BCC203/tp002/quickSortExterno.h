#ifndef QUICKSORTEXTERNO_H
#define QUICKSORTEXTERNO_H

#include "Util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define TAMANHOAREAPIVO 10
#define FALSE 0
#define TRUE 1

typedef struct area
{
    Aluno *areaAlunos;
    int tamanho;
} Area;


void quickSortExterno(FILE **arqLi, FILE **arqEi, FILE **arqLEs, int esq, int dir, Analise *a);

void leSuperior(FILE **arqLEs, Aluno *ultimoLido, int *ls, short *deveLerSuperior, Analise *a);

void leInferior(FILE **arqLi, Aluno *ultimoLido, int *li, short *deveLerSuperior, Analise *a);

void inserirAluno(Area *area, Aluno *ultimoLido, int *nAluno, Analise *a);

void escreveSup(FILE **arqLEs, Aluno R, int *es, Analise *a);

void escreveInf(FILE **arqEi, Aluno R, int *ei, Analise *a);

void retiraMax(Area *area, Aluno *R, int *nAluno, Analise *a);

void retiraMin(Area *area, Aluno *R, int *nAluno, Analise *a);

void particao(FILE **arqLi, FILE **arqEi, FILE **arqLEs, Area area, int esq, int dir, int *i, int *j, Analise *a);

void criaAlunoVazia(Aluno *aluno);

void insereItem(Aluno ultimoLido, Area *area, Analise *a);

void retiraUltimo(Area *area, Aluno *R, Analise *a);

void retiraPrimeiro(Area *area, Aluno *R, Analise *a);

#endif
