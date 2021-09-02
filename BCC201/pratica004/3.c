/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 3*/

#include <stdio.h>
#include <math.h>

int main(){
	int cod;
	double sal, nsal;
	printf("Digite seu salário\n");
	scanf("%lf",&sal);
	printf("Digite o seu código\n");
	scanf("%d",&cod);

	switch(cod){
		case 100:
			nsal = sal * 1.03;
			break;
		case 101:
			nsal = sal * 1.05;
			break;
		case 102:
			nsal = sal * 1.075;
			break;
		case 201:
			nsal = sal * 1.1;
			break;
		default:
			nsal = sal * 1.15;
	}

	printf("Seu salário ANTIGO: %.2lf\n", sal);
	printf("Seu NOVO salário: %.2lf\n", nsal);
	printf("Diferença: %.2lf\n", (nsal - sal));


}