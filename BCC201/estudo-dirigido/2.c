/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 2*/

#include <stdio.h>
#include <math.h>

float vol(float raio);

float vol(float raio){
	float pi = 3.141592693589;
	return  (4 * pi *pow(raio,3)/3);
}

int main(){
	float v, r;
	printf("Digite o raio \n");
	scanf("%f",&r);
	v = vol(r);
	printf("%.2f\n",v);
	return 0;
}