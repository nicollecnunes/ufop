/*
Antonio Alex Gomes Rodrigues - 19.1.4173
Arthur Mayan Faria de Almeida - 18.2.4149
Arthur Silva Lima - 20.1.4019
Bernardo Cavanellas Biondini - 20.1.4112
Leandro Libério Machado da Silva - 19.2.4074
Nicolle Canuto Nunes - 20.1.4022
*/


#include "Files.h"
#include "Util.h"
#include "balancedBlock.h"
#include "quickSortExterno.h"
#include "subBlock.h"

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
    int deveImprimir;
    if (temArgumentoOpcional(argc)) deveImprimir = TRUE;
    else deveImprimir = FALSE;

    // inicializando os ponteiros de arquivos
    FILE *arq;
    FILE *arqEi; // gerencia a escrita inferior
    FILE *arqLi; // gerencia a leitura inferior
    FILE *arqLEs; // gerencia o Leitura e escrita superiores
    FILE *resultado;

    // inicializando analise
    Analise a;
    iniciaAnalise(&a);
    

    Aluno *block = (Aluno*) malloc(QUANTIDADE_MEMORIA_INTERNA * sizeof(Aluno));
    AlunoMarcas *block2 = (AlunoMarcas*) malloc(QUANTIDADE_MEMORIA_INTERNA * sizeof(AlunoMarcas));

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
        printf("METODO DE ORDENACAO: Intercalacao Balanceada com Ordenacao Interna\n");

        FitasPrimeiroMetodo fitas;
        inicializaFitas(&fitas);
        // Transforma qualquer que seja o arquivo em binário  
        FILE *arqMet1 = fopen("PROVAO.bin", "wb");
        txt2Bin(arq, arqMet1, quantidade);
        fclose(arqMet1);
        
        iniciaTempo(&a);
        // chama a função que vai fazer a geração dos blocos
        mainBlock(block, &fitas, quantidade, &a);
        finalizaTempo(&a);

        transformaFitas(&fitas, quantidade);
        imprimirAnalise(&a);
        // [TODO: verificar se tem o [-P] (if (deveImprimir)), pra imprimir arqLi antes da ordenacao e o resultado depois da ordenacao]
        // [TODO: converter pra arquivo de texto?]
    }
    else if (metodo == 2) // IB + selecao por substituicao
    { 
        printf("METODO DE ORDENACAO: Intercalacao Balanceada com Seleção por Substituição\n");
        
        FitasPrimeiroMetodo fitas;
        inicializaFitas(&fitas);
        
        // Transforma qualquer que seja o arquivo em binário 
        FILE *arqMet1 = fopen("PROVAO.bin", "wb");
        txt2Bin(arq, arqMet1, quantidade);
        fclose(arqMet1);

        iniciaTempo(&a);
        // chama a função que vai fazer a geração dos blocos
        mainSubBlock(block2, &fitas, quantidade, &a);
        finalizaTempo(&a);

        transformaFitas(&fitas, quantidade);

        // FILE *arqMet12 = fopen("blocos.bin", "rb");
        // FILE *arqMet11 = fopen("blocos.txt", "w+");
        // bin2Txt(arqMet12, arqMet11, quantidade);
        // fclose(arqMet1);
        // fclose(arqMet11);
        // criarArquivos(&arqLEs, &arqLi, &arqEi, &arq, situacao, quantidade);
        // [TODO: chamar as funções necessárias]
        imprimirAnalise(&a);
        
        // [TODO: verificar se tem o [-P] (if (deveImprimir) ), pra imprimir arqLi antes da ordenacao e o resultado depois da ordenação]
        // [TODO: converter pra arquivo de texto?]
    }
    else if (metodo == 3) // quicksort externo
    {
        printf("METODO DE ORDENACAO: Quicksort Externo\n");
        criarArquivos(&arqLEs, &arqLi, &arqEi, &arq, situacao, quantidade);
        if (deveImprimir)
        {
            printf("Antes de ordenar:\n");
            // imprimeArquivo(arqLi, quantidade);
            printf("\n");
        }

        iniciaTempo(&a);

        // esq = 1 | dir = qtd
        quickSortExterno(&arqLi, &arqEi, &arqLEs, 1, quantidade, &a);
        finalizaTempo(&a);

        fclose(arqEi);
        fclose(arqLEs);
    
        if (deveImprimir)
        {
            printf("Depois de ordenar:\n");
            imprimeArquivo(arqLi, quantidade);
            printf("\n");
        }
        rewind(arqLi);


        if((resultado = fopen("resultado.txt", "w+")) == NULL)
        {
            printf("Erro na abertura do arquivo RESULTADO.TXT\n");
            return -1;
        }

        bin2Txt(arqLi, resultado, quantidade);

        fclose(resultado);
        fclose(arqLi);

        imprimirAnalise(&a);
        fclose(arqLi);
    }
    fclose(arq);
    return 0;
}