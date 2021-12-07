#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Util.h"

// FUNÇÕES AUXILIARES
void sortear(int *v, int tam);
void escolherValores(int *v, int tam);
void preencher_vetor(int *vetor, int tam, int opcode);
void escolhaPivoMediana(Aluno *vetor, int tamanho_vetor);


void troca(Aluno *v, int x, int y);
void imprimir(Aluno *v, int tam);

// INSERTIONSORT
void insertionSort(Aluno *v, int esquerda, int direita);

// PIVO MEDIANA
void quickSort_mediana(Aluno *v, int esquerda, int direita);
void pivo_mediana(Aluno *v, int esquerda, int direita);
int particao_mediana(Aluno *v, int esquerda, int direita);

