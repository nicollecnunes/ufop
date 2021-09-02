/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 2 A
*/

#include <stdio.h>
int main(){
	printf("*****SOMA DE DOIS NÚMEROS*****\n");
	double n1,n2,r;
	printf("Digite o primeiro e o segundo número\n");
 	scanf("%lf%lf",&n1, &n2);
	r = n1 + n2;
	printf("RESULTADO = %lf\n", r);
	return 0;
}