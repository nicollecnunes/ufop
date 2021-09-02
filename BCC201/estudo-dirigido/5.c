/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 4*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float mult(float a, float b);
float mult(float a, float b){
	return a*b;	
}

float divi(float a, float b);
float divi(float a, float b){
	if (b==0){
		printf("não é possível diviidir por 0! :(\n");
		abort();
	}else{
		return a/b;	
	}
}

float sub(float a, float b);
float sub(float a, float b){
	return a-b;	
}

float som(float a, float b);
float som(float a, float b){
	return a+b;	
}

float pot(float a, float b);
float pot(float a, float b){
	return pow(a,b);	
}

int main(){
	float x, y;
	char op;
	printf("Digite o primeiro valor: \n");
	scanf("%f",&x);
	getchar();

	printf("Digite o segundo valor: \n");
	scanf("%f",&y);
	getchar();

	printf("Informe a operação: \n");
	scanf("%c",&op);
	getchar();

	printf("%.2f %c %.2f = ", x,op,y);

	if (op=='+'){
		printf("%.2f",som(x,y));
	}else if (op=='-'){
		printf("%.2f", sub(x,y));
	}else if (op=='/'){
		printf("%.2f",divi(x,y));
	}else if (op=='-'){
		printf("%.2f",mult(x,y));
	}else if (op=='^'){
		printf("%.2f",pot(x,y));
	}


	return 0;
}