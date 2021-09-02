/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 1*/

#include <stdio.h>

int main(){
	int p=0,n=0;
	double x=0;
    do{
    	printf("Digite um número real (parar = 0): ");
    	scanf("%lf",&x);

    	if (x<0){
    		n++;
    	}
    	if(x>0){
    		p++;
    	}
    }while (x!=0);

    printf("Positivos: %d\n", p);
    printf("Negativos: %d\n", n);
    return 0;
}