/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 2*/

#include <stdio.h>

struct racional{
	int num;
	int den;
};

int mdc (int x, int y){
	int r = 1;
	while(r){
		r= x%y;
		x=y;
		y=r;
	}
	return x;
}

int equals(int n1, int d1, int n2, int d2){
	if ((n1==n2) && (d1==d2)){
		return 1;
	}else{
		return 0;
	}
}


int main(){
	struct racional r1;
	struct racional r2;
	int m;

	printf("Digite o numerador e denominador de r1: ");
	scanf("%d %d", &r1.num, &r1.den);

	printf("Digite o numerador e denominador de r2: ");
	scanf("%d %d", &r2.num, &r2.den);

	m = mdc(r1.num, r1.den);
	r1.num = r1.num / m;
	r1.den = r1.den / m;

	m = mdc(r2.num, r2.den);
	r2.num = r2.num / m;
	r2.den = r2.den / m;
	
	if (equals(r1.num, r1.den, r2.num, r2.den) == 1){
		printf("\nr1 e r2 são iguais!\n");
	}else{
		printf("\nr1 e r2 são diferentes!\n");
	}

	return 0;
}