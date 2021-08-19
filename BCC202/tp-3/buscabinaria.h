# ifndef buscabinaria_h
# define buscabinaria_h

long long *alocaVetor(long long *vetor, int n);

long long *desalocaVetor(long long *vetor);

int VetorBusca(long long *vetor, long x, int TAM);

int BuscaBinaria(long long *vetor, int esq, int dir, int x);

# endif