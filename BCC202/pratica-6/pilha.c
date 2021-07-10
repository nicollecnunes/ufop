#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da pilha
void Pilha_Inicia(Pilha *pilha) {
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
	if(pilha->tamanho < MAX){
        pilha->items[pilha->tamanho] = item; //recebe o item no final
        pilha->tamanho = pilha->tamanho + 1;
        printf("foi adicionado o item %d\n", item.key);
        return 1;
    }else{
        return 0;
    }  
}

// Retira o item do topo da pilha
int Pilha_Pop(Pilha *pilha, Item *item) {
	if (TPilha_EhVazia(pilha)){
        return 0;
    }else{
        (*item) = pilha->items[pilha->tamanho - 1]; //recebe o ultimo
        pilha->tamanho = pilha->tamanho - 1; //atualiza o tamanho
        printf("foi removido o item %d\n", item->key);
        return 1;
    }
}

//Remove cada elemento de uma pilha e libera a memória
void Pilha_Esvazia(Pilha *pilha) {

	for (int i=0;i<pilha->tamanho;i++) {
        free(pilha->items[i].key);
    }
}
