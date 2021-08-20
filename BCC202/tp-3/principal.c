#include "buscabinaria.h"
#include <stdio.h>

int main(){

	int n = 1, a = 1;
	long long *vetor, areaTiras;

	while(0<1){
		areaTiras = 0;

		scanf("%d", &n);
		printf("\n\nLido N == %d\n", n);

		vetor = alocaVetor(vetor, n);

		scanf("%d", &a);
		printf("Lido A == %d\n", a);

		if((a == 0) || (n == 0)){
			break;
		}

		for(int i = 0; i<n; i++){
			printf("FOR [%d/%d]\n", i+1, n);

			scanf("%lld", &vetor[i]);
			printf("Lido CHAVE[%d] == %lld\n", i, vetor[i]);

			areaTiras = areaTiras + vetor[i];
			printf("AREA TIRAS: %lld\n", areaTiras);

		}

		ordenacao(vetor, n);

		if(areaTiras < a){
			printf("-.-\n");
		}else if(areaTiras == a){
			printf(":D\n");
		}else{
			printf("...\n");
		}

		vetor = desalocaVetor(vetor);
	}



	return 0;
}