/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 4
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int ano,A,B,C,D,E,F,G,H,I,K,L,M,mes,dia, dia_carn, mes_cc, dia_cc, dia_ss, mes_ss, mes_carn;
	printf("Digite o ano\n");
 	scanf("%d",&ano);
	A = ano%19;
	B = ano/100;
	C = ano%100;
	D = B/4;
	E = B%4;
	F = (B + 8)/25;
	G = (B-F + 1)/3;
	H = (19*A + B-D-G + 15)%30;
	I = C/4;
	K = C%4;
	L = (32 + 2*E + 2*I-H-K) % 7;
	M = (A + 11*H + 22*L)/451;
	mes = (H + L-7*M+114) / 31;
	dia = (H +L-7*M+ 114) % 31 + 1;
	if (dia==1){
		dia_cc = 31;
		mes_cc = mes + 1;
		mes_ss = mes -1;
		dia_ss= 30;
		dia_carn = dia +12;
	}
	else if (dia ==2){
		mes_ss = mes -1;
		dia_ss=29;
		dia_cc = dia -1;
		mes_cc = mes +2;
		dia_carn = dia +13;

	}
	else{
		dia_cc = dia -1;
		mes_cc = mes +2;
		dia_ss = dia -2;
		mes_ss = mes;
		if (dia>=17){
			dia_carn = dia -16;
			mes_carn = mes -1;
		}else{
			dia_carn = dia +13;
			mes_carn = mes -2;
		}
	}

 	printf("PÁSCOA = %d/%d\n", dia, mes);
 	printf("SEXTA SANTA = %d/%d\n", dia_ss, mes_ss);
 	printf("TERÇA DE CARNAVAL = %d/%d\n", dia_carn, mes_carn);
 	printf("CORPUS CHRISTI = %d/%d\n", dia_cc, mes_cc);
	return 0;
}

