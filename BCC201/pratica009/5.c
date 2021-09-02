/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 5*/

#include <stdio.h>

void maior_menor(int *v, int *maior, int *menor, int n);
void maior_menor(int *v, int *maior, int *menor, int n){
	int i=0;
	*maior = v[0];
	*menor = v[0];
	while (i<n){
		if (v[i]>*maior){
			*maior = v[i];
		}
		if (v[i]<*menor){
			*menor = v[i];
		}

		i++;
	}

}


int main(){
	int n=101,a=0, maior, menor;
	printf("Digite o valor de N\n");
	scanf("%d",&n);

	int v[n];

	while(a<n){
		printf("Digite o valor na %dª posição\n", a+1);
		scanf("%d",&v[a]);
		a++;
	}
	maior_menor(v, &maior, &menor, n);
	printf("MAIOR: %d\n", maior);
	printf("MENOR: %d\n", menor);

	return 0;
}