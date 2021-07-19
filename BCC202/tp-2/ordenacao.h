# ifndef ordenacao_h
# define ordenacao_h

typedef struct pais TPais;

void lerQuantidade(int *qtd);

TPais *alocaPaises(TPais *P, int qtd);

void lerLista(TPais *P, int qtd);

void ordenaTudo(TPais *P, int qtd);

void imprimePaises(TPais *P, int qtd);

TPais *desalocaPaises(TPais *P);


# endif
