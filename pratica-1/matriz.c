#include "matriz.h"
#include<stdio.h>

void lerOperacao(char *operacao){
	scanf("%c", &O[0]);
}

void lerMatriz(double M[][12]){
	int i,j;
	for (i=0; i<12; i++){
    	for (j=0; j<12; j++){
    		scanf("%lf",&M[i][j]);
    	}   	
	}
}

double somaMatriz(double M[][12]){
	int i, j, aux = 0;
	for (i=0; i<5; i++){
		for(j=i+1; j<11-aux; j++){
			soma = M[i][j] + soma;
		}
		aux = aux + 1;
	}
	return soma;

}

double media(double resultado){
	double media = resultado/30;
	return media;
}

void printResultado(double resultado){
	printf("%.1lf\n", resultado);
}
