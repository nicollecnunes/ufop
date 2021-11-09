#include "arvBinaria.h"

TRegistro *rCriarArray(int n){
    TRegistro *aux = (TRegistro *) malloc(n * sizeof(TRegistro));
    if (aux != NULL)
        return aux;

    printf("Erro ao alocar o registro.\n");
    return NULL;  
}

TNo arvBinariaCriarNo(TItem *item){
    TNo aux;
    aux.item = *item;
    aux.esq = -1;
    aux.dir = -1;
    return aux;
}

int arvBinariaExterna(TItem *itemPesquisa, int situacao, Desempenho *d){ 
    int quantidadeRegistros = 20;
    TRegistro *registroAux = (TRegistro *) malloc (quantidadeRegistros * sizeof( TRegistro ));

    if (registroAux == NULL)
    {
        printf("Não há memória suficiente.\n");
        return -1;
    }

    TItem *item = registroAux;

    FILE *arv = fopen("arvBinaria.bin", "w+b");
    FILE *arq = fopen("dados.bin", "rb");

    if (arv == NULL || arq == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        return -1;
    }
    int aux = 0;

    inicializarAnalise(d);
    iniciaTimer(d);
    int i;
    switch (situacao){
        case 1:
            attTransferencias0(d, 1);
            // arquivo ordenado ascendentemente
            //printf("[LOG] Realizando insercao em arquivo ordenado ascendentemente\n");
            while (fread(item, sizeof(TItem), quantidadeRegistros, arq)){ // leitura de X itens
                attTransferencias0(d, 1);
                for ( i = 0; i < quantidadeRegistros; i++){ // percorre os itens para inseri-los
                    int okInsercao = arvBinariaOrdenadaInserir(arv, &item[i], aux, d); 
                    if (!okInsercao)
                        aux = aux - 1; // não foi inserido
                    aux = aux + 1;
                }
            }
            break;
        case 2:
            attTransferencias0(d, 1);
            // arquivo ordenado descendentemente
           // printf("[LOG] Realizando insercao em arquivo ordenado descendentemente\n");
            while (fread(item, sizeof(TItem), quantidadeRegistros, arq)){ // leitura de X itens
                attTransferencias0(d, 1);
                for ( i = 0; i < quantidadeRegistros; i++){ // percorre os itens para inseri-los
                    int okInsercao = arvBinariaOrdenadaInserir(arv, &item[i], aux, d); 
                    if (!okInsercao)
                        aux = aux - 1; // não foi inserido
                    aux = aux + 1;
                }
            }
            break;
        case 3:
            attTransferencias0(d, 1);
            // arquivo desordenado aleatoriamente
            //printf("[LOG] Realizando insercao em arquivo desordenado aleatoriamente\n");
            while (fread(item, sizeof(TItem), quantidadeRegistros, arq)){ // leitura de X itens
                attTransferencias0(d, 1);
                for ( i = 0; i < quantidadeRegistros; i++){ // percorre os itens para inseri-los
                    int okInsercao = arvBinariaInserir(arv, &item[i], aux, d); 
                    if (!okInsercao)
                        aux = aux - 1; // não foi inserido
                    aux = aux + 1;
                }
            }
            break;
        default:
            printf("Valor da situação é inválido.");
            break;
            return -1;
    }

    fclose(arv);
    fclose(arq);

    paraTimer(d);
    attTempo0(d);

    iniciaTimer(d);
    arv = fopen("arvBinaria.bin", "rb");

    int resultado = arvBinariaPesquisa(arv, itemPesquisa, d);
    fclose(arv);

    paraTimer(d);
    attTempo1(d);

    return resultado;
}

