#include "arvoreBinaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct tNo
{
  TItem item;
  int esq;
  int dir;
};


void gerarRegistros(int n, Registro *registros)
{
  srand(time(NULL));
  for (int i = 0; i < n; i++)
  {
    registros[i].indice = i + 1;
    registros[i].dado1 = rand() % 1000000000000;
    for (int j = 0; j < 1000; j++)
      registros[i].dado2[j] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random() % 26];
    for (int j = 0; j < 5000; j++)
      registros[i].dado3[j] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random() % 26];
  }
}

int arvoreBinaria(TItem *item, int situacao){
  TItem *item = criarArray(KDados);
  FILE *arv = fopen("data_arv.bin", "w+b");
  FILE *arq = fopen("data.bin", "rb");

  if (arv == NULL || arq == NULL)
  {
    printf("Ocorreu um erro\n");
    return -1;
  }

  int cont = 0;

  // dados ordenados
  if (situacao == 1) || (situacao == 2){
    while(fread(item, sizeof(TItem), KDados, arq)){
      for (int i = 0 ; i < KDados, i++){
        if(!(abInserirArvoreOrd(&item[i], arv, cont))){
          cont = cont - 1;
        }
        cont = cont + 1;
      }
    }
  }
  // dados desordenados
  else if(situacao == 3){
    while(fread(item, sizeof(TItem), KDados, arq)){
      for (int i = 0 ; i < KDados, i++){
        if(!(abInserirArvore(&item[i], arv, cont))){
          cont = cont - 1;
        }
        cont = cont + 1;
      }
    }
  }

  fclose(arv);
  fclose(arq);

  arv =  fopen("data_arv.bin", "rb");

  int retorno = abPesquisa(item, arv);
  fclose(arv);

  return retorno;
}

TNo abCriaNo(TItem *item){
  TNo aux;
  aux.item =  *item;

  aux.esq = -1;
  aux.dir = -1;

  return aux;
}