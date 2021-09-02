/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	printf("*****JOGO DE DADOS*****\n");
	int d1,d2;
	srand(time(NULL));
	d1 = (rand()  % 6 + 1 - 1) +1;
	d2 = (rand() % 6 + 1 - 1) +1;
	printf("PRIMEIRO DADO = %d\n", d1);
 	printf("PRIMEIRO DADO = %d\n", d2);
 	printf("SOMA = %d\n", d1+d2);
	return 0;
}

