/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 1*/

#include <stdio.h>

int main(){
	int a;
	printf("Digite o ano\n");
 	scanf("%d",&a);
 	if (a%4==0){
 		if (a%100!=00){
 			printf("Bissexto\n");
 			return 0;
 		}else{
 			if (a%400==0){
 				printf("Bissexto\n");
 				return 0;
			}
 		}
 	}else{
 		printf("Não é bissexto\n");	
 	}
 	
	return 0;
}

