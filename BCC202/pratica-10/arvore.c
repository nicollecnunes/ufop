#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
void TArvore_Inicia (TNo **pRaiz){
    //printf("inicializando a arvore\n");
    *pRaiz = NULL;
}

//Manter como especificado
void TArvore_Insere_Raiz (TNo **ppRaiz , TItem x){
    //printf("inserindo raiz\n");
    if (*ppRaiz == NULL){
        //printf("15- entrei no if\n");
        *ppRaiz = TNo_Cria(x);
        //printf("17- saindo\n");
        return;
    }
    //printf("20 - nao entrei no if\n");
    TArvore_Insere (ppRaiz, x);
}

//Manter como especificado
int TArvore_Insere (TNo **ppRaiz , TItem x){
    if (*ppRaiz == NULL) {
        *ppRaiz = TNo_Cria(x);
        return 1;
    }

    if (x.chave < (* ppRaiz) -> item.chave)
        return TArvore_Insere(&((* ppRaiz) -> pEsq) , x);
    if (x.chave > (* ppRaiz) -> item.chave)
        return TArvore_Insere(&((* ppRaiz) -> pDir) , x);

    return 0; // elemento jah existe

}

//Manter como especificado
TNo *TNo_Cria (TItem x){
    //printf("criandi  o no com Titemchave %ld\n", x.chave);
    TNo *pAux = (TNo*)malloc(sizeof(TNo));

    pAux->item = x;
    pAux->pEsq = NULL;
    pAux->pDir = NULL;
    return pAux;
}

//Manter como especificado
void Prefixa(TNo *p){
    if (p == NULL){
        return;
    }
    printf (" %ld", p->item.chave);
    Prefixa (p->pEsq);
    Prefixa (p->pDir);
}

//Manter como especificado
void Infixa(TNo *p){
    if (p == NULL ){
        return;
    }
    Infixa(p ->pEsq);
    printf (" %ld", p ->item.chave);
    Infixa(p ->pDir);
}

//Manter como especificado
void Posfixa(TNo *p){
    if (p == NULL){
        return;
    }
    Posfixa (p -> pEsq);
    Posfixa (p -> pDir);
    printf (" %ld", p->item.chave) ;
}
