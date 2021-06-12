#include "corretor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct subm {
  char id[1];
  int t;
  char julg[20];
};


void lerQuantidade(int *n){
	scanf("%d", n);
    getchar();
    printf("quantidade lida: %d\n",*n);
}

TADsubm *alocaSubm(TADsubm *S, int n){
	int i;
	for (i=0; i < n; i++){
   		S = malloc (n * sizeof (TADsubm)) ;
	}
	return S;
}


TADsubm *desalocaSubm(TADsubm *S){
	free (S);
	return S;
}

int testaCorreto(char julg[]){
	//printf("ENTRANDO COM: %s\n", julg);
	if (strcmp(julg, "correto") ==0){
		//printf("entrei no if!!!\n");
		return 1;
	}else{
		return 0;
	}
}

void lerSubm(TADsubm *S, int n, int *c){
  int i;
  //printf("c agora vale %d\n", *c);
  for (i=0; i <n; i++){
  	scanf("%c", S[i].id);
  	getchar();
  	scanf("%d", &S[i].t);
  	getchar();
  	scanf("%s", S[i].julg);
  	getchar();
  	//printf("LEVANDO PARA O TESTEEEEE: %s, \n",S[i].julg);;
  	//printf("lida a submissao [%d], letra: %s, tempo: %d, julgamento: %s\n",i, S[i].id, S[i].t, S[i].julg);
  	*c =  *c + testaCorreto(S[i].julg);
  	//printf("o trem agora vale %d\n",testaCorreto(S[i].julg));
  	//printf("c agora vale %d por causa do indice [%d]\n", *c, i);
  	;
  }
}

void printSaida(TADsubm *S, int n, int c){
	printf("corretos: %d", c);
}