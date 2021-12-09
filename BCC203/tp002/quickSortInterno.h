#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Util.h"

// FUNÇÕES AUXILIARES

void escolhaPivoMediana(Aluno *vetor, int tamanho_vetor);


void troca(Aluno *v, int x, int y);
void imprimir(Aluno *v, int tam);

// INSERTIONSORT
void insertionSort(Aluno *v, int esquerda, int direita, Analise *a);

// PIVO MEDIANA
void quickSort_mediana(Aluno *v, int esquerda, int direita, Analise *a);
void pivo_mediana(Aluno *v, int esquerda, int direita, Analise *a);
int particao_mediana(Aluno *v, int esquerda, int direita, Analise *a);

