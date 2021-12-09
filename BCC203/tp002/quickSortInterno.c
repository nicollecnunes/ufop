#include "quickSortInterno.h"

// Escolha do pivo numa mediana de 3 valores
void pivo_mediana(Aluno *v, int esquerda, int direita, Analise *an)
{
    //procura a mediana entre esquerda, meio e direita
    int meio = (esquerda + direita) / 2;

    double a = v[esquerda].nota;
    double b = v[meio].nota;
    double c = v[direita].nota;

    int indice_do_meio; //índice da mediana

    // compara para saber qual o maior elemento. Menor elemento. E o elemento do meio.
    novaComparacao(an);
    if (a < b) 
    {
        novaComparacao(an);
        if (b < c) 
        {
            indice_do_meio = meio; // a < b < c

        } else 
        {
            novaComparacao(an);
            if (a < c) 
            {
                indice_do_meio = direita; //a < c < b

            } else 
            {
                novaComparacao(an);
                indice_do_meio = esquerda; //c < a < b

            }
        }
    } else 
    {
        novaComparacao(an);
        if (c < b) 
        {
            indice_do_meio = meio; //c < b < a 
        } else 
        {
            novaComparacao(an);
            if (c < a) 
            {
                indice_do_meio = direita; // b < c < a 
            } else {
                novaComparacao(an);
                indice_do_meio = esquerda; // b < a < c
            }
        }
    }
    troca(v, indice_do_meio, direita); //coloca o elemento da mediana na variavel direita


}

//Quicksort MEDIANA
void quickSort_mediana(Aluno *v, int esquerda, int direita, Analise *a)
{
    while(esquerda < direita)
    {
        if(direita - esquerda <= 10)
        {
            insertionSort(v, esquerda, direita, a);
            break;
        }
        else
        {
            int pivo = particao_mediana(v, esquerda, direita, a);

            if(pivo - esquerda < direita - pivo) // esquerda
            {
                quickSort_mediana(v, esquerda, pivo - 1, a);
                esquerda = pivo + 1;
            }
            else{
                quickSort_mediana(v, pivo + 1, direita, a); // direita
                direita = pivo - 1;
            }
        }
    }
}

// Particao do quicksort
int particao_mediana(Aluno *v, int esquerda, int direita, Analise *a) 
{
    pivo_mediana(v, esquerda, direita, a);

    double pivo = v[direita].nota; // colocamos o pivo no ultimo elemento
    int i = esquerda - 1;
    int j;
    
    // Os elementos que são menores ou iguais ao pivo, serão colocados do lado esquerdo
    for (j = esquerda; j <= direita - 1; j++) // da esquerda para a direita 
    {
        novaComparacao(a);
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
    int i;
    for (i = 0; i < tam; i++) 
    {
        printf("%lf ", v[i].nota);
    }
    printf("\n");
}

// Implementação do insertionSort
void insertionSort(Aluno *v, int esquerda, int direita, Analise *a)
{
    // Um número compara com o seu antecessor
    // Caso for maior, troca de posição e compara com todos os elementos que antecedem sucessivamente
    int i, j;
    Aluno aux;

    for(i = esquerda + 1; i <= direita; i++)
    {
        aux = v[i];
        j = i;
        
        while(j > esquerda && v[j-1].nota > aux.nota)
        {
            novaComparacao(a);
            v[j] = v[j-1];
            j--;
        }

        v[j] = aux;
    }
}

