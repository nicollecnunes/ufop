#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char pesquisa[10];
    int metodo;
    int quantidade;
    int situacao;
    int chave;

    // comando de execução:
    // pesquisa <método> <quantidade> <situação> <chave> [-P]

    strcpy(pesquisa, argv[1]);  // palavra "pesquisa"
    metodo = atoi(argv[2]);     // (1) acesso sequencial indexado, (2) árvore binária de pesquisa, (3) árvore B e (4) árvore B*
    quantidade = atoi(argv[3]); //representa a quantidade de registros do arquivo considerado
    situacao = atoi(argv[4]);   //1 (arquivo ordenado ascendentemente), 2 (arquivo ordenado descendentemente) ou 3 (arquivo desordenado aleatoriamente)
    chave = atoi(argv[5]);      // representa a chave a ser pesquisada no arquivo considerado;

    if (argc == 7 && strcmp(argv[5], "[-P]"))
    {
        printf("Tem o [-P]\n");
        // [-P] representa um argumento opcional que deve ser colocado quando se deseja que as chaves de
        // pesquisa dos registros do arquivo considerado sejam apresentadas na tela.
    }

    // tem que gerar o arquivo [A FAZER]

    if (metodo == 1)
    { //acesso sequencial indexado
        printf("Preencher a chamada do ACESSO SEQUENCIAL INDEXADO\n");
        // preencher a chamada :: [A FAZER]
    }
    else if (metodo == 2)
    { // arvore binaria
        printf("Preencher a chamada da ARVORE BINARIA\n");
    }
    else if (metodo == 3)
    { // arvore B
        printf("Preencher a chamada da ARVORE B\n");
        // preencher a chamada :: [A FAZER]
    }
    else if (metodo == 4)
    { // arvore B estrela
        printf("Preencher a chamada da ARVORE B ESTRELA\n");
        // preencher a chamada :: [A FAZER]
    }
    else
    {
        printf("Método inexistente\n");
        return -1;
    }

    printf("Registro Encontrado!! \n");

    return 0;
}