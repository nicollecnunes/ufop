#include "buscabinaria.h"
#include <stdio.h>

int main(){

	int n = 1, a = 1;
	long long *vetor, areaTiras;

	while((n=!0) && (a!=0)){
		areaTiras = 0;

		scanf("%d", &n);
		printf("\n\nLido N == %d\n", n);

		vetor = alocaVetor(vetor, n);

		scanf("%d", &a);
		printf("Lido A == %d\n", a);

		for(int i = 0; i<n; i++){
			printf("FOR [%d/%d]\n", i+1, n);

			scanf("%lld", &vetor[i]);
			printf("Lido CHAVE[%d] == %lld\n", i, vetor[i]);

			areaTiras = areaTiras + vetor[i];
			printf("AREA TIRAS: %lld\n", areaTiras);

		}
		if(areaTiras < a){
			printf("-.-\n");
		}else if(areaTiras == a){
			printf(":D\n");
		}else{
			printf("check\n");
		}

		vetor = desalocaVetor(vetor);
	}



	return 0;
}