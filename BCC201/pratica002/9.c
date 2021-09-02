/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 9
*/

#include <stdio.h>
#include <math.h>
int main(){
	double k,m,x,a;
	printf("Digite a constante elástica\n");
 	scanf("%lf",&k);
 	printf("Digite a massa do corpo\n");
 	scanf("%lf",&m);
 	printf("Digite a posição inicial\n");
 	scanf("%lf",&x);
 	a = (k*x)/m;
 	printf("Aceleração = %.1lfm/s²\n", a);
	return 0;
}

