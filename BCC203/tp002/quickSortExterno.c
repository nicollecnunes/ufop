#include "quickSortExterno.h"

// algoritmo principal com chamadas recursivas
void quickSortExterno(FILE **arqLi, FILE **arqEi, FILE **arqLEs, int esq, int dir, Analise *a)
{
    int i, j;
    Area area;

    if ( dir - esq < 1){
        return;
    }
    area.areaAlunos = malloc(TAMANHOAREAPIVO * sizeof(Aluno));
    area.tamanho = 0;

    particao(arqLi, arqEi, arqLEs, area, esq, dir, &i, &j, a);

    if (i - esq < dir - j) // ativa primeiro a particao menor
    {
        quickSortExterno(arqLi, arqEi, arqLEs, esq, i, a); // primeira particao vai de esq a i
        quickSortExterno(arqLi, arqEi, arqLEs, j, dir, a); // segunda particao vai de j a dir
    }
    else
    {
        quickSortExterno(arqLi, arqEi, arqLEs, j, dir, a); // primeira particao vai de esq a i
        quickSortExterno(arqLi, arqEi, arqLEs, esq, i, a); // segunda particao vai de j a dir
    }
}

// ponteiro de leitura e escrita superior
// por isso fez o fseek antes, na posicao que queremos. (ls- 1) para pegar o inicio
// da posicao desejada. ls é decrementado
void leSuperior(FILE **arqLEs, Aluno *ultimoLido, int *ls, short *deveLerSuperior, Analise *a)
{
    fseek(*arqLEs, (*ls - 1) * sizeof(Aluno), SEEK_SET);
    novaLeitura(a);
    fread(ultimoLido, sizeof(Aluno), 1, *arqLEs);
    (*ls) --;
    *deveLerSuperior = FALSE; // controla as leituras alternadas. FALSE indica que deve fazer a leitura inferior
}

// controlada pelo ponteiro especifico arqLi
// simplesmente le o item e o retorna. li é o valor numerico da posicao
void leInferior(FILE **arqLi, Aluno *ultimoLido, int *li, short *deveLerSuperior, Analise *a)
{
    novaLeitura(a);
    fread(ultimoLido, sizeof(Aluno), 1, *arqLi);
    (*li)++;
    *deveLerSuperior = TRUE; // controla as leituras alternadas. TRUE indica que deve fazer a leitura superior
}

// inserir dentro da area que representa o pivo
// os itens lidos sao inseridos na area.
// esse metodo pega o item lido e insere na area
void inserirAluno(Area *area, Aluno *ultimoLido, int *nAluno, Analise *a)
{
    // insere item ORDENADO
    insereItem(*ultimoLido, area, a);
    *nAluno = area->tamanho;
}

// escreve do lado superior
// precisa dar fseek em es - 1 pois o ponteiro é compartilhado pra
// leitura e escrita superiores
void escreveSup(FILE **arqLEs, Aluno R, int *es, Analise *a)
{
    novaEscrita(a);
    fseek(*arqLEs, (*es - 1) * sizeof(Aluno), SEEK_SET);
    fwrite(&R, sizeof(Aluno), 1, *arqLEs);
    (*es) --;
}

// escreve no lado inferior. apenas fwrite pois o ponteiro e unico
void escreveInf(FILE **arqEi, Aluno R, int *ei, Analise *a)
{
    novaEscrita(a);
    fwrite(&R, sizeof(Aluno), 1, *arqEi);
    (*ei) ++;
}

// retira o maior elemento do pivo (ultimo)
void retiraMax(Area *area, Aluno *R, int *nAluno, Analise *a){
    retiraUltimo(area, R, a);
    *nAluno = area->tamanho;
}

// retira o menor elemento (primeiro) do pivo
void retiraMin(Area *area, Aluno *R, int *nAluno, Analise *a){
    retiraPrimeiro(area, R, a);
    *nAluno = area->tamanho;
}

