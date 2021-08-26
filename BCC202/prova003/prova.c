#include <stdio.h>

int main(){
	char matricula[10];
	scanf("%s", matricula);
	printf("lida [%s]\n",matricula);

	unsigned int soma = 0;
	for(int i = 0; i<9; i++){
		soma = soma + (unsigned int) matricula[i];
	}

	printf("soma: %d\n", soma);
	printf("chave: %d\n", soma%7);

	return 0;
}