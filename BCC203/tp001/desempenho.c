#include "desempenho.h"

void inicializarAnalise(Desempenho *d)
{
    d->transferencias0 = 0;
    d->transferencias1 = 0;

    d->comparacoes0 = 0;
    d->comparacoes1 = 0;
}

void iniciaTimer(Desempenho *d)
{
    d->hora0 = clock();
}

void paraTimer(Desempenho *d)
{
    d->hora1 = clock();
}

void attTransferencias0(Desempenho *d, int n)
{
    d->transferencias0 = d->transferencias0 + n;
}

void attTransferencias1(Desempenho *d, int n)
{
    d->transferencias1 = d->transferencias1 + n;
}

void attComparacoes0(Desempenho *d, int n)
{
    d->comparacoes0 = d->comparacoes0 + n;
}

void attComparacoes1(Desempenho *d, int n)
{
    d->comparacoes1 = d->comparacoes1 + n;
}

void attTempo0(Desempenho *d)
{
    d->tempo0 = ((double)(d->tempo1 - d->hora0) * 1000 / CLOCKS_PER_SEC) * -1;
}

void attTempo1(Desempenho *d)
{
    d->tempo1 = ((double)(d->tempo1 - d->hora1) * 1000 / CLOCKS_PER_SEC) * -1;
}

void resultadoDesempenho(Desempenho *d)
{
    printf("Desempenho do pre-processamento:\nTempo: %.4lfms\nComparacoes: %d\nTransferencias: %d\n\n", d->tempo0, d->comparacoes0, d->transferencias0);

    printf("Desempenho do pos-processamento:\nTempo: %.4lfms\nComparacoes: %d\nTransferencias: %d\n", d->tempo1, d->comparacoes1, d->transferencias1);
}
