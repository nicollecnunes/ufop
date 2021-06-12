#include "duende.h"
#include<stdio.h>

int main(){
	int n;
	TADsubm *S = NULL;

	lerQuantidade(&n);
	S = alocaSubm(S, n);
	lerSubm(S, n);
	return 0;
}