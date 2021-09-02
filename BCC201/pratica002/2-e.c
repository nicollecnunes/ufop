/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 2 E
*/

#include <stdio.h>
#include <math.h>
int main(){
	printf("*****SENO DA DIFERENÇA*****\n");
	double n1,n2,r;
	printf("Digite o primeiro e o segundo número\n");
 	scanf("%lf%lf",&n1, &n2);
	r = sin((n1-n2));
	printf("RESULTADO = %lf\n", r);
	return 0;
}