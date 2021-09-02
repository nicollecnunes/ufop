/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 3
*/
#include <stdio.h>
#include <math.h>
int main(){
	printf("*****MÓDULO DO PRIMEIRO*****\n");
	double n1,n2,r;
	printf("Digite o primeiro e o segundo número\n");
 	scanf("%lf%lf",&n1, &n2);
	r = fabs(n1);
	printf("RESULTADO = %lf\n", r);
	return 0;
}