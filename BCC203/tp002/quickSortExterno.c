#include "quickSortExterno.h"

void quickSortExterno(FILE **arqLi, FILE **arqEi, FILE **arqLEs, int esq, int dir)
{
    int i, j;

    Aluno *Area;
    Area = malloc(TAMANHOAREA * sizeof(Aluno));

    if ( dir - esq < 1) return;

    criaAreaVazia(Area);

    particao(arqLi, arqLi, arqLi, Area, esq, dir, &i, &j);

    fflush(*arqLi);
    fflush(*arqLi);
    fflush(*arqLi);

    if (i - esq < dir - j) // vai pro subarquivo menor
    {
        quickSortExterno(arqLi, arqEi, arqLEs, esq, i);
        quickSortExterno(arqLi, arqEi, arqLEs, j, dir);
    }
    else
    {
        quickSortExterno(arqLi, arqEi, arqLEs, j, dir);
        quickSortExterno(arqLi, arqEi, arqLEs, esq, i);
    }

    free(Area);
}

void leSuperior(FILE **arqLEs, Aluno *ultimoLido, int *ls, short *ondeLer)
{
    fseek(*arqLEs, (*ls - 1) * sizeof(Aluno), SEEK_SET);
    fread(ultimoLido, sizeof(Aluno), 1, *arqLEs);
    (*ls) --;
    *ondeLer = FALSE;
}

void leInferior(FILE **arqLi, Aluno *ultimoLido, int *li, short *ondeLer)
{
    fread(ultimoLido, sizeof(Aluno), 1, *arqLi);
    (*li)++;
    *ondeLer = TRUE;
}

void inserirArea(Aluno *area, Aluno *ultimoLido, int *nArea)
{
    // insere o ultimo lido de forma ordenada na area
    insereItem(*ultimoLido, area);
    *nArea = obterNumCelulasOcupadas(area);
}

void escreveMax(FILE **arqLEs, Aluno *R, int *es)
{
    fseek(*arqLEs, (*es - 1) * sizeof(Aluno), SEEK_SET);
    fwrite(&R, sizeof(Aluno), 1, *arqLEs);
    (*es) --;
}


void escreveMin(FILE **arqEi, Aluno *R, int *ei)
{
    fwrite(&R, sizeof(Aluno), 1, *arqEi);
    (*ei) ++;
}

void retiraMax(Aluno *area, Aluno *R, int *nArea){
    retiraUltimo(area, R);
    *nArea = obterNumCelulasOcupadas(area);
}

void retiraMin(Aluno *area, Aluno *R, int *nArea){
    retiraPrimeiro(area, R);
    *nArea = obterNumCelulasOcupadas(area);
}

void particao(FILE **arqLi, FILE **arqEi, FILE **arqLEs, Aluno *area, int esq, int dir, int *i, int *j)
{
    int ls = dir;
    int es = dir;
    int li = esq;
    int ei = esq;

    int nArea = 0;

    int lInf = INT_MIN;
    int lSup = INT_MAX;

    short ondeLer = TRUE;

    Aluno R;

    fseek(*arqLi, (li - 1) * sizeof(Aluno), SEEK_SET);
    fseek(*arqEi, (ei - 1) * sizeof(Aluno), SEEK_SET);

    *i = esq - 1;
    *j = dir + 1;

    while (ls >= li)
    {
        Aluno ultimoLido;
        if (nArea < TAMANHOAREA - 1)
        {
            if (ondeLer) leSuperior(arqLEs, &ultimoLido, &ls, &ondeLer);
            else leInferior(arqLi, &ultimoLido, &li, &ondeLer);

            inserirArea(area, &ultimoLido, &nArea);
            continue;
        }

        if (ls == es)
        {
            leSuperior(arqLEs, &ultimoLido, &ls, &ondeLer);
        }
        else if (li == ei)
        {
            leInferior(arqLi, &ultimoLido, &li, &ondeLer);
        }
        else if (ondeLer)
        {
            leSuperior(arqLEs, &ultimoLido, &ls, &ondeLer);
        }
        else
        {
            leInferior(arqLi, &ultimoLido, &li, &ondeLer);
        }

        if (ultimoLido.nota > lSup)
        {
            *j = es;
            escreveMax(arqLEs, &ultimoLido, &es);
            continue;
        }

        if (ultimoLido.nota < lInf)
        {
            * i = ei;
            escreveMin(arqEi, &ultimoLido, &ei);
            continue;
        }

        inserirArea(area, &ultimoLido, &nArea);
        
        if ( ei - esq < dir - es)
        {
            retiraMin(area, &R, &nArea);
            escreveMin(arqEi, &R, &ei);
            lInf = R.nota;
        }
        else
        {
            retiraMax(area, &R, &nArea);
            escreveMax(arqLEs, &R, &es);
            lSup = R.nota;
        }    
    }

    while ( ei <= es)
    {
        retiraMin(area, &R, &nArea);
        escreveMin(arqEi, &R, &ei);
    }
}

void criaAreaVazia(Aluno *area)
{
    for(int i = 0; i < TAMANHOAREA; i++){
        area[i].inscricao = -1;
        area[i].nota = -1.0;
        strcpy(area[i].estado,"XX");
        strcpy(area[i].cidade,"XX");
        strcpy(area[i].curso,"XX");
    }
}

void insereItem(Aluno ultimoLido, Aluno *area)
{
    int i = 0;
    int j = 18;
    int k = 19;

    while(area[i].nota < ultimoLido.nota && area[i].inscricao != -1 && i < TAMANHOAREA){
        i++;
    }

    while (j >= i)
    {
        area[k] = area[j];
        j--;
        k--;
    }

    area[i] = ultimoLido;
}

int obterNumCelulasOcupadas(Aluno *area)
{
    int i = 0;
    while(area[i].inscricao != -1 && i < TAMANHOAREA)
        i++;

    return i;
}

void retiraUltimo(Aluno *area, Aluno *R)
{
    int i = 0;
    while(area[i].inscricao != -1 && i < TAMANHOAREA)
        i++;

    i--; 
    *R = area[i];

    area[i].inscricao = -1;
    area[i].nota = -1.0;
    strcpy(area[i].estado,"XX");
    strcpy(area[i].cidade,"XX");
    strcpy(area[i].curso,"XX");
}

void retiraPrimeiro(Aluno *area, Aluno *R)
{
    int i = 0;
    int j = 1;

    *R = area[i];

    while(area[j].inscricao != -1 && i < TAMANHOAREA-1){
        area[i] = area[j];
        i++;
        j++;
    }

    area[i].inscricao = -1;
    area[i].nota = -1.0;
    strcpy(area[i].estado,"XX");
    strcpy(area[i].cidade,"XX");
    strcpy(area[i].curso,"XX");
    // TODO: criar funcao de gerar posicao vazia
}






