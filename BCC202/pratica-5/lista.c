#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista) { //ok
	pLista->pPrimeiro = (TCelula*) malloc (sizeof (TCelula));
	pLista->pUltimo = pLista->pPrimeiro;
	pLista->pPrimeiro->pProx = NULL;

}

//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) { //ok
	return (pLista->pPrimeiro == pLista->pUltimo);
}

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x) {

	pLista->pUltimo->pProx = (TCelula*)malloc(sizeof(TCelula));
	pLista->pUltimo = pLista->pUltimo->pProx;
	pLista->pUltimo->item = x;
	pLista->pUltimo->pProx = NULL;

	return 1;
}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {
	/*if ( TLista_EhVazia ( pLista )){
		return 0;
	}

	TCelula *pAux;

	pAux = pLista->pPrimeiro->pProx;
	pAux = pLista->pPrimeiro->pAnt;

	*pX = pAux->item;

	pLista->pPrimeiro->pProx = pAux-> pProx;
	pLista->pPrimeiro->pAnt = pAux-> pAnt;

	free (pAux);
    pLista->TAM--;

    return 1;*/

}

// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista) {
	TCelula *atual;
	atual = pLista->pPrimeiro->pProx;

    while(atual != pLista->pUltimo) {
        printf("%s\n", atual->item.nome);
        atual = atual->pProx;
    }

    printf("%s\n", atual->item.nome);
}

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {
//preencher
}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2){
	TCelula *atual;
	atual = pLista2->pPrimeiro->pProx;


    while(atual != pLista2->pUltimo) {
    	TLista_InsereFinal(pLista1, atual->item);
        atual = atual->pProx;
    }
    TLista_InsereFinal(pLista1, atual->item);
}

// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str){
	TCelula *aux, *aux2;
	aux = pLista1->pPrimeiro->pProx;
	aux2 = aux->pProx;

    while((strcmp(str, aux->pProx->item.nome)!=0)){
    	TLista_InsereFinal(pLista1, aux->item);
    	aux = aux->pProx;
    	aux2 = aux2->pProx;
    }
    
    aux->pProx = pLista2->pPrimeiro->pProx;


    pLista2->pUltimo->pProx = aux2;
    pLista1->pUltimo = pLista2->pUltimo;

 
    while(aux2->pProx!=NULL){
    	TLista_InsereFinal(pLista1, aux2->item);
    	aux2 = aux2->pProx;
    }

    TLista_Imprime(pLista1);

}
