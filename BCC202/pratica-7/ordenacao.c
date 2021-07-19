#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
TipoAluno *alocaAlunos(TipoAluno *alunos, int n){
	for (int i = 0; i < n; i++){
   		alunos = malloc (n * sizeof (TipoAluno)) ;
	}
	return alunos;
}

//Manter como especificado
TipoAluno *desalocaAlunos(TipoAluno *alunos){
	free(alunos);
	return alunos;
}

void ordena(TipoAluno *alunos, int n){
	char aux[20];
	int j, i =0, r;
	//printf("valor de N:%d",n);


	for (i = 0; i < n; i++){
		for (j = i + 1; j<n; j++){
			r = strcmp(alunos[i].nome, alunos[j].nome);
			if(r > 0){
				//printf("%s é menor que %s\n",alunos[i].nome, alunos[j].nome );
				strcpy(aux, alunos[i].nome);
				strcpy(alunos[i].nome, alunos[j].nome);
				strcpy(alunos[j].nome, aux);
			}
			//printf("i = %d  | j = %d", i,j);
		}
		//printf("i = %d  | j = %d", i,j);
	}
	//printf("linha 33\n");
	//print(alunos, n);
}


void preenche(TipoAluno *alunos, int n){
 	for (int i = 0; i <n; i++){
  		scanf("%s", alunos[i].nome);
  		//printf("lido o aluno %s\n", alunos[i].nome);
	}
}


void print(TipoAluno *alunos, int k){
	//printf("iniciando impressao");
	puts(alunos[k-1].nome);

}

