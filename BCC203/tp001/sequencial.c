#include "sequencial.h"

int busca_sequencial(int chave, TRegistro *registro, Desempenho *d, int situacao)
{
  inicializarAnalise(d);
  iniciaTimer(d);
  int n = calcula_tamanho_arquivo(d);
  FILE *arq = fopen("dados.bin", "r");

  TIndice *indices = (TIndice *)malloc(n * sizeof(TIndice));
  int indice_desejado;
  gerar_tabela_indices(n, indices, d);

  if (arq == NULL)
    return 0;
  paraTimer(d);
  attTempo0(d);

  iniciaTimer(d);

  int i = 0;
  attComparacoes1(d, 1);
  if (situacao == 1)
  {
    while (i < n)
    {
      attComparacoes1(d, 1);
      i += 4;
      if (i > n)
        i = n - 1;

      attComparacoes1(d, 1);
      if (indices[i].chave >= chave)
      {
        attComparacoes1(d, 1);
        for (int j = 0; j <= 3; j++)
        {
          attComparacoes1(d, 1);
          if (indices[i - j].chave == chave)
          {
            indice_desejado = indices[i].indice;

            fseek(arq, indice_desejado * sizeof(TRegistro), SEEK_SET);
            attTransferencias1(d, 1);
            fread(registro, sizeof(TRegistro), 1, arq);
            attTransferencias1(d, 1);
            paraTimer(d);
            attTempo1(d);
            return 1;
          }
        }
      }
    }
  }

  else if (situacao == 2)
  {
    attComparacoes1(d, 1);
    while (i < n)
    {
      attComparacoes1(d, 1);
      i += 4;
      if (i > n)
        i = n - 1;

      attComparacoes1(d, 1);

      if (indices[i].chave <= chave)
      {
        attComparacoes1(d, 1);
        for (int j = 0; j <= 3; j++)
        {
          attComparacoes1(d, 1);
          if (indices[i - j].chave == chave)
          {
            indice_desejado = indices[i].indice;

            fseek(arq, indice_desejado * sizeof(TRegistro), SEEK_SET);
            attTransferencias1(d, 1);
            fread(registro, sizeof(TRegistro), 1, arq);
            attTransferencias1(d, 1);
            paraTimer(d);
            attTempo1(d);
            return 1;
          }
        }
      }
    }
  }

  else
    printf("Sem ordenação não é possível usar o método\n");

  paraTimer(d);
  attTempo1(d);

  return 0;
}

int calcula_tamanho_arquivo(Desempenho *d)
{

  FILE *arquivo = fopen("dados.bin", "r");
  fseek(arquivo, 0, SEEK_END);
  attTransferencias0(d, 1);
  return ftell(arquivo) / sizeof(TRegistro);
}

void gerar_tabela_indices(int n, TIndice *indices, Desempenho *d)
{
  FILE *arq = fopen("dados.bin", "r");
  TRegistro aux;

  for (int i = 0; i < n; i++)
  {
    fread(&aux, sizeof(TRegistro), 1, arq);
    attTransferencias0(d, 1);
    attComparacoes0(d, 1);
    indices[i].indice = i;
    indices[i].chave = aux.chave;
  }
  fclose(arq);
}