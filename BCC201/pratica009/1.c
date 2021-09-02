/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 1*/

#include <stdio.h>

int main(){
	int n=0,i=2;
	do{
		printf("Digite o valor de n, tal que n>:2 \n");
		scanf("%d",&n);
	}while (n<2);
	int f[n];
	f[0]=1;
	f[1]=1;
	printf("SEQUÊNCIA DE FIBONACCI: %d DÍGITOS\n",n);
	printf("%d, %d, ", f[0], f[1]);
	while(i<n){
		f[i]= f[i-1] + f[i-2];
		printf("%d, ",f[i]);
		i++;
	}
	printf("\n");
	

	return 0;
}