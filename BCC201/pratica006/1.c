/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 1*/

#include <stdio.h>
#include <stdlib.h>

long long fato(int n);
long long fato(int n){
	int i = 1;
	long long r = 1;
	while (i<=n){
		r = r * i;
		i = i + 1;
	}
	return r;
}

int main(){
	int n;
	printf("Digite o número: \n");
	scanf("%d",&n);
	printf("FATORIAL DE %d = %lld \n", n, fato(n));

	return 0;
}