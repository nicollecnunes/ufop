#include "buscabinaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int *alocaVetor(int *vetor, int n){
	vetor = (int *) malloc (n * sizeof(int));
	return vetor;
}

int *desalocaVetor(int *vetor){
	free(vetor);
	return vetor;
}

double AreaAcima(int *vetor, double meio, int n){
	double areaAcima = 0;
	for(int j = 0; j < n; j++){
			if(vetor[j] > meio){
				areaAcima = areaAcima + (vetor[j] - meio);
			}
	}

	return areaAcima;
}

double BuscaBinaria(int *vetor, int a, int n){
	double meio;
	double esq = 0;
	double dir = vetor[n-1];

	while(esq <= dir){
		meio = (esq + dir) / 2;
		double area = AreaAcima(vetor, meio, n);
		
		if (area > a){
			esq = meio + 0.000001;
		}else{
			dir = meio - 0.000001;
		} 
	}

	return meio;
}

void mergesort(int *vetor, int l, int r) {
	int m;
	if(l < r) {
		m = (l + r) / 2;
		mergesort(vetor, l, m);
		mergesort(vetor, m+1, r);
		merge(vetor, l, m, r);
	}
}


void merge(int *vetor, int l, int m, int r) {
	int size_l = m - l + 1;
	int size_r = r - m;


	int *vet_l = malloc (size_l * sizeof (int)) ;
	int *vet_r = malloc (size_r * sizeof (int)) ;


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

void ordenacao(int *vetor, int n){
	mergesort(vetor, 0, n-1);
}