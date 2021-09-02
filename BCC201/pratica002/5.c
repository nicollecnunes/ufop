/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 5
*/

#include <stdio.h>
#include <math.h>
int main(){
	double n;
	int i;
	printf("Digite o número\n");
 	scanf("%lf",&n);
 	i = trunc(n);
 	printf("PARTE INTEIRA = %d\n", i);
 	printf("PARTE DECIMAL = %lf\n", n - i);
	return 0;
}

