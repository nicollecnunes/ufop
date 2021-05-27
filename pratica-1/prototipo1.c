#include <stdio.h>
int main()
{
    double **M;

    char O[0];
    int aux = 0, i, j, n;
    double soma = 0;

    scanf("%d", &n);
    M = (int**) malloc(sizeof(int*)* *n);
    for(i=0;i<*n;i++){
		M[i] = (int*) malloc(sizeof(int)* *n); 
	}

    scanf("%c", &O[0]);


    for (i=0; i<12; i++){
    	for (j=0; j<12; j++){
    		scanf("%lf",&M[i][j]);
    	}   	
	}

	for (i=0; i<5; i++){
		for(j=i+1; j<11-aux; j++){
			soma = M[i][j] + soma;
		}
		aux = aux + 1;
	}


	if(O[0]=='M'){
		soma = soma/30;
	}

	printf("%.1lf\n", soma);

	for(i=0;i<n;i++){
		free(M[i]);
	}
	free(M);

    return 0;
}

