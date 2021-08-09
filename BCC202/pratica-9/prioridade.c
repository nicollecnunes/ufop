#include "prioridade.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
TipoCaixa *alocaVetor(TipoCaixa *heap, int n){
	for (int i = 0; i < n; i++){
   		heap = malloc (n * sizeof (TipoCaixa)) ;
	}
	return heap;
}

//Manter como especificado
TipoCaixa *desalocaVetor(TipoCaixa *heap){
	free(heap);
	return heap;
}

void Heap_Constroi(TipoCaixa *heap, int n){
	for (int i = 0; i < n; i++){
  		scanf("%d", &heap[i].time);
  		heap[i].index = i;
  		heap[i].timeused = 0;
  		heap[i].livre = 1;
  	}
}

int Heap_Refaz(TipoCaixa *heap, int n){
	//printf("procurando o primeiro a ficar livre\n");
	int first = 0;
	int tAtual = heap[0].timeused;
	for (int i = 0; i < n; i++){
		if (heap[i].timeused < tAtual){
			//printf("parece que o que acabou primeiro foi %d, com %dmin\n", i, heap[i].timeused);
			first = i;
			tAtual = heap[i].timeused;	
		}		
	}
	//heap[first].timeused = heap[first].timeused + 
	return first;
}

