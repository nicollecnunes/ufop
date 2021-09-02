/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 2*/

#include <stdio.h>
int main(){

	int m[3][3] = {{ 1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, a=0,j,i;

	for(i=0; i<3; i++){
		a = a + m[i][1];
	}
	printf("SOMA DOS ELEMENTOS DA 1ª COLUNA: %d\n", a);
	
	a=1;
	for(i=0; i<3; i++){
		a = a * m[1][i];
	}
	printf("PRODUTO DA 1ª LINHA: %d\n", a);

	a=0;
	for (i=0; i<3; i++){
		for (j=0;j<3;j++){
			a = a + m[i][j];
		}
	}
	printf("SOMA DE TODOS: %d\n", a);
		
	return 0;
}