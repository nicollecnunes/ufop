#include "arvoreb.h"

void Inicializa (TipoApontador *Arvore) { 
    *Arvore = NULL; //inicializa a arvoreb
}

int Pesquisa(TRegistro *x, TipoApontador Ap, Desempenho *d) {
    long i = 1;
    
    attComparacoes1(d, 1);
    if(Ap == NULL) return 0; // caso a arvore esteja vazia, ou o programa chegue, por meio da recursão,
                            // aos apontadores nulos dos nós folhas, retorna-se 0 pois o registro com a chave
                            //desejada não foi encontrado

    while(i < Ap->n && x->chave > Ap->r[i-1].chave) {
        i++;                                        // pesquisa sequencial para encontrar intervalo desejado
        attComparacoes1(d, 1);                      // enquanto i for menor ao numero de registros do nó e a
    }                                               // a chave desejada maior que a chave dos registros no nó
                                                    // i é incrementado. Dessa forma, podemos ter acesso a  
                                                    // "posicao seguinte" da que precisamos
    attComparacoes1(d, 1);
    if(x->chave == Ap->r[i-1].chave) {
        *x = Ap->r[i-1];
        return 1;
    } // caso a chave no intervalo for encontrada, atualizamos a variavel de registro e retornamos 1
    
    attComparacoes1(d, 1);
    if(x->chave < Ap->r[i-1].chave) return Pesquisa(x, Ap->p[i-1], d);
    else return Pesquisa(x, Ap->p[i], d); // caso a chave que queremos encontrar seja menor do que o registro analisado
                                         // chamamos recursivamente a funcao para o apontador da página a esquerdo da arvore
                                         // caso contrário chamamos para o apontador do lado direito
    return 0;
}

int arvBExterna(TRegistro *reg, int quantidadeRegistros, Desempenho *d){

    TipoApontador arvoreB;
    Inicializa(&arvoreB); //inicializa a arvore

    TRegistro *registro = (TRegistro *) malloc (quantidadeRegistros * sizeof( TRegistro ));

    if (registro == NULL) {
        printf("Não há mamória suficiente.\n");
        return -1;
    } // verifica se a alocação para a quantidade de registros que serao lidos foi válida
    
    FILE *arq = fopen("dados.bin", "rb");

    if (arq == NULL) {
        printf("Erro na abertura do arquivo.\n");
        return -1;
    }
// int i; VARIAVEL NÃO ESTA SENDO UTILIZADA
    inicializarAnalise(d);
    iniciaTimer(d);

    while (fread(registro, sizeof(TRegistro), quantidadeRegistros, arq)){ // leitura de X itens
        attTransferencias0(d, 1);
        for (int i = 0; i < quantidadeRegistros; i++){ // percorre os itens para inseri-los
            attComparacoes0(d, 1);
            Insere(registro[i], &arvoreB, d); // insere o registro na arvore
        }
    }

    fclose(arq);
    free(registro);

    paraTimer(d);
    attTempo0(d);

    Imprime(arvoreB, d);

    iniciaTimer(d);

    if(Pesquisa(reg, arvoreB, d)) {
        paraTimer(d);
        attTempo1(d);
        liberarArvore(arvoreB);
        return 1;
    } // retorna se a pesquisa pelo item foi ou não bem sucedida
    
    paraTimer(d);
    attTempo1(d);
    liberarArvore(arvoreB);

    return 0;
}


void Imprime(TipoApontador arvore, Desempenho *d){
    int i = 0;
    if(arvore == NULL) return;
    while(i <= arvore->n) {
        Imprime(arvore->p[i], d);
        if(i != arvore->n)
            printf("chave:%d\n", arvore->r[i].chave);
        i++;
    } 
}

void InsereNaPagina(TipoApontador Ap, TRegistro Reg, TipoApontador ApDir, Desempenho *d) {
    short naoAchouPosicao;
    int k;
    k = Ap->n;
    
    attComparacoes0(d, 1);
    if(k > 0) naoAchouPosicao = 1;
    else naoAchouPosicao = 0;

    while(naoAchouPosicao) {
        attComparacoes0(d, 1);
        if(Reg.chave >= Ap->r[k-1].chave) {
            naoAchouPosicao = 0;
            break;
        }
        Ap->r[k] = Ap->r[k-1];
        Ap->p[k+1] = Ap->p[k];
        // o registro de maior chave é empurrado para posições maiores
        k--; 
        attComparacoes0(d, 1);
        if(k<1) naoAchouPosicao = 0;
    }

    Ap->r[k] = Reg; // insere o registro
    Ap->p[k+1] = ApDir; // apontador a direita
    Ap->n++; // incrementa numero de registros na pagina
}

