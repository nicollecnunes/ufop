# ifndef prioridade_h
# define prioridade_h

typedef struct{
	int time;
	int index;
	int timeused;
	int livre;
} TipoCaixa;

//Manter como especificado
TipoCaixa *alocaVetor(TipoCaixa *heap, int n);

//Manter como especificado
TipoCaixa *desalocaVetor(TipoCaixa *heap);

//Manter como especificado
void Heap_Constroi(TipoCaixa *heap, int n);

int Heap_Refaz(TipoCaixa *heap, int n);
# endif
