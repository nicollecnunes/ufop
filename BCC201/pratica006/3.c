/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 3*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int x, y, aux;
	printf("Digite os valores de X e Y: \n");
	scanf("%d%d",&x,&y);
	while (x>=y){
		printf("Digite os valores de X e Y: \n");
		printf("Erro: X deve ser menor que Y. \n");
		scanf("%d%d",&x,&y);
	}
	while ((x%2==1)||(y%2==1)){
		printf("Digite os valores de X e Y: \n");
		printf("Erro: Ambos devem ser pares. \n");
		scanf("%d%d",&x,&y);
	}
	aux = 0;
	while (y>=x){
	
		while (aux<x){
			printf("*");
			aux ++;
		}
		aux = 0;
		x++;
		printf("\n");
		
	}

	return 0;
}