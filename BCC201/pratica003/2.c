/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 2*/
#include <string.h>
#include <stdio.h>

int main(){
	char l[0];
	printf("Digite uma letra\n");
 	scanf("%s",l);
 	if ((strcmp(l, "a")==0)|| (strcmp(l, "e")==0)||(strcmp(l, "i")==0)||(strcmp(l, "o")==0)||(strcmp(l, "u")==0)){
 		printf("É uma vogal minúscula\n");
 	}else{
 		printf("Não é uma vogal minúscula\n");
 	}
 	
	return 0;
}

