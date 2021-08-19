#include "buscabinaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


long long *alocaVetor(long long *vetor, int n){
	vetor = (long long *) malloc (n * sizeof(long long));
	return vetor;
}

long long *desalocaVetor(long long *vetor){
	free(vetor);
	return vetor;
}

int VetorBusca(long long *vetor, long x, int TAM){
	return BuscaBinaria(vetor, 0, TAM-1, x);
}

int BuscaBinaria(long long *vetor, int esq, int dir, int x){
	int meio = (esq + dir) / 2;

	if((vetor[meio] != x) && (esq == dir)){
		return -1;
	}else if(vetor[meio] < x){
		return BuscaBinaria(vetor, meio+1, dir, x);
	}else if(vetor[meio] > x){
		return BuscaBinaria(vetor, esq, meio-1, x);
	}else{
		return meio;
	}
}