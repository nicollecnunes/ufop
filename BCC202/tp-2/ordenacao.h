# ifndef ordenacao_h
# define ordenacao_h


typedef struct {
    char nome[20];
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



void listaInicia(TLista *lista);

int listaEhVazia(TLista *lista);

void listaIncludeAntes(TLista *lista, TPais pais, char *str);

void listaIncludeFinal(TLista *lista, TPais pais);

void ordenaLista(TLista *lista, TPais *novo);

void TLista_Imprime(TLista *lista);

# endif
