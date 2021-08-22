# ifndef buscabinaria_h
# define buscabinaria_h

int *alocaVetor(int *vetor, int n);

int *desalocaVetor(int *vetor);

void BuscaBinaria(int *vetor, int a, int n);

double AreaAcima(int *vetor, double meio, int n);

void mergesort(int *vetor, int l, int r);

void merge(int *vetor, int l, int m, int r);

void ordenacao(int *vetor, int n);

int inicializa(int *n, int *a);

void leitoresoma(int *vetor, int n, int *area);

# endif