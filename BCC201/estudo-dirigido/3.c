/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 3*/

#include <stdio.h>
#include <math.h>

float dolar(float real, float dol);

float dolar(float real, float dol){
	return  real / dol;
}

int main(){
	float dol, real;
	printf("Digite o valor em reais: \n");
	scanf("%f",&real);
	printf("Digite a cotação do dólar: \n");
	scanf("%f",&dol);
	printf("O valor convertido é: %.2f\n", dolar(real, dol));
	return 0;

}