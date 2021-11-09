#ifndef arvoreBinaria_h
#define arvoreBinaria_h

typedef Registro TItem;
typedef struct tNo TNo;

#define QTD_DADOS 15

typedef struct
{
  int indice;
  long int dado1;
  char dado2[1000], dado3[5000];
} Registro;

void gerarRegistros(int n, Registro *registros);

int arvoreBinaria(TItem *item, int situacao);

int abInserirArvore(TItem *item, FILE *arv, int pos);

int abInserirArvoreOrd(TItem *item, FILE *arv, int pos);

TNo abCriaNo(TItem *item);

int abPesquisa(TItem *itemPesq, FILE *arv);

void abPrint();

#endif