int arvBinariaInserir(FILE *arv, TItem *item, int pos, Desempenho *d) {
    //printf("[LOG] Insercao do item (%d) em uma arvore desordenada\n", item->chave);
    if (pos == 0) { // arvore binaria vazia
        //printf("[LOG] Arvore Vazia");
        TNo no;
        no = arvBinariaCriarNo(item); // cria o nó

        fseek(arv, 0, SEEK_SET); // vai para o inicio do arquivo
        fwrite(&no, sizeof(TNo), 1, arv); // escreve o no
        attTransferencias0(d,1);
        return 1;
    }
    else {
        TNo no;
        no = arvBinariaCriarNo(item); //Cria o novo nó a ser inserido

        int aux = 0;

        fseek(arv, 0, SEEK_SET); // vai para o inicio do arquivo

        TNo raiz;
        fread(&raiz, sizeof(TNo), 1, arv); // armazena a raiz
        attTransferencias0(d,1);

        while (1) { // buscar o item anterior . o while executa enquanto não se encontram itens iguais
            attComparacoes0(d,1);
            if (item->chave < raiz.item.chave) { //se a chave do item for menor que a da raiz, vai para a sub-arvore à esquerda
                if (raiz.esq != -1) { // existe um no a esquerda
                    aux = raiz.esq;
                    fseek(arv, raiz.esq * sizeof(TNo), SEEK_SET); // o ponteiro vai para o filho a esquerda
                    fread(&raiz, sizeof(TNo), 1, arv); // armazena o no a esquerda
                    attTransferencias0(d,1);
                }
                else { // caso nao exista um no a esquerda (raiz.esq == -1)
                    raiz.esq = pos;

                    fseek(arv, aux * sizeof(TNo), SEEK_SET); // volta para a posicao anterior (aux)
                    fwrite(&raiz, sizeof(TNo), 1, arv); // escreve a linha do item pai
                    attTransferencias0(d,1);

                    fseek(arv, pos * sizeof(TNo), SEEK_SET);
                    fwrite(&no, sizeof(TNo), 1, arv); // escreve o nó no arquivo
                    attTransferencias0(d,1);
                    return 1;
                }
            }
            else if (item->chave > raiz.item.chave) { //se a chave do item for maior que a da raiz, vai para a sub-arvore à direita
                attComparacoes0(d,1);
                if (raiz.dir != -1){ // existe um no a direita
                    aux = raiz.dir;
                    fseek(arv, raiz.dir * sizeof(TNo), SEEK_SET); // o ponteiro vai para o filho a direita
                    fread(&raiz, sizeof(TNo), 1, arv); // le o no seguinte
                    attTransferencias0(d,1);
                }
                else {
                    attComparacoes0(d,1);
                    raiz.dir = pos;

                    fseek(arv, aux * sizeof(TNo), SEEK_SET); // volta para a posicao anterior (aux)
                    fwrite(&raiz, sizeof(TNo), 1, arv); // escreve a linha do item pai
                    attTransferencias0(d,1);

                    fseek(arv, pos * sizeof(TNo), SEEK_SET);
                    fwrite(&no, sizeof(TNo), 1, arv); // escreve o nó no arquivo
                    attTransferencias0(d,1);

                    return 1;
                }
            }
            else { // encontrou itens iguais. quebra o loop
                return 0;
            }
        }
    }

    return 0;
}


