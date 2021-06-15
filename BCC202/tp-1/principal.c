#include "corretor.h"
#include<stdio.h>

int main(){
	int n, c=0, p=0;
	TADsubm *S = NULL;
	TADcorr *C=NULL;

	lerQuantidade(&n);
	S = alocaSubm(S, n);
	C = alocaCorr(C, n);
	lerSubm(S, n, &c, C);
	calculaP(&p, S, n, C);
	printSaida(S, n, c, p);
	S = desalocaSubm(S);
	C = desalocaCorr(C);

	return 0;
}