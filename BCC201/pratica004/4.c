/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 4*/

#include <stdio.h>
#include <ctype.h>

int main(){
	char ec;
	char s;
	printf("Digite seu estado civil\n");
	scanf("%c",&ec);
	getchar();  // <== remove o \n
	printf("Digite seu sexo\n");
	scanf("%c",&s);


	ec = tolower(ec);
	s = tolower(s);

	switch(ec){
	case 'c':
		printf("Casad");
		break;
	case 's':
		printf("Solteir");
		break;
	case 'v':
		printf("Viúv");
		break;
	case 'd':
		printf("Divorciad");
		break;
	default:
		printf("INVÁLIDO");
	}

	if (s == 'f'){
		printf("a\n");
	}else{
		printf("o\n");
	}
	return 0;
}	