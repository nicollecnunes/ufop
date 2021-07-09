
/*como nas funções-exemplo de TLista tem-se um "int pos"
como parâmetro, deduz-seque o TAD a ser implementado trata-se
de uma lista com vetores, e não com ponteiros
*/

/*Esta implementação é eficiente?
Resposta: Sim, a implementação das funções de pilha em
uma lista simples com vetor é eficiente, por ambas (pilha
e lista com vetor) se comportam da mesma forma e possuem
as mesmas estruturas (TAD Item com as informações; TAD Lista/Pilha
com um int tamanho e um vetor do TAD Item).
*/

#define MAX 100
#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int key;
} TItem ;

typedef struct lista{
    TItem items[MAX];
    int tamanho;
}TLista ;


void TPilha_Inicia (TLista *pLista){
    pLista->tamanho = 0;
}

int TPilha_EhVazia(TLista *pLista){
    if (pLista->tamanho == 0){
        return 1;
    }else{
        return 0;
    }
}

int TPilha_Push (TLista *pLista, TItem item){
    if(pLista->tamanho < MAX){
        pLista->items[pLista->tamanho] = item; //recebe o item no final
        pLista->tamanho = pLista->tamanho + 1;
        printf("foi adicionado o item %d\n", item.key);
        return 1;
    }else{
        return 0;
    }   
}

int TPilha_Pop (TLista *pLista, TItem *item){
    if (TPilha_EhVazia(pLista)){
        return 0;
    }else{
        (*item) = pLista->items[pLista->tamanho - 1]; //recebe o ultimo
        pLista->tamanho = pLista->tamanho - 1; //atualiza o tamanho
        printf("foi removido o item %d\n", item->key);
        return 1;
    }

}

void TPilha_Imp(TLista *pLista) {
    printf("[");
    for (int i=0;i<pLista->tamanho;i++) {
        printf(" %d", pLista->items[i].key);
    }
    printf(" ]\n");
}


int main(){
    
    TItem item;
    
    TLista A;
    TPilha_Inicia(&A);
    
    if(TPilha_EhVazia(&A)){
        printf("foi iniciada uma lista vazia\n");
    }else{
        printf("algo deu errado, a lista não está vazia\n");
    }
    
    item.key = 1;
    TPilha_Push(&A, item);
    TPilha_Imp(&A);
    
    item.key = 2;
    TPilha_Push(&A, item);
    TPilha_Imp(&A);
    
    item.key = 3;
    TPilha_Push(&A, item);
    TPilha_Imp(&A);
    
    item.key = 3;
    TPilha_Pop(&A, &item);
    TPilha_Imp(&A);

    return 0;
}
