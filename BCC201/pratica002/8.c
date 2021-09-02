/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 8
*/

#include <stdio.h>
#include <math.h>
int main(){
	const double g = 9.807;
	double t,v,s;
	printf("Digite o instante de tempo\n");
 	scanf("%lf",&t);
 	v = g * t;
 	s = (g * pow(t,2)) / 2;
 	printf("Velocidade = %.1lfm/s\n", v);
 	printf("Distância = %.1lfm\n", s);

	return 0;
}

