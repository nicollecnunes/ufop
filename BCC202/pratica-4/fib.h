# ifndef fib_h
# define fib_h

typedef struct{
  int n;
  long long resultado;
  long long chamadas;
} TADfib;

long long fibonacci(int n, TADfib *f, int i);

void lerQuantidade(int *qtd);


TADfib *alocaFib(TADfib *f, int qtd);

//Manter como especificado
TADfib *desalocaFib(TADfib *f);

void lerCasos(TADfib *f, int qtd);


void imprimir(TADfib *f, int qtd);

# endif
