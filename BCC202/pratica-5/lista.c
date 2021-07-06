#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista) {
	pLista -> pPrimeiro = NULL ;
	pLista -> pUltimo = NULL ;
}

//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) {
	return ( pLista -> pPrimeiro == NULL );
}

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x) {
	TCelula * novo = ( TCelula *) malloc ( sizeof ( TCelula ));

	novo -> Item = x;
	novo -> pProx = NULL ;
	if ( TLista_EhVazia ( pLista )) {
		pLista -> pPrimeiro = novo ;
		pLista -> pUltimo = novo ;
	} else {
		pLista -> pUltimo - > pProx = novo ;
		pLista -> pUltimo = novo ;
	}

}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {
	if ( TLista_EhVazia ( pLista )){
		return 0;
	}
	TCelula * pAux ;
	pAux = pLista - > pPrimeiro -> pProx ;
	* pX = pAux -> item ;
	pLista -> pPrimeiro -> pProx = pAux - > pProx ;
	free ( pAux );
	return 1;

}

// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista) {
	int i;
	for (i = pLista -> primeiro ; i < pLista - > ultimo ; i ++){
		printf ("%d\n", pLista -> item [i]. chave );
	}
}

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {
	for (int i=0; i<pLista1->pUltimo; i++){
		free(TCelula);
	}
	free(pLista);
//preencher
}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2){
	int j=0;
    for (int i = pLista1->pUltimo; i<(pLista1->pUltimo + pLista2->pUltimo); i++){
        pLista1->item[i].nome = pLista2->item[j].nome;
        printf("A na posicao [%d] recebe o nome %c que estava na posicao %d de B\n", i, pLista2->item[j].nome, j);
        j++;
    }
    pLista1->pUltimo = A->pUltimo + B->pUltimo;
}

// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str){
	TLista Aux;
	for (int i=0; i<pLista1->pUltimo; i++){
		Aux->item[i].nome = pLista1->item[i].nome;
        if(pLista1->item[i].nome == x){
            printf("%d esta na posição [%d]!\n", x, i);
            TLista_append(&Aux, &pLista2)
        }
    }

    for (int i=0; i<Aux->pUltimo; i++){
		pLista1->item[i].nome = Aux->item[i].nome;
    }
}
