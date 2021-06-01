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
		printf("lendo ele %d", i);
		scanf("%f", &v[i]);
	}

	printf("fim da leitira");

	novo = reverso(4, v);

	printf("vetor V:\n");
	for (i = 0;i < 5; i++){
    	printf("%.2f\n",v[i]);
  	}

  	printf("vetor NOVO:\n");
	for (i = 0;i < 5; i++){
    	printf("%.2f\n",novo[i]);
  	}

	free(v);
	free(novo);


	return 0;
}