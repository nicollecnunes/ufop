#include <stdio.h>
#include <stdlib.h>

int main()
{
    double **M;

    char O[0];
    int aux = 1, i, j, n;
    double soma = 0;

    scanf("%d", &n);
    getchar();
    printf("o numero n é %d", n);
	M = malloc (n * sizeof (double*)) ;
	for (i=0; i < n; i++)
   		M[i] = malloc (n * sizeof (double)) ;

    scanf("%c", &O[0]);
    printf("a operação é %c", O[0]);

    for (i=0; i<n; i++){
    	for (j=0; j<n; j++){
    		scanf("%lf",&M[i][j]);
    	}   	
	}

	int v = n/2 - 1;

	for (i=0; i<v; i++){
		for(j=i+1; j<n-aux; j++){
			soma = M[i][j] + soma;;
		}
		aux = aux + 1;
	}


	if(O[0]=='M'){
		soma = soma/30;
	}

	printf("%.1lf\n", soma);

	for (i=0; i <n; i++)
	   free (M[i]);

	free (M) ;
    return 0;
}

