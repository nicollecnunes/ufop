#include "corretor.h"
#include<stdio.h>

int main(){
	int n, c=0, p=0;
	TADsubm *S = NULL;

	lerQuantidade(&n);
	S = alocaSubm(S, n);
	lerSubm(S, n, &c);
	calculaP(&p, S, n);
	printSaida(S, n, c, p);
	S = desalocaSubm(S);

	return 0;
}