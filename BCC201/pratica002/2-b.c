/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 2 B
*/

#include <stdio.h>
#include <math.h>
int main(){
	printf("*****PRODUTO DO PRIMEIRO PELO QUADRADO DO SEGUNDO*****\n");
	double n1,n2,r;
	printf("Digite o primeiro e o segundo número\n");
 	scanf("%lf%lf",&n1, &n2);
	r = n1 * pow(n2,2);
	printf("RESULTADO = %lf\n", r);
	return 0;
}