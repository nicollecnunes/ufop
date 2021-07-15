#include "ordenacao.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void listaInicia(TLista *lista) {
	lista->pHead = (TCelula *) malloc(sizeof(TCelula));
	lista->pTail = lista->pHead;
	lista->pHead->pProx = NULL; //sem lixo
	lista->tamanho = 0;
}

int listaEhVazia(TLista *lista) {
	if (lista->tamanho == 0){
        return 1;
    }else{
        return 0;
    }
}

void listaIncludeAntes(TLista *lista, TPais pais, char *str){
	TCelula *novo = (TCelula *) malloc(sizeof(TCelula));
	novo -> pais = pais;


	TCelula *aux, *aux2;
	aux = lista->pHead->pProx;
	aux2 = aux->pProx;

	if(strcmp(str, aux->pais.nome)==0){
		novo->pProx = aux;
		lista->pHead->pProx = novo;
	}else{
		while(0<1){
			if(strcmp(str, aux2->pais.nome)==0){
				novo->pProx = aux2;
				aux->pProx = novo;
				break;
			}  		
   		 }
	}
	lista->tamanho = lista->tamanho + 1;
}

void listaIncludeFinal(TLista *lista, TPais pais){
	TCelula *novo = (TCelula *) malloc(sizeof(TCelula));
	novo->pais = pais;

	TCelula *aux = lista->pHead;

	for (int i = 0; i<lista->tamanho; i++){
		aux = aux ->pProx;
	}

	aux-> pProx = novo;
	novo -> pProx = NULL;

	lista->tamanho = lista->tamanho + 1;
	
}

void ordenaLista(TLista *lista, TPais *novo){
    TCelula *atual;
	atual = lista->pHead->pProx;

    for(int i= 0; i<lista->tamanho; i++) {
    	if(atual->pais.ouro < novo->ouro){
    		listaIncludeAntes(lista, *novo, atual->pais.nome);
    	}else if(atual->pais.ouro < novo->ouro){
    		listaIncludeFinal(lista, *novo);
    	}else{
    		if(atual->pais.prata < novo->prata){
    			listaIncludeAntes(lista, *novo, atual->pais.nome);
    		}else if(atual->pais.prata < novo->prata){
    			listaIncludeFinal(lista, *novo);
    		}else{
    			if(atual->pais.bronze < novo->bronze){
    				listaIncludeAntes(lista, *novo, atual->pais.nome);
    			}else if(atual->pais.bronze < novo->bronze){
    				listaIncludeFinal(lista, *novo);
    			}
    		}
    	}
        atual = atual->pProx;
    }
     
}



void insertionOuro(Tlista **lista, TPais *pais){
    TCelula *atual, *novo, *anterior;
    int x = pais->ouro;

    novo = (TCelula *) malloc(sizeof(TCelula));

    atual = *p;
    anterior = NULL;

    novo->pais.ouro = x;

    if(atual == NULL){
        novo->prox = NULL;
        *p = novo;
    } else{
        while(atual != NULL && atual->valor < num){
            anterior = atual;
            atual = atual->prox;
        }

        novo->prox = atual;

        if(anterior == NULL){
            *p = novo;
        } else{
            anterior->prox = novo;
        }
    }
}





void TLista_Imprime(TLista *lista) {
	TCelula *atual;
	atual = lista->pHead->pProx;

	for (int i = 0; i<lista->tamanho; i++){
		printf(" - %s ", atual->pais.nome);
		atual = atual->pProx;
	}
	printf("\n");
}

