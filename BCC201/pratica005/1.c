/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 1*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void convert(float c, float *f, float *k);
void convert(float c, float *f, float *k){
	*f = 1.8 * c + 32;
	*k = c +273.15;
}

int main(){
	float c,f,k;
	printf("Digite a temperatura em Celcius: \n");
	scanf("%f",&c);
	convert(c, &f, &k);
	printf("%.2f Celcius = %.2f Fahrenheit\n", c, f);
	printf("%.2f Celcius = %.2f Kewin\n", c, k);

	return 0;
}