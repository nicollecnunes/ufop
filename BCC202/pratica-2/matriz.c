#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>

void lerOrdem(int *ordem){
	//printf("lendo a ordem\n");
	scanf("%d", ordem);
    getchar();

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
	int i, j, aux=1;
	double soma=0;
	int v = ordem/2 - 1;
	for (i=0; i<v; i++){
		for(j=i+1; j<ordem-aux; j++){
			soma = M[i][j] + soma;
			//printf("SOMANDO o valor %.2lf na posicao %d %d.... deu %.2lf\n", M[i][j], i, j, soma);
		}
		aux = aux + 1;
	}
	return soma;

}

double media(double resultado, int ordem){
	int i, j,aux=1, qtd=0;
	int v = ordem/2 - 1;
	for (i=0; i<v; i++){
		for(j=i+1; j<ordem-aux; j++){
			qtd = qtd +1;
		}
		aux = aux + 1;
	}
	
	resultado = resultado / qtd;
	//printf("A DIVISAO FOI POR %d e a ordem era %d\n", qtd, ordem);
	return resultado;

}

void printResultado(double resultado){
	printf("%.1lf\n", resultado);
}
