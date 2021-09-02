/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 4*/

#include <stdio.h>
#include <math.h>

float comiss(float vendas);

float comiss(float vendas){
	if (vendas >= 5000){
		return vendas * 0.25;
	}else if ((vendas>=2500) && (vendas<5000)){
		return vendas * 0.2;
	}else if (vendas<2500){
		return vendas * 0.15;
	}
}

int main(){
	float vendas;
	printf("Digite o valor total das vendas: \n");
	scanf("%f",&vendas);
	printf("O valor da~comissao eh: %.2f\n", comiss(vendas));
	return 0;
}