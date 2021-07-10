# ifndef pilha_h
# define pilha_h

typedef struct {
    char key;
} Item;

typedef struct celula {
	Item item;
	struct celula *pProx;
} Celula;

typedef struct {
    Celula *pHead;
    int tamanho;
} Pilha;

//Inicializa a lista
void Pilha_Inicia(Pilha *pilha);
//Retorna se a lista esta vazia
int Pilha_EhVazia(Pilha *pilha);
// Insere um item no inicio da lista
int Pilha_Push(Pilha *pilha, Item item);
// Retira o primeiro item da lista
int Pilha_Pop(Pilha *pilha, Item *item);
// Remove cada elemento de uma lista e libera a memória
void Pilha_Esvazia(Pilha *pilha);

void TLista_Imprime(Pilha *pilha);
# endif
