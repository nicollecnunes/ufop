#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
int *alocaVetor(int *vetor, int n){
	for (int i = 0; i < n; i++){
   		vetor = malloc (n * sizeof (int)) ;
	}
	return vetor;
}

//Manter como especificado
int *desalocaVetor(int *vetor){
	free(vetor);
	return vetor;
}

void ordenacao(int *vetor, int n, int *movimentos){
	*movimentos = 0;
	for (int i = 0; i <n; i++){
  		for (int j = i + 1; j<n; j++){
  			//printf("comparando %d com %d \n", vetor[i], vetor[j]);
  			if (vetor[i] > vetor[j]){
  				*movimentos = *movimentos + 1;
  				//printf("como é maior, soma 1 em mov, que agora são %d\n", *movimentos);
  			}

  		}
  		
	}

}

void preenche(int *vetor, int n){
 	for (int i = 0; i <n; i++){
  		scanf("%d", &vetor[i]);
  		//printf("lido o numero %d na posição %d\n", vetor[i], i+1);
	}
}


void vencedor(int movimentos){
	if(movimentos%2==0){//mov par
		printf("Carlos\n");
	}else{//mov impar
		printf("Marcelo\n");
	}
}