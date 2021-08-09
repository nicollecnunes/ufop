#include "prioridade.h"
#include <stdio.h>

int main ()
{
	int n, m, index = 0, demorado = 0;
	TipoCaixa *heap = NULL;
	int timeMax = 0, tAtual = 0;

	//ler n e m
	scanf("%d %d", &n, &m);
	//alocar o vetor para o heap com tamanho n
	heap = alocaVetor(heap, n);
	int cesta[m];

	//ler o tempo de atendimento de cada caixa
	//criar a fila de prioridades
	//a principio, cada caixa esta disponivel no tempo zero
	Heap_Constroi(heap, n);

	for (int i =0; i<m; i++){
		scanf("%d", &cesta[i]);
	}

	for (int x = 0; x<m; x++){
		if(x < n){
			heap[x].livre = 0;
			heap[x].timeused = heap[x].timeused + cesta[x] * heap[x].time;
			//printf("1) colocando o funcionario %d ocupado. o tempo dele eh %d e a cesta tem %d itens... == %d\n", x, heap[x].time, cesta[x], heap[x].timeused);
			index = x;
		}else{
			index = Heap_Refaz(heap, n);
			heap[index].timeused = heap[index].timeused + cesta[x] * heap[index].time;
			//printf("2) foi para o caixa %d que agora tem tempo %d\n", index, heap[index].timeused);
		}

		if(timeMax < heap[index].timeused){
			timeMax =  heap[index].timeused;
			//printf("demorou mt, o novo tempo maximo agora eh esse ai (%d)\n", timeMax);
			tAtual = timeMax;
		}
	}

	//desalocar o vetor do heap
	heap = desalocaVetor(heap);
	
	//imprimir a resposta
	printf("%d\n",timeMax);
	return 0;
}
