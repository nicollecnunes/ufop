#include "corretor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct subm {
  char id[];
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

void lerSubm(TADsubm *S, int n){
  int i;
  for (i=0; i <n; i++){
  	scanf("%c", S[i].id);
  	scanf("%d", &S[i].t);
  	scanf("%s", D[i].julg);
  	printf("lida a submissao [%d], letra: %s, tempo: %d, julgamento: %s\n",i, S[i].id, S[i].t, S[i].julg);
  }
}