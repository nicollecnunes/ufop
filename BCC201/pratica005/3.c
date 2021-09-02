/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 3*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int tempo(int *hi, int *mi, int *hf, int *mf);
int tempo(int *hi, int *mi, int *hf, int *mf){

	int dh=0, dm=0, dur=0;
	if (*hi < *hf){ //mesmo diaA
		dh = *hf - *hi;
		if (*mi <= *mf){
			dm = *mf - *mi;			
		}else{
			dm = *mi - *mf;
			dh--;
		}
	}else if (*hi == *hf){ //varia
		if (*mi == *mf){ //outro
			dh = 24;
			dm = 0;
		}else if (*mi > *mf){ //outro
			dh =  23;
			dm = *mf+*mi;
		}else if (*mi < *mf){ //mesmo
			dh = 0;
			dm = *mf - *mi;
		}
	}else if(*hi > *hf){ //outro dia
		if (*mi < *mf){
			dh = 24 - (*hi - *hf);
			dm = *mf - *mi;
		}else if(*mi == *mf){
			dh = 24 - (*hi - *hf);
			dm =0;
		}else if(*mi>*mf){
			dh = 23 - (*hi - *hf);
			dm = 60 - (*mi - *mf);
		}

	}

	printf("Tempo de duração = %d horas e %d minutos \n", dh, dm );

	dur = dh * 60 + dm;
	return dur;
	}


int main(){
	int hi,mi,hf,mf;
	printf("Digite a HORA INICIAL e o MINUTO INICIAL, respectivamente: \n");
	scanf("%d%d",&hi,&mi);
	printf("Digite a HORA FINAL e o MINUTO FINAL, respectivamente: \n");
	scanf("%d%d",&hf,&mf);

	tempo(&hi, &mi, &hf, &mf);
	printf("Tempo de duração = %d minutos \n", tempo(&hi, &mi, &hf, &mf) );


	return 0;
}