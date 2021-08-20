#include "buscabinaria.h"
#include <stdio.h>

int main(){

	int n = 1, a = 1;
	int *vetor, areaTiras;
	double resultado;

	while(0<1){
		areaTiras = 0;

		scanf("%d", &n);
		vetor = alocaVetor(vetor, n);

		scanf("%d", &a);

		if((a == 0) || (n == 0)){
			break;
		}

		for(int i = 0; i<n; i++){
			scanf("%d", &vetor[i]);
			areaTiras = areaTiras + vetor[i];
		}

		ordenacao(vetor, n);

		if(areaTiras < a){
			printf("-.-\n");
		}else if(areaTiras == a){
			printf(":D\n");
		}else{
			resultado = BuscaBinaria(vetor, a, n);
			printf("%.4lf\n", resultado);
		}

		vetor = desalocaVetor(vetor);
	}



	return 0;
}