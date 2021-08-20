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


void mergesort(long long *vetor, int l, int r) {
	int m;
	if(l < r) {
		m = (l + r) / 2;
		mergesort(vetor, l, m);
		mergesort(vetor, m+1, r);
		merge(vetor, l, m, r);
	}
}


void merge(long long *vetor, int l, int m, int r) {
	int size_l = m - l + 1;
	int size_r = r - m;


	long long *vet_l = malloc (size_l * sizeof (long long)) ;
	long long *vet_r = malloc (size_r * sizeof (long long)) ;


	for(int i=0; i<size_l; i++){
		vet_l[i] = vetor[i+l];
	}
	for(int j=0; j<size_r; j++){
		vet_r[j] = vetor[m + j + 1];
	}

	int i=0;
	int j=0;


	for (int k=l; k<=r; k++){
		if(i==size_l){
			vetor[k] = vet_r[j++];
		}else if(j ==  size_r){
			vetor[k] = vet_l[i++];
		}else if(vet_l[i] <= vet_r[j]){
			vetor[k] = vet_l[i++];
		}else{
			vetor[k] = vet_r[j++];
		}
	}

	free(vet_l);
	free(vet_r);
}

void ordenacao(long long *vetor, int n){
	mergesort(vetor, 0, n-1);
}