/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 1*/

#include <stdio.h>
#include <math.h>

int main(){
	double p, h, imc;
	printf("Digite seu peso em kg\n");
	scanf("%lf",&p);
	printf("Digite sua altura em metros\n");
	scanf("%lf",&h);
	imc = p / pow(h,2);
	printf("Seu IMC é: %lf\n",imc);
	if (imc <= 18.5){
		printf("Abaixo do peso\n");
	}else if ((imc > 18.5) && (imc <= 25)){
		printf("Peso normal\n");
	}else if ((imc > 25) && (imc <= 30)){
		printf("Acima do peso\n");
	}else if (imc > 30){
		printf("Obeso\n");
	}

}