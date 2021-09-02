/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 3*/
#include <string.h>
#include <stdio.h>

int main(){
	int a,b,c;
	printf("Digite os números\n");
 	scanf("%d%d%d",&a, &b, &c);
 	if ((a>=b) && (a>=c)){
 		printf("Maior: %d \n", a);
	 	if ((b>=c)){
	 		printf("Intermediário: %d \n", b);
	 		printf("Menor: %d \n", c);
	 		return 0;
	 	}else{
	 		printf("Intermediário: %d \n", c);
	 		printf("Menor: %d \n", b);
	 		return 0;
 		}
 	}

 	if ((b>=a) && (b>=c)){
 		printf("Maior: %d \n", b);
	 	if ((a>=c)){
	 		printf("Intermediário: %d \n", a);
	 		printf("Menor: %d \n", c);
	 		return 0;
	 	}else{
	 		printf("Intermediário: %d \n", c);
	 		printf("Menor: %d \n", a);
	 		return 0;
 		}
 	}


 	if ((c>=b) && (c>=a)){
 		printf("Maior: %d \n", c);
	 	if ((b>=a)){
	 		printf("Intermediário: %d \n", b);
	 		printf("Menor: %d \n", a);
	 		return 0;
	 	}else{
	 		printf("Intermediário: %d \n", a);
	 		printf("Menor: %d \n", b);
	 		return 0;
 		}
 	}

 	
	return 0;
}

