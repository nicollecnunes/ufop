/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 3*/

#include <stdio.h>

int main(){
	int n=51,i=0,a=0;
	while(n>50){
		printf("Digite o valor de N, tal que N<=50\n");
		scanf("%d",&n);
	}
	int v[n];
	while(i<n){
		printf("Digite o valor da %dª posição\n", i+1);
		scanf("%d",&v[i]);
		i++;
	}
	i=0;
	

	while (i<=n){
		while (a<v[i]){
			printf("*");
			a++;
		}
		a=0;
		printf("\n");
		i++;
	}
	return 0;
}