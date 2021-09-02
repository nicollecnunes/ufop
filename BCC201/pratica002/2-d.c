/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 2 D
*/

#include <stdio.h>
#include <math.h>
int main(){
	printf("*****RAIZ DA SOMA DOS QUADRADOS*****\n");
	double n1,n2,r;
	printf("Digite o primeiro e o segundo número\n");
 	scanf("%lf%lf",&n1, &n2);
	r = sqrt(pow(n1,2) + pow(n2,2));
	printf("RESULTADO = %lf\n", r);
	return 0;
}