# ifndef buscabinaria_h
# define buscabinaria_h

long long *alocaVetor(long long *vetor, int n);

long long *desalocaVetor(long long *vetor);

int VetorBusca(long long *vetor, long x, int TAM);

int BuscaBinaria(long long *vetor, int esq, int dir, int x);

void mergesort(long long *vetor, int l, int r);

void merge(long long *vetor, int l, int m, int r);;

void ordenacao(long long *vetor, int n);

# endif