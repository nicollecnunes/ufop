#include "Files.h"
#include "Util.h"
#include "balancedBlock.h"
#include "quickSortExterno.h"

//  ordena <metodo> <quantidade> <situacao> [-P]

// <método>:
    // 1. Intercalação (2f fitas) com qualquer método de ordenação interna
    // 2. Intercalação (2f fitas) com a técnica de seleção por substituição
    // 3. Quicksort externo
// <quantidade>:
    // representa a quantidade de alunos (linhas do arquivo texto) a serem ordenados;
// <situação>:
    // 1. arquivo ordenado ascendentemente
    // 2. arquivo ordenado descendentemente
    // 3. arquivo desordenado
// [-P]:
    // argumento opcional que deve ser colocado quando se deseja que os dados dos
    // alunos a serem ordenados e o resultado da ordenação realizada sejam apresentados na tela.

int main(int argc, char *argv[])
{
    // Verificando quantidade e validade dos argumentos passados
    if (tratarErros(argc, argv) == -1)
    {
        printf("Finalizando a execucao devido ao erro...\n");
        return -1;
    }

    // Verificando a existencia do argumento opcional [-P]
    short deveImprimir;
    if (temArgumentoOpcional(argc, argv)) deveImprimir = TRUE;
    else deveImprimir = FALSE;


    // inicializando os ponteiros de arquivos
    FILE *arq;
    FILE *arqEi;
    FILE *arqLi;
    FILE *arqLEs;
    FILE *resultado;
    

    Aluno *block = (Aluno*) malloc(20 * sizeof(Aluno));

    // armazenando os argumentos em suas respectivas variaveis
    char ordena[10];
    strcpy(ordena, argv[1]);

    int metodo = atoi(argv[2]);
    int quantidade = atoi(argv[3]);
    int situacao = atoi(argv[4]);

    // -------------------- SITUACAO --------------------
    char nomeTxt[14];
    if (situacao == 1) // ordenado ascendentemente
        strcpy(nomeTxt, "PROVAO1.txt");
    else if (situacao == 2) // ordenado descendentemente
        strcpy(nomeTxt, "PROVAO2.txt");
    else if (situacao == 3) // desordenado
        strcpy(nomeTxt, "PROVAO.TXT");

    if ((arq = fopen(nomeTxt, "r+")) == NULL)
    {
        printf("Erro na abertura do arquivo %s\n", nomeTxt);
        return -1;
    }

    // -------------------- METODO DE ORDENACAO --------------------
    if (metodo == 1) // IB + qualquer metodo de ordenacao interna
    {
        FILE *arquivoAleatorio = fopen("PROVAO.bin", "wb");
        printf("METODO DE ORDENACAO: Intercalacao Balanceada com Ordenacao Interna\n");
        txt2Bin(arq, arquivoAleatorio, quantidade);
        fclose(arquivoAleatorio);
        mainBlock(block, quantidade);
        FILE *arquivoAleatorioLer = fopen("blocos.bin", "rb");
        FILE *arquivoAleatorioTXT = fopen("blocos.txt", "w+");
        bin2Txt(arquivoAleatorioLer, arquivoAleatorioTXT, quantidade);
        fclose(arquivoAleatorioLer);
        fclose(arquivoAleatorioTXT);
        // criarArquivos(&arqLEs, &arqLi, &arqEi, &arq, situacao, quantidade);
        // [TODO: chamar as funções necessárias]
        // [TODO: verificar se tem o [-P] (if (deveImprimir)), pra imprimir arqLi antes da ordenacao e o resultado depois da ordenacao]
        // [TODO: converter pra arquivo de texto?]
    }
    else if (metodo == 2) // IB + selecao por substituicao
    { 
        printf("METODO DE ORDENACAO: Intercalacao Balanceada com Seleção por Substituição\n");
        // criarArquivos(&arqLEs, &arqLi, &arqEi, &arq, situacao, quantidade);
        // [TODO: chamar as funções necessárias]
        // [TODO: verificar se tem o [-P] (if (deveImprimir) ), pra imprimir arqLi antes da ordenacao e o resultado depois da ordenação]
        // [TODO: converter pra arquivo de texto?]
    }
    else if (metodo == 3) // quicksort externo
    {
        printf("METODO DE ORDENACAO: Quicksort Externo\n");
        // criarArquivos(&arqLEs, &arqLi, &arqEi, &arq, situacao, quantidade);
        // [TODO: converter pra arquivo de texto?]
        if (deveImprimir)
        {
            printf("Antes de ordenar:\n");
            imprimeArquivo(arqLi, quantidade);
        }
        
        quickSortExterno(&arqLi, &arqEi, &arqLEs, 1, quantidade);

        fclose(arqEi);
        fclose(arqLEs);

        if (deveImprimir)
        {
            printf("Depois de ordenar:\n");
            imprimeArquivo(arqLi, quantidade);
        }

        rewind(arqLi);

        if((resultado = fopen("resultado.txt", "w+")) == NULL)
        {
            printf("Erro na abertura do arquivo RESULTADO.TXT\n");
            return -1;
        }

        bin2Txt(arqLi, resultado, quantidade);
        fclose(resultado);
    }

    fclose(arq);
    return 0;
}