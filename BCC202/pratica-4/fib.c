#include "fib.h"
#include<stdio.h>
#include<stdlib.h>

long long fibonacci(int n, TADfib *f, int i){
	long long aux;
	if (n <= 1){
    	return n;
	}
 	f[i].chamadas = f[i].chamadas +2;
 	aux = fibonacci(n - 1, f,i) + fibonacci(n - 2, f,i);
  	return aux;
}

void lerQuantidade(int *qtd){
	scanf("%d", qtd);
    getchar();
    //printf("quantidade lida: %d\n",*qtd);
}

TADfib *alocaFib(TADfib *f, int qtd){
	int i;
	for (i=0; i < qtd; i++){
   		f = malloc (qtd * sizeof (TADfib)) ;
	}
	return f;
}

//Manter como especificado
TADfib *desalocaFib(TADfib *f){
	free (f);
	return f;
}


void lerCasos(TADfib *f, int qtd){
  int i;
  for (i=0; i <qtd; i++){
  	scanf("%d", &f[i].n);
  	f[i].chamadas=0;
  	f[i].resultado = fibonacci(f[i].n, f,i);
  }
}


void imprimir(TADfib *f, int qtd){
	//fib(5) = 14 chamadas = 5
	int i;
	for (i=0; i<qtd; i++){
		printf("fib(%d) = %lld chamadas = %lld\n", f[i].n, f[i].chamadas, f[i].resultado);
	}

}