#include "quickSortInterno.h"

// Escolha do pivo numa mediana de 3 valores
void pivo_mediana(Aluno *v, int esquerda, int direita)
{
    //procura a mediana entre esquerda, meio e direita
    int meio = (esquerda + direita) / 2;

    double a = v[esquerda].nota;
    double b = v[meio].nota;
    double c = v[direita].nota;

    int indice_do_meio; //índice da mediana

    // compara para saber qual o maior elemento. Menor elemento. E o elemento do meio.
    if (a < b) 
    {
        if (b < c) 
        {
            indice_do_meio = meio; // a < b < c

        } else 
        {
            if (a < c) 
            {
                indice_do_meio = direita; //a < c < b

            } else 
            {
                indice_do_meio = esquerda; //c < a < b

            }
        }
    } else 
    {
        if (c < b) 
        {
            indice_do_meio = meio; //c < b < a 
        } else 
        {
            if (c < a) 
            {
                indice_do_meio = direita; // b < c < a 
            } else {
                indice_do_meio = esquerda; // b < a < c
            }
        }
    }
    troca(v, indice_do_meio, direita); //coloca o elemento da mediana na variavel direita


}

//Quicksort MEDIANA
void quickSort_mediana(Aluno *v, int esquerda, int direita)
{
    while(esquerda < direita)
    {
        if(direita - esquerda <= 10)
        {
            insertionSort(v, esquerda, direita);
            break;
        }
        else
        {
            int pivo = particao_mediana(v, esquerda, direita);

            if(pivo - esquerda < direita - pivo) // esquerda
            {
                quickSort_mediana(v, esquerda, pivo - 1);
                esquerda = pivo + 1;
            }
            else{
                quickSort_mediana(v, pivo + 1, direita); // direita
                direita = pivo - 1;
            }
        }
    }
}

// Particao do quicksort
int particao_mediana(Aluno *v, int esquerda, int direita) 
{
    pivo_mediana(v, esquerda, direita);

    double pivo = v[direita].nota; // colocamos o pivo no ultimo elemento
    int i = esquerda - 1;
    int j;
    
    // Os elementos que são menores ou iguais ao pivo, serão colocados do lado esquerdo
    for (j = esquerda; j <= direita - 1; j++) // da esquerda para a direita 
    {
        if (v[j].nota <= pivo) 
        {
            i = i + 1;
            troca(v, i, j);
        }
    }

    troca(v, i + 1, direita); // coloca o pivô na posição de ordenação

    return i + 1; //retorna a posição do pivô
}


// Auxiliares

// Coloca X no lugar de Y
void troca(Aluno *v, int x, int y)
{
    Aluno aux = v[x];
    v[x] = v[y];
    v[y] = aux;
}

// Impressão do vetor

void imprimir(Aluno *v, int tam) 
{
    for (int i = 0; i < tam; i++) 
    {
        printf("%lf ", v[i].nota);
    }
    printf("\n");
}

// Implementação do insertionSort
void insertionSort(Aluno *v, int esquerda, int direita)
{
    // Um número compara com o seu antecessor
    // Caso for maior, troca de posição e compara com todos os elementos que antecedem sucessivamente
    int j;
    Aluno aux;

    for(int i = esquerda + 1; i <= direita; i++)
    {
        aux = v[i];
        j = i;
        
        while(j > esquerda && v[j-1].nota > aux.nota)
        {
            v[j] = v[j-1];
            j--;
        }

        v[j] = aux;
    }
}

// Prenchee o vetor com números aleatorios de 0 a MAX
void sortear(int *v, int tam)
{
    srand(time(NULL));

    printf("\nVocê deseja números de 0 até quanto?\n");
    int max;
    scanf("%d", &max);

    for (int i = 0; i < tam; i++)
    {
        v[i] = rand() % max;
    }
}

// Pede o usuario para digitar os valores para preecher o vetor
void escolherValores(int *v, int tam)
{
    printf("\nDigite os valores que você deseja: ");
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &v[i]);
    }
}

// Opcode para prencheer o vetor com numeros aleatorios a escolha do usuario
void preencher_vetor(int *vetor, int tam, int opcode)
{
    if (opcode == 1)
    {
        sortear(vetor, tam);
    }
    else if (opcode == 2)
    {
        escolherValores(vetor, tam);
    }

    printf("\n************************************************************\n");

}

// Define se o pivo vai ser por meio aleatorio ou por mediana
void escolhaPivoMediana(Aluno *vetor, int tamanho_vetor)
{
    quickSort_mediana(vetor, 0, tamanho_vetor - 1);
}