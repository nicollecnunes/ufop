#include <stdio.h>
#include <stdlib.h>

float* reverso(int n, float *v){
	float *novo;
	int i, aux=0;
	novo = (float *) malloc(n * sizeof(float));

	for (i = n; i >=0; i--){ //para reverter
    	novo[aux] = v[i];
    	aux++;
  	}
	
  	return novo;
}

int main(){

	int i;
	float *v, *novo;

	v = (float *) malloc(5 * sizeof(float));

	for(i=0; i<5; i++){
		printf("Digite V[%d]: ", i);
		scanf("%f", &v[i]);
	}

	printf("Fim da leitura de V. Chamando a função reverso\n");

	novo = reverso(4, v);

	printf("\nVetor V:\n");
	for (i = 0;i < 5; i++){
    	printf("V[%d] = %.2f\n",i, v[i]);
  	}

  	printf("\nVetor NOVO:\n");
	for (i = 0;i < 5; i++){
    	printf("Novo[%d] = %.2f\n",i, novo[i]);
  	}

	printf("Liberando o vetor V...\n");
	free(v);
	printf("Liberando o vetor NOVO...\n");
	free(novo);


	return 0;
}