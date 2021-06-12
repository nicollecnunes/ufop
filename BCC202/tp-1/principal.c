#include "corretor.h"
#include<stdio.h>

int main(){
	int n, c=0;
	TADsubm *S = NULL;

	lerQuantidade(&n);
	S = alocaSubm(S, n);
	lerSubm(S, n, &c);
	printSaida(S, n, c);
	S = desalocaSubm(S);

	return 0;
}