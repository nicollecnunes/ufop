#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	int *vetor;
	int n, movimentos;

	while(scanf("%d", &n), n){
		vetor = alocaVetor(vetor, n);
		preenche(vetor, n);
		//printf("preenchido\n");
		movimentos = 0;
		//printf("Valor de N == %d\n", n);
		ordenacao(vetor, n, &movimentos);
		//printf("qtd de movimentos: %d", movimentos);
		vencedor(movimentos);
		desalocaVetor(vetor);
	}

	return 0;
}