void Ins(TRegistro Reg, TipoApontador Ap, short *Cresceu, TRegistro *RegRetorno, TipoApontador *ApRetorno, Desempenho *d) {
    long i = 1;
    long j;

    TipoApontador ApTemp;

    // caso seja a primeira execução esse if vai ser responsável por informar que é preciso criar uma página raiz
    // caso não seja, se verdadeiro, ele vai informar que é onde o registro terá que ser inserido
    attComparacoes0(d, 1);
    if(Ap == NULL) {
        *Cresceu = 1;
        *RegRetorno = Reg;
        *ApRetorno = NULL;
        return;
    }

    while(i < Ap->n && Reg.chave > Ap->r[i-1].chave) {
        i++;                                            // realiza uma pesquisa dentro da página.Dessa forma, 
        attComparacoes0(d, 1);                          //podemos ter acesso a  "posicao seguinte" da que precisamos
    }

    
    attComparacoes0(d, 1);
    if(Reg.chave == Ap->r[i-1].chave) { 
        *Cresceu = 0;
        return;
    } //caso o item ja exista, não é preciso inseri-lo na arvore
    
    
    attComparacoes0(d, 1);
    if(Reg.chave < Ap->r[i-1].chave) i--; // verifica se a recursão será feita com o apontador da maior ou da menor chave
                                        // no intervalo
    
    Ins(Reg, Ap->p[i], Cresceu, RegRetorno, ApRetorno, d);

    attComparacoes0(d, 1);
    if(!*Cresceu) return;
    
    attComparacoes0(d, 1);
    if(Ap->n < MM) {
        InsereNaPagina(Ap, *RegRetorno, *ApRetorno, d);
        *Cresceu = 0;
        return;
    } // caso ainda exista espaço na página, basta inserir na página

    ApTemp = (TipoApontador) malloc(sizeof(TipoPagina)); // cria uma nova pagina
    ApTemp->n = 0; // numero de elementos da pagina
    ApTemp->p[0] = NULL; // apontador

    // caso i seja menor, o registro que se deseja inserir fica na página antiga
    attComparacoes0(d, 1);
    if(i < M + 1) {
        InsereNaPagina(ApTemp, Ap->r[MM-1], Ap->p[MM], d);
        Ap->n--;
        InsereNaPagina(Ap, *RegRetorno, *ApRetorno, d);
    } 
    // caso seja maior o registro será inserido na pagina nova, temporaria
    else InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno, d);

    // insere os registros da pagina mais antiga na nova pagina
    for(j = M + 2; j <= MM; j++) {
        InsereNaPagina(ApTemp, Ap->r[j-1], Ap->p[j], d);
        attComparacoes0(d, 1);
    }

    Ap->n = M; // a pagina "mais velha" diminui a quantidade de registros
    ApTemp->p[0] = Ap->p[M+1];  // a nova pagina "rouba" o apontador da antiga
    *RegRetorno = Ap->r[M]; // o registro que será retornado para as recursões anteriores
    *ApRetorno = ApTemp;  // retorna-se a pagina nova
}

void Insere(TRegistro Reg, TipoApontador *Ap, Desempenho *d) {
    short Cresceu;
    // vai informar se houve uma divisão de páginas em determinado nivel
    // que implicará em alterações nos pais
    TRegistro RegRetorno;
    TipoPagina *ApRetorno, *ApTemp;

    Ins(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno, d);

    // caso as páginas até a raiz estiverem cheias o método Ins retorna a variavel cresceu como Verdadeiro
    // nesse caso é preciso criar uma nova página raiz
    attComparacoes1(d, 1);
    if(Cresceu) {
        ApTemp = (TipoPagina*) malloc(sizeof(TipoPagina));
        ApTemp->n = 1;
        ApTemp->r[0] = RegRetorno;
        ApTemp->p[1] = ApRetorno;
        ApTemp->p[0] = *Ap;
        *Ap = ApTemp;
    }
}

int liberarArvore(TipoApontador Ap) {
    int i = 0;
    if (Ap == NULL) return 0;

    while (i <= Ap->n) {
        liberarArvore(Ap->p[i]);
        i++;
    }
    free(Ap);
    return 1;
}