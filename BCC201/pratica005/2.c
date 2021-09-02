/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 2*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int calcr(float *a, float *b, float *c);
int calcr(float *a, float *b, float *c){
	float delta = pow(*b,2) - 4 * (*a) * (*c);
	if (delta >=0){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	float a,b,c;
	printf("Digite o valor de A, B e C respectivamente: \n");
	scanf("%f%f%f",&a,&b,&c);
	float d = pow(b,2) - 4 * a * c;
	calcr(&a, &b, &c);

	if (calcr(&a, &b, &c)==1){
		printf("X1 = %.2f\n", (((-b) + (sqrt(d))) / (a*2)));
		printf("X2 = %.2f\n", (((-b) - (sqrt(d))) / (a*2)));
	}else{
		printf("Não possui raízes reais\n");
	}

	return 0;
}