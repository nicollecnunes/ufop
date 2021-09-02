/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 1*/

#include <stdio.h>

float Area(int raio);

float Area(int raio){
	float pi = 3.141592693589;
	return pi * raio * raio;
}

int main(){
	int r;
	float a;
	printf("Digite o raio \n");
	scanf("%d",&r);
	a = Area(r);
	printf("%.2f\n",a);
	return 0;

}