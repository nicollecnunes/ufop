#include "ordenacao.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void lerQuantidade(int *qtd){
	scanf("%d", qtd);
    getchar();
    //printf("quantidade lida: %d\n",*qtd);
}

void lerLista(TLista *lista, int qtd){
	TPais x;

	for (int i = 0; i<qtd; i++){
		scanf("%s", x.nome);
		scanf("%d", &x.ouro);
		scanf("%d", &x.prata);
		scanf("%d", &x.bronze);
		listaIncludeFinal(lista, x);
		insertionOuro(lista, &x);
        insertionPrata(lista, &x);
        insertionBronze(lista, &x);
	}

}

void listaInicia(TLista *lista) {
	lista->pHead = (TCelula *) malloc(sizeof(TCelula));
	lista->pTail = lista->pHead;
	lista->pHead->pProx = NULL; //sem lixo
	lista->tamanho = 0;
}

int listaEhVazia(TLista *lista) {
	if (lista->tamanho == 0){
		//printf("esta vazia.\n");
        return 1;
    }else{
    	//printf("NAO esta vazia:\n");
        return 0;
    }
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

/*void ordenaLista(TLista *lista, TPais *novo){
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
     
}*/



void insertionOuro(TLista *lista, TPais *pais){
    TCelula *novo;
    novo = (TCelula *) malloc(sizeof(TCelula));

    novo->pais = *pais;
    //printf("O NOVO É %s", novo->pais.nome);

    TCelula *atual, *anterior;
	atual = lista->pHead->pProx;
	anterior = lista->pHead;  

	//printf(" LINHA 101: ATUAL == %d OUROS\n", atual->pais.ouro);

	for (int i = 0; i<lista->tamanho; i++){
		if(atual->pais.ouro < novo->pais.ouro){
			anterior->pProx = novo;
			novo->pProx = atual;
			break;
			}
			anterior = atual;
			atual = atual->pProx;
		}


}


void insertionPrata(TLista *lista, TPais *pais){
    TCelula *novo;
    novo = (TCelula *) malloc(sizeof(TCelula));

    novo->pais = *pais;

    TCelula *atual, *anterior;
	atual = lista->pHead->pProx;  
	anterior = lista->pHead;

	//printf(" LINHA 101: ATUAL == %d OUROS\n", atual->pais.ouro);

	for (int i = 0; i<lista->tamanho; i++){
		if((atual->pais.ouro == novo->pais.ouro) && (strcmp(atual->pais.nome, novo->pais.nome) != 0)){
			//printf("o ouro de %s(%d) é igual ao de %s(%d)\n", atual->pais.nome, atual->pais.ouro, novo->pais.nome, novo->pais.ouro);
			if(atual->pais.prata < novo->pais.prata){
				//printf("a prata de de %s(%d) é maior que a de %s(%d)\n", novo->pais.nome, novo->pais.prata, atual->pais.nome, atual->pais.prata);
				anterior->pProx = novo;
				novo->pProx = atual;
			}
			anterior = atual;
			atual = atual->pProx;	
		}
	}
}


void insertionBronze(TLista *lista, TPais *pais){
    TCelula *novo;
    novo = (TCelula *) malloc(sizeof(TCelula));

    novo->pais = *pais;

    TCelula *atual, *anterior;
	atual = lista->pHead->pProx;  
	anterior = lista->pHead;

	for (int i = 0; i<lista->tamanho; i++){
		if((atual->pais.ouro == novo->pais.ouro) && (strcmp(atual->pais.nome, novo->pais.nome) != 0) && (atual->pais.prata == novo->pais.prata)){
			//printf("o ouro e a prata de %s(%d)(%d) sao iguais aos de %s(%d)(%d)\n", atual->pais.nome, atual->pais.ouro, atual->pais.prata, novo->pais.nome, novo->pais.ouro, novo->pais.prata);
			if(atual->pais.bronze < novo->pais.bronze){
				//printf("o bronze de de %s(%d) é maior que a de %s(%d)\n", novo->pais.nome, novo->pais.bronze, atual->pais.nome, atual->pais.bronze);
				anterior->pProx = novo;
				novo->pProx = atual;
			}
			anterior = atual;
			atual = atual->pProx;	
		}
	}
}




void TLista_Imprime(TLista *lista) {
	TCelula *atual;
	atual = lista->pHead->pProx;

	for (int i = 0; i<lista->tamanho; i++){
		printf("%s %d %d %d\n", atual->pais.nome, atual->pais.ouro, atual->pais.prata, atual->pais.bronze);
		atual = atual->pProx;
	}
}

