# ifndef ordenacao_h
# define ordenacao_h

//void ordenacao(int *vetor, int n, int *movimentos);
void mergesort(int *vetor, int l, int r, int *movimentos);

int *alocaVetor(int *vetor, int n);

void merge(int *vetor, int l, int m, int r, int *movimentos);

void ordenacao(int *vetor, int n, int *movimentos);
//Manter como especificado
int *desalocaVetor(int *vetor);

void preenche(int *vetor, int n);

void vencedor(int movimentos);

# endif
