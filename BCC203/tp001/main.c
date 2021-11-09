#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "arvBinaria.h"
#include "tratamentoErros.h"
#include "gArquivo.h"
#include "sequencial.h"
#include "arvoreBEstrela.h"
#include "arvoreb.h"
#include "desempenho.h"

int main(int argc, char *argv[])
{
    if (argc < 6)
    {
        printf("Por favor, informe todos os comandos de execucao\n");
        return -1;
    }

    char pesquisa[10];
    int metodo = atoi(argv[2]);     // (1) acesso sequencial indexado, (2) árvore binária de pesquisa, (3) árvore B e (4) árvore B*;
    int quantidade = atoi(argv[3]); // representa a quantidade de registros do arquivo considerado;
    int situacao = atoi(argv[4]);   // 1 (arquivo ordenado ascendentemente), 2 (arquivo ordenado descendentemente) ou 3 (arquivo desordenado);
    int chave = atoi(argv[5]);      // representa a chave a ser pesquisada no arquivo considerado;

    Desempenho d;

    strcpy(pesquisa, argv[1]); // palavra "pesquisa"

    // comando de execução:
    // pesquisa <método> <quantidade> <situação> <chave> [-P]

    if (tratarErros(argc, argv) == -1)
    {
        printf("Finalizando a execucao...\n");
        return -1;
    }

    // criando arquivo
    TRegistro *itens = (TRegistro *)malloc(quantidade * sizeof(TRegistro));
    geradorArquivo(quantidade, situacao, itens);
    // printf("Arquivo .bin criado.\n");

    TRegistro item;
    item.chave = chave;

    if (metodo == 1)
    { // acesso sequencial indexado
        TRegistro registro;

        if (!busca_sequencial(chave, &registro, &d, situacao))
        {
            printf("Registro não encontrado\n");
            resultadoDesempenho(&d);
            return 0;
        }

        if (argc == 7 && strcmp(argv[5], "[-P]"))
        {
            printf("\n\nREGISTRO:\n");
            printf("CHAVE: %d\n", registro.chave);
            printf("DADO 1: %ld\n", registro.dado1);
            printf("DADO 2: %s\n", registro.dado2);
            printf("DADO 3: %s\n\n", registro.dado3);
        }
    }

    else if (metodo == 2)
    { // arvore binaria
        if (!arvBinariaExterna(&item, situacao, &d))
        {
            printf("Registro não encontrado :\n");
            resultadoDesempenho(&d);
            return 0;
        }

        if (argc == 7 && strcmp(argv[5], "[-P]"))
        {
            printf("\n\nREGISTRO:\n");
            printf("CHAVE: %d\n", item.chave);
            printf("DADO 1: %ld\n", item.dado1);
            printf("DADO 2: %s\n", item.dado2);
            printf("DADO 3: %s\n\n", item.dado3);
        }

        // arvBinariaPrint();
    }
    else if (metodo == 3)
    { // arvore B
        item.chave = chave;
        if (!arvBExterna(&item, quantidade, &d))
        {
            printf("Registro nao encontrado :\n");
            return 0;
        }

        if (argc == 7 && strcmp(argv[5], "[-P]"))
        {
            printf("\n\nREGISTRO:\n");
            printf("CHAVE: %d\n", item.chave);
            printf("DADO 1: %ld\n", item.dado1);
            printf("DADO 2: %s\n", item.dado2);
            printf("DADO 3: %s\n\n", item.dado3);
        }
    }
    else if (metodo == 4)
    { // arvore B estrela
        if (!arvExternaBEstrela(&item, situacao, quantidade, &d))
        {
            printf("Registro nao encontrado :\n");
            return 0;
        }

        if (argc == 7 && strcmp(argv[5], "[-P]"))
        {
            printf("\n\nREGISTRO:\n");
            printf("CHAVE: %d\n", item.chave);
            printf("DADO 1: %ld\n", item.dado1);
            printf("DADO 2: %s\n", item.dado2);
            printf("DADO 3: %s\n\n", item.dado3);
        }
    }

    printf("Registro Encontrado\n");
    resultadoDesempenho(&d);

    return 0;
}