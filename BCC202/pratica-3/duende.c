#include "duende.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct duende {
  char nome[20];
  int idade;
  int escalado;
};

struct time {
  char lider[20];
  int idadeLider;

  char entregador[20];
  int idadeEntregador;

  char piloto[20];
  int idadePiloto;
};

void lerQuantidade(int *qtd){
	scanf("%d", qtd);
    getchar();
    printf("quantidade lida: %d\n",*qtd);
}
//Manter como especificado
TADduende *alocaDuendes(TADduende *D, int qtd){
	int i;
	for (i=0; i < qtd; i++){
   		D = malloc (qtd * sizeof (TADduende)) ;
	}
	return D;
}

//Manter como especificado
TADtime *alocaTimes(TADtime *T, int qtd){
	int i;
	for (i=0; i < qtd; i++){
   		T = malloc (qtd * sizeof (TADtime)) ;
	}
	return T;
}

//Manter como especificado
TADduende *desalocaDuendes(TADduende *D){
	free (D);
	return D;
}

//Manter como especificado
TADtime *desalocaTimes(TADtime *T){
	free (T);
	return T;
}

//Manter como especificado
void lerDuendes(TADduende *D, int qtd){
  int i;
  for (i=0; i <qtd; i++){
  	scanf("%s", D[i].nome);
  	scanf("%d", &D[i].idade);
  	D[i].escalado = 0; 
  	//printf("lido o doende [%d], nome: %s, idade: %d\n",i, D[i].nome, D[i].idade);
  }
}

//Manter como especificado
void escalarTimes(TADduende *D, TADtime *T, int qtd){
  int i, indice;
  //completar o XXX
  for (i=0; i<qtd/3; i++){
    indice = proximoMaisVelho(D, qtd);
    //printf("%do proximo mais velho tem %d anos\n", i+1, D[indice].idade);
    D[indice].escalado = 1; 
    strcpy(T[i].lider, D[indice].nome);
    T[i].idadeLider = D[indice].idade;
  }

  for (i=0; i<qtd/3; i++){
    indice = proximoMaisVelho(D, qtd);
    D[indice].escalado = 1; 
    //printf("%s foi escalado\n", D[indice].nome);

    strcpy(T[i].entregador, D[indice].nome);
    T[i].idadeEntregador = D[indice].idade;
  } 

   for (i=0; i<qtd/3; i++){
    indice = proximoMaisVelho(D, qtd);
    D[indice].escalado = 1; 

    strcpy(T[i].piloto, D[indice].nome);
    T[i].idadePiloto =D[indice].idade;;
  }
}

int proximoMaisVelho(TADduende *D, int qtd){
  int indice,i;
  for (i = 0; i<qtd; i++){
  	if (D[i].escalado == 0){
  		indice = i;
  		break;
  	}
  }
  for (i = 0; i < qtd; i++){
  	if (D[indice].idade < D[i].idade){
  		if (D[i].escalado == 0){
  			indice = i;
  		}
  	}
  }
  return indice;
}

//Manter como especificado
void printTimes(TADtime *T, int qtd){
	int i;
	for (i=0; i<qtd; i++){
		printf("Time %d\n", i+1);
		printf("%s %d\n", T[i].lider, T[i].idadeLider);
		printf("%s %d\n", T[i].entregador, T[i].idadeEntregador);
		printf("%s %d\n\n", T[i].piloto, T[i].idadePiloto);

	}

}
