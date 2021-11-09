#include "tratamentoErros.h"

int tratarErros(int argc, char* argv[]){
    char pesquisa[10];
    int metodo;
    int quantidade;
    int situacao;

    strcpy(pesquisa, argv[1]);  // tem que ser a palavra "pesquisa"
    if (strcmp(pesquisa, "pesquisa")){
        printf("O comando digitado foi: %s (argv[1])\n", pesquisa);
        printf("Comando invalido. Comandos disponiveis:\n- pesquisa");
        return -1;
    }

    metodo = atoi(argv[2]);
    if (metodo != 1 && metodo != 2 && metodo != 3 && metodo != 4){
        printf("O metodo digitado foi: %d (argv[2])\n", metodo);
        printf("Metodo invalido. Metodos disponiveis:\n(1) acesso sequencial indexado\n(2) arvore binaria de pesquisa\n(3) arvore B\n(4) arvore B*");
        return -1;
    }

    quantidade = atoi(argv[3]);
    if (quantidade <= 0){
        printf("O arquivo nao possui dados (quantidade = 0)\n");
        return -1;
    }

    situacao = atoi(argv[4]);
    if (situacao != 1 && situacao != 2 && situacao != 3){
        printf("A situacao digitada foi: %d (argv[4])\n", situacao);
        printf("Situacao invalida. Situacoes disponiveis:\n1 (arquivo ordenado ascendentemente)\n2 (arquivo ordenado descendentemente)\n3 (arquivo desordenado aleatoriamente)");
        return -1;
    }

    if (argc == 7 && strcmp(argv[5], "[-P]")){
        printf("Tem o [-P]\n");
        // [-P] representa um argumento opcional que deve ser colocado quando se deseja que as chaves de
        // pesquisa dos registros do arquivo considerado sejam apresentadas na tela.
    }

    return 0;
}