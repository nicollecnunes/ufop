#include "arvBinExterna.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tipoNode
{
  TipoItem item;
  int esq;
  int dir;
};

int arvoreBinariaExterna(TipoItem *itemP, Analise *analise, int situacao)
{
  TipoItem *item = dados_cria_array(QTD_DADOS);
  FILE *arv = fopen("data_arv.bin", "w+b");
  FILE *arq = fopen("data.bin", "rb");
  if (arv == NULL || arq == NULL)
  {
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }
  //Cria a arvore no aquivo
  int cont = 0;
  int inseriu;

  iniciaAnalise(analise);
  iniciaContagemTempo(analise);
  if (situacao == 3)
  { // Caso os dados estejam aleatorios
    updateTranferencias_pre(analise, 1);
    while (fread(item, sizeof(TipoItem), QTD_DADOS, arq)) //Pega n itens do arquivo
    {
      updateTranferencias_pre(analise, 1);
      for (int i = 0; i < QTD_DADOS; i++)
      { //Percorre o array de n itens para inserir na arvore
        inseriu = arvoreBin_insereArv(arv, &item[i], cont, analise);
        if (!inseriu)
          cont--; //não foi possivel inserir, a posição no arv nn fica vazia
        cont++;
      }
    }
  }
  else
  { //Caso os dados estejam ordenados ascendentemente ou descendentemente
    updateTranferencias_pre(analise, 1);
    while (fread(item, sizeof(TipoItem), QTD_DADOS, arq)) //Pega n itens do arquivo
    {
      updateTranferencias_pre(analise, 1);
      for (int i = 0; i < QTD_DADOS; i++)
      {
        inseriu = arvoreBin_insereArvOrd(arv, &item[i], cont, analise);
        if (!inseriu)
          cont--; //não foi possivel inserir, a posição no arv nn fica vazia
        cont++;
      }
    }
  }

  fclose(arv);
  fclose(arq);
  finalizaContagemTempo(analise);
  updateTempo_pre(analise);

  iniciaContagemTempo(analise);
  arv = fopen("data_arv.bin", "rb");
  int rtr = arvoreBin_pesquisa(arv, itemP, analise);
  fclose(arv);
  finalizaContagemTempo(analise);
  updateTempo_pos(analise);
  return rtr;
}

TipoNode arvoreBin_criaNovoNode(TipoItem *item)
{
  TipoNode aux;
  aux.item = *item;
  aux.esq = -1;
  aux.dir = -1;
  return aux;
}

int arvoreBin_pesquisa(FILE *arv, TipoItem *itemPesq, Analise *analise)
{
  TipoNode node;
  if (!fread(&node, sizeof(TipoNode), 1, arv))
  {
    return 0;
  }

  long int desloc;
  int filhoEsq = 1, filhoDir = 1;

  while (1)
  {
    updateComparacoes_pos(analise, 1);
    if (itemPesq->chave < node.item.chave && filhoEsq != -1)
    {
      desloc = node.esq * sizeof(TipoNode);
      fseek(arv, desloc, SEEK_SET);
      fread(&node, sizeof(TipoNode), 1, arv); //Lê o filho a esquerda
      filhoEsq = node.esq;
      filhoDir = node.dir;
      updateTranferencias_pos(analise, 1);
    }
    else if (itemPesq->chave > node.item.chave && filhoDir != -1)
    {
      updateComparacoes_pos(analise, 1);
      desloc = node.dir * sizeof(TipoNode);
      fseek(arv, desloc, SEEK_SET);
      fread(&node, sizeof(TipoNode), 1, arv); //Lê o filho a direita
      filhoEsq = node.esq;
      filhoDir = node.dir;
      updateTranferencias_pos(analise, 1);
    }
    else if (itemPesq->chave == node.item.chave)
    { // Analisando folhas
      updateComparacoes_pos(analise, 1);
      *itemPesq = node.item;
      return 1;
    }else{
      updateComparacoes_pos(analise, 1);
      return 0;
    } 
  }
}