int arvBinariaOrdenadaInserir(FILE *arv, TItem *item, int pos, Desempenho *d) {
    //printf("[LOG] Insercao do item (%d)\n", item->chave);
    if (pos == 0) { // arvore vazia
        //printf("[LOG] Arvore vazia\n");
        TNo no;
        no = arvBinariaCriarNo(item); // cria um novo nó

        fseek(arv, 0, SEEK_SET); // vai para o inicio do arquivo
        fwrite(&no, sizeof(TNo), 1, arv); // escreve o no
        attTransferencias0(d,1);
        return 1;
    }
    else {
        TNo no;
        TNo raiz;

        int aux = (pos - 1); // posicao do no Pai
        no = arvBinariaCriarNo(item); // cria um novo nó a ser inserido 

        fseek(arv, aux * sizeof(TNo), SEEK_SET); // vai para a linha anterior
        fread(&raiz, sizeof(TNo), 1, arv); // armazena a raiz

        attTransferencias0(d,1);
        attComparacoes0(d,1);

        if (item->chave < raiz.item.chave && raiz.esq == -1){ // se a chave do item for menor que a da raiz E 
                                                            // nao existir subarvore a esquerda, vai para a sub-arvore à esquerda
            //printf("[LOG] Esquerda, pois a chave (%d) e menor que o no atual (%d)\n", item->chave, raiz.item.chave);
            raiz.esq = pos;
            fseek(arv, aux * sizeof(TNo), SEEK_SET); // vai para a posicao anterior
            fwrite(&raiz, sizeof(TNo), 1, arv); // reescreve a linha
            attTransferencias0(d,1);

            fseek(arv, pos * sizeof(TNo), SEEK_SET); // vai para a posicao pos
            fwrite(&no, sizeof(TNo), 1, arv); // escreve o no
            attTransferencias0(d,1);

            return 1;
        }
        else if (item->chave > raiz.item.chave && raiz.dir == -1){// se a chave do item for maior que a da raiz E 
                                                            // nao existir subarvore a direita, vai para a sub-arvore à direita
            //printf("[LOG] Direita, pois a chave (%d) e maior que o no atual (%d)\n", item->chave, raiz.item.chave);
            attComparacoes0(d,1);
            raiz.dir = pos;
            fseek(arv, aux * sizeof(TNo), SEEK_SET); // vai para a posicao anterior
            fwrite(&raiz, sizeof(TNo), 1, arv); // reescreve a linha
            attTransferencias0(d,1);

            fseek(arv, pos * sizeof(TNo), SEEK_SET);
            fwrite(&no, sizeof(TNo), 1, arv); // escreve o no
            attTransferencias0(d,1);

            return 1;
        }
        else { // itens iguais
            //printf("[LOG] Itens iguais\n");
            attComparacoes0(d,1);
            return 0;
        }
    }
    return 0;
}

int arvBinariaPesquisa(FILE *arv, TItem *itemPesq, Desempenho *d){
    //printf("[LOG] Iniciando pesquisa do %d\n", itemPesq->chave);
    TNo no;

    if (!fread(&no, sizeof(TNo), 1, arv))
        return 0;

    int fEsq = 1, fDir = 1;

    while (1)
    {
        attComparacoes1(d,1);
        if (itemPesq->chave < no.item.chave && fEsq != -1){ // se a chave do item pesquisado for menor que a chave do no atual
                                                            // e existir um filho a esquerda:
            fseek(arv, no.esq * sizeof(TNo), SEEK_SET);
            fread(&no, sizeof(TNo), 1, arv); // armazena o filho a esquerda

            // atualiza os nós para percorrer
            fEsq = no.esq; 
            fDir = no.dir;
            attComparacoes1(d,1);
            //printf("[LOG] Esquerda, pois a chave (%d) e menor que o no atual (%d)\n", itemPesq->chave, no.item.chave);
        }
        else if (itemPesq->chave > no.item.chave && fDir != -1){ // se a chave do item pesquisado for maior que a chave do no atual
                                                                // e existir um filho a direita:
            attComparacoes1(d,1);
            fseek(arv, no.dir * sizeof(TNo), SEEK_SET);
            fread(&no, sizeof(TNo), 1, arv); // armazena o filho a direita

            // atualiza os nós para percorrer
            fEsq = no.esq;
            fDir = no.dir;
            attComparacoes1(d,1);
            //printf("[LOG] Direita, pois a chave (%d) e maior que o no atual (%d)\n", itemPesq->chave, no.item.chave);
        }
        else if (itemPesq->chave == no.item.chave){ // se as chaves forem iguais (folhas)
            attComparacoes1(d,1);
            *itemPesq = no.item;
            //printf("[LOG] Encontrados itens iguais\n");
            return 1;
        }else{ // nao encontrado
            attComparacoes1(d,1);
            return 0;
        } 
    }
}

void arvBinariaPrint(){
    FILE *arv = fopen("arvBinaria.bin", "rb");
    if (arv == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        return;
    }

    TNo no;
    while (fread(&no, sizeof(TNo), 1, arv))
    {
        printf("%d | %d | %d\n", no.esq, no.item.chave, no.dir);
    }
    fclose(arv);
}
