# ifndef corretor_h
# define corretor_h

typedef struct subm TADsubm;

typedef struct c TADcorr;

void lerQuantidade(int *n);

TADsubm *alocaSubm(TADsubm *S, int n);

TADsubm *desalocaSubm(TADsubm *S);

TADcorr *alocaCorr(TADcorr *S, int n);

TADcorr *desalocaCorr(TADcorr *S);

int testaCorreto(char julg[]);

void lerSubm(TADsubm *S, int n, int *c, TADcorr *C);

void printSaida(TADsubm *S, int n, int c, int p);

void calculaP(int *p, TADsubm *S, int n, TADcorr *C);

# endif