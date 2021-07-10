#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*typedef struct {
    char key;
} Item;

typedef struct celula {
	Item item;
	struct celula *pProx;
} Celula;

typedef struct {
    Celula *pHead;
} Pilha;
*/

// Inicia as variaveis da pilha
void Pilha_Inicia(Pilha *pilha) {
	pilha->pHead = (Celula *) malloc(sizeof(Celula));
	pilha->pHead->pProx = NULL; //sem lixo
	pilha->tamanho = 0;
}

//Retorna se a pilha esta vazia
int Pilha_EhVazia(Pilha *pilha) {
	if (pilha->tamanho == 0){
        return 1;
    }else{
        return 0;
    }
}

// Insere um item no topo da pilha
int Pilha_Push(Pilha *pilha, Item item) {
	Celula *new = (Celula *) malloc(sizeof(Celula));
	new->item = item;

	Celula *aux = pilha->pHead;

	for (int i = 0; i<pilha->tamanho; i++){
		aux = aux ->pProx;
	}

	aux-> pProx = new;
	new -> pProx = NULL;

	pilha->tamanho = pilha->tamanho + 1;
	printf("foi adicionado o item %s \n", new->item.key);
	
	return 1;
}

// Retira o item do topo da pilha
int Pilha_Pop(Pilha *pilha, Item *item) {
	if (Pilha_EhVazia(pilha)){
        return 0;
    }else{
    	Celula *aux = pilha->pHead;
		Celula *aux2;
    	for (int i = 0; i<pilha->tamanho; i++){
			aux = aux ->pProx;
		}
		aux2 = aux;
		free(aux);
		aux2->pProx = NULL;
		return 1;
		printf("foi removido o item %s \n", item->key);
    }
}

//Remove cada elemento de uma pilha e libera a memória
void Pilha_Esvazia(Pilha *pilha) {
	Celula *aux = pilha->pHead;
	Celula *aux2;

	while(aux != NULL){
		aux2 = aux->pProx;
		free(aux);
		aux = aux2;
	}

}

void TLista_Imprime(Pilha *pilha) {
	Celula *atual;
	atual = pilha->pHead->pProx;

	for (int i = 0; i<pilha->tamanho; i++){
		printf(" - %s ", atual->item.key);
		atual = atual->pProx;
	}
	printf("%s \n", atual->item.key);
}




/*
Celula *aux = pilha->pheado->prox
int tamanho  = 0;
while(aux!=NULL){
	tamanho ++;
	aux = aux ->pprox;
} o
*/