int arvoreBin_insereArv(FILE *arv, TipoItem *item, int pos, Analise *analise)
{
  if (pos == 0)
  { //Arvore vazia
    TipoNode node;
    node = arvoreBin_criaNovoNode(item);
    fseek(arv, 0, SEEK_SET);
    fwrite(&node, sizeof(TipoNode), 1, arv);
    updateTranferencias_pre(analise, 1);
    return 1;
  }
  else
  {
    TipoNode node;
    TipoNode root;
    long desloc;
    int posNodePai = 0;
    //int cond = 0;
    node = arvoreBin_criaNovoNode(item); //Cria o novo nó a ser inserido

    fseek(arv, 0, SEEK_SET);                //Retorna para o inicio
    fread(&root, sizeof(TipoNode), 1, arv); //Lê a raiz
    updateTranferencias_pre(analise, 1);

    while (1)
    { //Procurar o item pai
      updateComparacoes_pre(analise, 1);
      if (item->chave < root.item.chave)
      { //Insere à esquerda
        if (root.esq != -1)
        { //O node contem filho a esquerda
          posNodePai = root.esq;
          desloc = root.esq * sizeof(TipoNode);

          fseek(arv, desloc, SEEK_SET);           //Desaloca o ponteiro do arquivo para o filho a esquerda
          fread(&root, sizeof(TipoNode), 1, arv); //Lê o node a esquerda para retornar o loop
          updateTranferencias_pre(analise, 1);
        }
        else
        {
          root.esq = pos;
          desloc = posNodePai * sizeof(TipoNode);
          fseek(arv, desloc, SEEK_SET);            //Volta para a posicao do item pai
          fwrite(&root, sizeof(TipoNode), 1, arv); //Reescreve a linha do item pai
          updateTranferencias_pre(analise, 1);

          desloc = pos * sizeof(TipoNode);
          fseek(arv, desloc, SEEK_SET);
          fwrite(&node, sizeof(TipoNode), 1, arv); //Registra o nó no arquivo
          updateTranferencias_pre(analise, 1);
          return 1;
        }
      }
      else if (item->chave > root.item.chave)
      { //Insere à direita, não consisera itens iguais
        updateComparacoes_pre(analise, 1);
        if (root.dir != -1)
        { //O node contem filho a esquerda
          posNodePai = root.dir;
          desloc = root.dir * sizeof(TipoNode);
          fseek(arv, desloc, SEEK_SET);           //Desaloca o ponteiro do arquivo para o filho a esquerda
          fread(&root, sizeof(TipoNode), 1, arv); //Lê o node a esquerda para retornar o loop
          updateTranferencias_pre(analise, 1);
        }
        else
        {
          updateComparacoes_pre(analise, 1); // uma vez do else if acima
          root.dir = pos;
          desloc = posNodePai * sizeof(TipoNode);
          fseek(arv, desloc, SEEK_SET);            //Volta para a posicao do item pai
          fwrite(&root, sizeof(TipoNode), 1, arv); //Reescreve a linha do item pai
          updateTranferencias_pre(analise, 1);

          desloc = pos * sizeof(TipoNode);
          fseek(arv, desloc, SEEK_SET);
          fwrite(&node, sizeof(TipoNode), 1, arv); //Registra o nó no arquivo
          updateTranferencias_pre(analise, 1);
          return 1;
        }
      }
      else
      { // itens iguais
        return 0;
      }
    }
  }

  return 0;
}

int arvoreBin_insereArvOrd(FILE *arv, TipoItem *item, int pos, Analise *analise)
{
  if (pos == 0)
  { //Arvore vazia
    TipoNode node;
    node = arvoreBin_criaNovoNode(item);
    fseek(arv, 0, SEEK_SET);
    fwrite(&node, sizeof(TipoNode), 1, arv);
    updateTranferencias_pre(analise, 1);
    return 1;
  }
  else
  {
    TipoNode node;
    TipoNode root;
    long desloc;
    int posNodePai = (pos - 1);
    node = arvoreBin_criaNovoNode(item); //Cria o novo nó a ser inserido

    desloc = posNodePai * sizeof(TipoNode);
    fseek(arv, desloc, SEEK_SET);           //Retorna para a linha anterior
    fread(&root, sizeof(TipoNode), 1, arv); //Lê a raiz
    updateTranferencias_pre(analise, 1);

    updateComparacoes_pre(analise, 1);
    if (item->chave < root.item.chave && root.esq == -1)
    { //Insere à esquerda
      root.esq = pos;
      desloc = posNodePai * sizeof(TipoNode);
      fseek(arv, desloc, SEEK_SET);            //Volta para a posicao do item pai
      fwrite(&root, sizeof(TipoNode), 1, arv); //Reescreve a linha do item pai
      updateTranferencias_pre(analise, 1);

      desloc = pos * sizeof(TipoNode);
      fseek(arv, desloc, SEEK_SET);
      fwrite(&node, sizeof(TipoNode), 1, arv); //Registra o nó no arquivo
      updateTranferencias_pre(analise, 1);
      return 1;
    }
    else if (item->chave > root.item.chave && root.dir == -1)
    { //Insere à direita, não consisera itens iguais
      updateComparacoes_pre(analise, 1);

      root.dir = pos;
      desloc = posNodePai * sizeof(TipoNode);
      fseek(arv, desloc, SEEK_SET);            //Volta para a posicao do item pai
      fwrite(&root, sizeof(TipoNode), 1, arv); //Reescreve a linha do item pai
      updateTranferencias_pre(analise, 1);

      desloc = pos * sizeof(TipoNode);
      fseek(arv, desloc, SEEK_SET);
      fwrite(&node, sizeof(TipoNode), 1, arv); //Registra o nó no arquivo
      updateTranferencias_pre(analise, 1);
      return 1;
    }
    else
    {                                    // itens iguais
      updateComparacoes_pre(analise, 1); //conta um vez no else if acima
      return 0;
    }
  }

  return 0;
}

void arvoreBin_imprimeArv()
{
  FILE *arv = fopen("data_arv.bin", "rb");
  if (arv == NULL)
  {
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }

  TipoNode node;

  while (fread(&node, sizeof(TipoNode), 1, arv))
  {
    printf("%d - %d - %d\n", node.esq, node.item.chave, node.dir);
  }

  fclose(arv);
}