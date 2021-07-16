# ifndef ordenacao_h
# define ordenacao_h


typedef struct {
    char nome[50];
  	int ouro;
  	int prata;
  	int bronze;
} TPais;

typedef struct celula {
	TPais pais;
	struct celula *pProx;
} TCelula;

typedef struct {
    TCelula *pHead;
    TCelula *pTail;
    int tamanho;
} TLista;


void lerQuantidade(int *qtd);

void lerLista(TLista *lista, int qtd);

void listaInicia(TLista *lista);

int listaEhVazia(TLista *lista);

void listaIncludeFinal(TLista *lista, TPais pais);

void insertionOuro(TLista *lista, TPais *pais);

void insertionPrata(TLista *lista, TPais *pais);

void insertionBronze(TLista *lista, TPais *pais);

void TLista_Imprime(TLista *lista);


# endif
