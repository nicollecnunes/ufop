#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>

void lerOrdem(int *ordem){

}

//manter como especificado
double **alocaMatriz(double **M, int ordem){
	int i;
	M = malloc (ordem * sizeof (double*)) ;
	for (i=0; i < ordem; i++){
   		M[i] = malloc (ordem * sizeof (double)) ;
	}
	return M;

}

//manter como especificado
double **desalocaMatriz(double **M, int ordem){
	int i;
	for (i=0; i <ordem; i++)
	   free (M[i]);

	free (M) ;
	return M;

}

//manter como especificado
void lerOperacao(char *operacao){
	scanf("%c", operacao);

}

void lerMatriz(double **M, int ordem){
	int i, j;
	for (i=0; i<ordem; i++){
    	for (j=0; j<ordem; j++){
    		scanf("%lf",&M[i][j]);
    	}   	
	}

}

double somaMatriz(double **M, int ordem){
	int i, j, aux=1, soma;
	int v = ordem/2 - 1;
	for (i=0; i<v; i++){
		for(j=i+1; j<ordem-aux; j++){
			soma = M[i][j] + soma;
		}
		aux = aux + 1;
	}
	return soma;

}

double media(double resultado, int ordem){
	ordem = ordem * 2.5;
	resultado = resultado / ordem;
	return resultado;

}

void printResultado(double resultado){
	printf("%.1lf\n", resultado);
}
