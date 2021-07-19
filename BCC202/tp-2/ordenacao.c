#include "ordenacao.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct pais {
    char nome[50];
  	int ouro;
  	int prata;
  	int bronze;
};

void lerQuantidade(int *qtd){
	scanf("%d", qtd);
    getchar();
    //printf("quantidade lida: %d\n",*qtd);
}

TPais *alocaPaises(TPais *P, int qtd){
	for (int i = 0; i < qtd; i++){
   		P = malloc (qtd * sizeof (TPais)) ;
	}
	return P;
}

void lerLista(TPais *P, int qtd){
  for (int i = 0; i <qtd; i++){
  	scanf("%s", P[i].nome);
  	scanf("%d", &P[i].ouro);
  	scanf("%d", &P[i].prata);
  	scanf("%d", &P[i].bronze);
  	//printf("lido o pais [%d], nome: %s, ouro: %d, prata: %d, bronze: %d\n",i, P[i].nome, P[i].ouro,P[i].prata,  P[i].bronze);
  }
}

void ordenaTudo(TPais *P, int qtd){
	int max;
	TPais aux;

	for (int i=0; i<qtd; i++){
		max = i;
		for (int j=i+1; j<qtd; j++){
			if (P[max].ouro<P[j].ouro){
				max = j;
			}else if(P[max].ouro == P[j].ouro){
				if(P[max].prata < P[j].prata){
					max = j;
				}else if(P[max].prata == P[j].prata){
					if(P[max].bronze < P[j].bronze){
						max = j;
					}else if(P[max].bronze == P[j].bronze){
						if(strcmp(P[max].nome,P[j].nome) > 0){
							max = j;
						}

					}
				}

			}

		}
		aux = P[i];
		P[i] = P[max];
		P[max] = aux;

	}
}


void imprimePaises(TPais *P, int qtd){
	for (int i = 0; i<qtd; i++){
		printf("%s %d %d %d\n", P[i].nome, P[i].ouro, P[i].prata, P[i].bronze);
	}

}

TPais *desalocaPaises(TPais *P){
	free (P);
	return P;
}