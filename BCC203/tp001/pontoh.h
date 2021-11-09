#ifndef arvBinExterna_h
#define arvBinExterna_h

#include "dados.h"
#include "analise.h"

typedef Dados TipoItem;

typedef struct tipoNode TipoNode;

int arvoreBinariaExterna(TipoItem *itemPesq, Analise *analise, int situacao);

int arvoreBin_insereArv(FILE *arv, TipoItem *item, int pos, Analise *analise);

int arvoreBin_insereArvOrd(FILE *arv, TipoItem *item, int pos, Analise *analise);

TipoNode arvoreBin_criaNovoNode(TipoItem *item);

int arvoreBin_pesquisa(FILE *arv, TipoItem *itemPesq, Analise *analise);

void arvoreBin_imprimeArv();

#endif