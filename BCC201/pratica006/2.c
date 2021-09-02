/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 2*/

#include <stdio.h>
#include <stdlib.h>

int ehprimo(int n);
int ehprimo(int n){
	int i = 1;
	int div = 0;
	while (i<=n){
		if(n%i==0){
			div = div +1;
		}
		i = i+1;
	}
	if (div ==2){
		return 1;
	}else{
		return 0;
	}
	
}

int main(){
	int n;
	printf("Digite o número: \n");
	scanf("%d",&n);
	if (ehprimo(n)==0){
		printf("%d não é primo.", n);
	}else{
		printf("%d é primo.", n);
	}

	return 0;
}