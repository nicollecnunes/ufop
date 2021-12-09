#include "heap.h"

void heapRefaz(AlunoMarcas *v, int esq, int dir, Analise *a) { 
    int i =  esq;
    int j =  i*2 +  1; //j =  primeiro filho de i
    
    AlunoMarcas  aux =  v[i]; //aux =  no i (pai de j)
    
    while (j <= dir) { 
        //Checando qual filho é maior
        novaComparacao(a);
        if (j < dir && v[j].aluno.nota < v[j+1].aluno.nota && v[j].isMarked == v[j+1].isMarked){ 
            j++;
        }
        else if (j < dir && v[j].isMarked == 0 && v[j+1].isMarked == 1){
            novaComparacao(a);
            j++; 
        }
        //Checando se o pai é maior que o filho
        novaComparacao(a);
        if (aux.aluno.nota >=  v[j].aluno.nota && aux.isMarked == v[j].isMarked) 
            break;
        else if (aux.isMarked == 1 && v[j].isMarked == 0){
            novaComparacao(a);
            break; 
        }
        //trocando o pai com o filho maior
        v[i] = v[j];
        i =  j; 
        j =  i*2 + 1; 
    }
    v[i] =  aux;
}

void heapConstroi(AlunoMarcas  *v, int n, Analise *a) { 
    int esq;
    esq =  (n / 2) - 1; //esq =  nó anterior ao primeiro nó folha do heap
    while (esq >=  0) { 
        heapRefaz(v, esq, n-1, a);
        esq--;
    }
}

void heapSort(AlunoMarcas  *v, int n, Analise *a) {
    AlunoMarcas  aux;
    heapConstroi(v, n, a);
    while (n > 1) {
        aux =  v[n-1];
        v[n-1] =  v[0];
        v[0] =  aux;
        n--;
        heapRefaz(v, 0, n-1, a); //refaz o heap
    }
}