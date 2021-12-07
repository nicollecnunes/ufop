#include "balancedBlock.h"

void mainBlock(Aluno *v1, int quantidade){
    int pointer = 0;
    FILE *blocos = fopen("blocos.bin", "wb");

    while(quantidade){
        readBlocks(v1, pointer);
        ordenateBlocks(v1);

		fwrite(v1, sizeof(Aluno), 20, blocos);

        pointer++;
        quantidade = quantidade - 20;
    }

    fclose(blocos);
}

void readBlocks(Aluno *v1, int pointer){
    FILE *arqBin = fopen("PROVAO.bin", "rb");
    int position = pointer * 20;

    fseek(arqBin, position*sizeof(Aluno), SEEK_SET);
    
    
    if(!fread(v1, sizeof(Aluno), 20, arqBin)){
        printf("Erro no primeiro bloco\n");
    }
    
    fclose(arqBin);
}

void ordenateBlocks(Aluno *v1)
{
    printf("************************* QUICKSORT ************************\n\n");

    // printf("Digite o tamanho do vetor que você deseja ordenar:\n");
    // int tamanho_vetor;
    // scanf("%d", &tamanho_vetor);

    // printf("\n************************************************************\n");

    // printf("\nDigite\n");
    // printf("1 - Caso queira um vetor com valores aleatorios\n2 - Para escolher os valores do vetor\n\n");
    // int opcode;
    // scanf("%d", &opcode);

    // printf("\n************************************************************\n");

    // int vetor[tamanho_vetor];

    // preencher_vetor(vetor, tamanho_vetor, opcode);

    printf("\n************************************************************\n\n");

    printf("Vetor sem ordenar: ");
    imprimir(v1, 20);

    quickSort_mediana(v1, 0, 20 - 1);

    printf("\nVetor ordenado: ");
    imprimir(v1, 20);

    printf("\n************************************************************\n\n");
}

// void fitas(Aluno *v1, Aluno *v2, Aluno *v3, Aluno *v4, int pointer){

// }