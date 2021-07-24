#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	int *vetor;
	int n, movimentos;

	while(scanf("%d", &n), n){
		if(n == 0){
			break;
		}
		vetor = alocaVetor(vetor, n);
		preenche(vetor, n);
		ordenacao(vetor, n, &movimentos);
		//printf("qtd de movimentos: %d", movimentos);
		vencedor(movimentos);
		desalocaVetor(vetor);
	}

	return 0;
}
