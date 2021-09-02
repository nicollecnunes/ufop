/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 2*/

#include <stdio.h>

int main(){
	int i=0, v[7], x;
	while(i<7){
		printf("Digite o %dº valor\n", i+1);
		scanf("%d",&v[i]);
		i++;
	}
	printf("\n===============FIM DA LEITURA===============\n", i+1);
	i=0;
	printf("Digite o valor a ser procurado\n", i+1);
	scanf("%d",&x);
	while(i<7){
		if(v[i]==x){
			printf("Valor encontrado na %dº posição.\n", i+1);
		}
		i++;
	}

	if(i==7){
		printf("O valor não foi encontrado.\n");
	}
	return 0;
}