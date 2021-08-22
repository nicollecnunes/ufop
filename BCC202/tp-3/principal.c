#include "buscabinaria.h"
#include <stdio.h>

int main(){

	int n, a, areaTiras, run = 1;
	int *vetor;
	run = inicializa(&n, &a);

	do{
		areaTiras = 0;
		vetor = alocaVetor(vetor, n);

		leitoresoma(vetor, n, &areaTiras);
		ordenacao(vetor, n);

		if(areaTiras < a){
			printf("-.-\n");
		}else if(areaTiras == a){
			printf(":D\n");
		}else{
			BuscaBinaria(vetor, a, n);
		}

		vetor = desalocaVetor(vetor);
		run = inicializa(&n, &a);

	}while(run);

	return 0;
}