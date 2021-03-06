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

	int i, n;
	float *v, *novo;

	scanf("%d", &n);

	v = (float *) malloc(n * sizeof(float));

	for(i=0; i<=n; i++){
		printf("Digite V[%d]: ", i);
		scanf("%f", &v[i]);
	}

	printf("Fim da leitura de V. Chamando a função reverso\n");

	novo = reverso(n, v);

	printf("\nVetor V:\n");
	for (i = 0;i <=n; i++){
    	printf("V[%d] = %.2f\n",i, v[i]);
  	}

  	printf("\nVetor NOVO:\n");
	for (i = 0;i <=n; i++){
    	printf("Novo[%d] = %.2f\n",i, novo[i]);
  	}

	printf("Liberando o vetor V...\n");
	free(v);
	printf("Liberando o vetor NOVO...\n");
	free(novo);


	return 0;
}