// retorna os valores de i e de j, que sao os limites da particao
void particao(FILE **arqLi, FILE **arqEi, FILE **arqLEs, Area area, int esq, int dir, int *i, int *j, Analise *a)
{
    int ls = dir;
    int es = dir;
    int li = esq;
    int ei = esq;

    int nAluno = 0;

    int lInf = INT_MIN;
    int lSup = INT_MAX;

    short deveLerSuperior = TRUE;

    Aluno R;
    Aluno ultimoLido;

    fseek(*arqLi, (li - 1) * sizeof(Aluno), SEEK_SET); // inicializa ponteiros na primeira posição do arquivo
    fseek(*arqEi, (ei - 1) * sizeof(Aluno), SEEK_SET); // inicializa ponteiros na primeira posição do arquivo

    *i = esq - 1; // 0
    *j = dir + 1; // qtd + 1

    while (ls >= li)
    {
        if (nAluno < TAMANHOAREAPIVO - 1) // preenche a area do pivo ate que reste apenas 1 posicao livre
        {
            if (deveLerSuperior) leSuperior(arqLEs, &ultimoLido, &ls, &deveLerSuperior, a);
            else leInferior(arqLi, &ultimoLido, &li, &deveLerSuperior, a);

            // ultimo lido é lido de sup ou inf e inserido no pivo
            inserirAluno(&area, &ultimoLido, &nAluno, a);
            continue; // volta pro while
        }

        // agora tem que fazer a leitura do elemento único que poderia preencher a posicao
        // livre que ficou no pivo
        if (ls == es)
        {
            leSuperior(arqLEs, &ultimoLido, &ls, &deveLerSuperior, a);
        }
        else if (li == ei)
        {
            leInferior(arqLi, &ultimoLido, &li, &deveLerSuperior, a);
        }

        else if (deveLerSuperior)
        {
            leSuperior(arqLEs, &ultimoLido, &ls, &deveLerSuperior, a);
        }
        else
        {
            leInferior(arqLi, &ultimoLido, &li, &deveLerSuperior, a);
        }

        // inicia o processo de saber o que fazer com o ultimo item que lemos
        novaComparacao(a);
        if (ultimoLido.nota > lSup)
        {
            // atualiza J e escreve o item em ES
            *j = es;
            escreveSup(arqLEs, ultimoLido, &es, a);
            continue;
        }

        novaComparacao(a);
        if (ultimoLido.nota < lInf)
        {
            // atualiza I e escreve o item em EI
            * i = ei;
            escreveInf(arqEi, ultimoLido, &ei, a);
            continue;
        }

        // se nao tiver entrado em nenhum dos ifs, vai simplesmente escrever o item no pivo
        // isso faz com que ele seja preenchido completamente
        inserirAluno(&area, &ultimoLido, &nAluno, a);
        
        // se a qtd de elementos do subA1 < qtd SubA2
        if ( ei - esq < dir - es)
        {
            // retira o menor elemento do pivo, escreve ele no A1 e atualiza linf
            retiraMin(&area, &R, &nAluno, a);
            escreveInf(arqEi, R, &ei, a);
            lInf = R.nota;
        }
        else
        {
            // retira o maior elemento do pivo, escreve ele no A2 e atualiza lusp
            retiraMax(&area, &R, &nAluno, a);
            escreveSup(arqLEs, R, &es, a);
            lSup = R.nota;
        }    
    } // ls e li se cruzaram

    // voltar com os elementos do pivo pra dentro do arquivo
    while ( ei <= es)
    {
        retiraMin(&area, &R, &nAluno, a);
        escreveInf(arqEi, R, &ei, a);
    }
}

void insereItem(Aluno ultimoLido, Area *area, Analise *a)
{
    int j, i;
    novaComparacao(a);
    for (i = area->tamanho - 1; ((i>=0) && (area->areaAlunos[i].nota > ultimoLido.nota)); i--)
    {
        novaComparacao(a);
        j = i + 1;
        area->areaAlunos[j] = area->areaAlunos[i];
    }
    area->areaAlunos[i + 1] = ultimoLido;
    area->tamanho = area->tamanho + 1;
}

void retiraUltimo(Area *area, Aluno *R, Analise *a)
{
    int posicao = area->tamanho - 1;
    
    *R = area->areaAlunos[posicao];
    area->tamanho = area->tamanho - 1;
}

void retiraPrimeiro(Area *area, Aluno *R, Analise *a)
{
    *R = area->areaAlunos[0];

    for (int i = 0; i < area->tamanho; i++)
    {
        area->areaAlunos[i] = area->areaAlunos[i+1];
    }

    area->tamanho = area->tamanho - 1;
}






