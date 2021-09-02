/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 2*/

#include <stdio.h>

int main(){
	int i;
	printf("Digite sua idade\n");
	scanf("%d",&i);
	printf("Você deve pagar: ");
	if (i <= 10){
		printf("R$ 90,00\n");
	}else if ((i > 10) && (i <= 29)){
		printf("R$ 170,00\n");
	}else if ((i > 29) && (i <= 45)){
		printf("R$ 290,00\n");
	}else if ((i > 45) && (i <= 59)){
		printf("R$ 400,00\n");
	}else if ((i > 59) && (i <= 65)){
		printf("R$ 515,00\n");
	}else{
		printf("R$ 695,00\n");
	}

}