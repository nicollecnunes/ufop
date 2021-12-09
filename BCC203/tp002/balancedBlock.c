#include "balancedBlock.h"
#include "Util.h"

void mainBlock(Aluno *v1, FitasPrimeiroMetodo *fitas, int quantidade, Analise *a){
    int pointer = 0; // responsável por identificar para onde o ponteiro de arquivo irá apontar
    // para a leitura dos blocos

    // abre as fitas binarias
    fitasBinariaModoEscrita(fitas, 1);
    int controlador_fitas = 0; // responsavel por controlar qual fita o bloco sera escrito
    while(quantidade > 0){
        // le blocos do arquivo
        readBlocks(v1, pointer, a);
        // ordena o vetor do bloco lido
        ordenateBlocks(v1, a);
        // escreve o vetor na fita
        novaEscrita(a);
        fwrite(v1, sizeof(Aluno), QUANTIDADE_MEMORIA_INTERNA, fitas->fita_entrada[controlador_fitas]);
        controlador_fitas++;
        
        // o controlador deve respeitar a quantidade de fitas, caso ele alcance a quantidade
        // voltamos com ele para 0
        if(controlador_fitas >= QUANTIDADE_FITAS)
            controlador_fitas = 0;

        pointer++;
        // responsavel por controlar o while
        quantidade -= QUANTIDADE_MEMORIA_INTERNA;
    }
    // fecha as fitas
    fechaFitas(fitas, 1);
}

void readBlocks(Aluno *v1, int pointer, Analise *a){
    FILE *arqBin = fopen("PROVAO.bin", "rb");

    // pointer anda de 1 em 1, mas lemos sempre um bloco de 20, portanto precisamos
    // multiplicar esse pointer por 20
    int position = pointer * QUANTIDADE_MEMORIA_INTERNA;

    fseek(arqBin, position*sizeof(Aluno), SEEK_SET);

    // lemos o bloco
    novaLeitura(a);
    if(!fread(v1, sizeof(Aluno), QUANTIDADE_MEMORIA_INTERNA, arqBin)){
        printf("Erro no primeiro bloco\n");
    }
    
    fclose(arqBin);
}

void ordenateBlocks(Aluno *v1, Analise *a)
{
    //printf("************************* Intercalação Balanceada ************************\n\n");
    //printf("Vetor sem ordenar: ");
    //imprimir(v1, QUANTIDADE_MEMORIA_INTERNA);

    // vai chamar a ordenação interna para o vetor de alunos

    quickSort_mediana(v1, 0, QUANTIDADE_MEMORIA_INTERNA - 1, a);

    //printf("\nVetor ordenado: ");
    //imprimir(v1, QUANTIDADE_MEMORIA_INTERNA);

    //printf("\n************************************************************\n\n");
}
