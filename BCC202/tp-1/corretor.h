# ifndef corretor_h
# define corretor_h

typedef struct subm TADsubm;

void lerQuantidade(int *n);

TADsubm *alocaSubm(TADsubm *S, int n);

TADsubm *desalocaSubm(TADsubm *S);

int testaCorreto(char julg[]);

void lerSubm(TADsubm *S, int n, int *c);

void printSaida(TADsubm *S, int n, int c);

# endif