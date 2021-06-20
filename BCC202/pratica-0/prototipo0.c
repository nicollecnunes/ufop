#include <stdio.h>
int main(){

    double M[12][12];
    char O[0];
    int aux = 0, i, j;
    double soma = 0;
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

    return 0;
}
