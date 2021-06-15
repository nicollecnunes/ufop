#include "corretor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct subm {
  char id[1];
  int t;
  char julg[20];
};

struct c{
	char id[1];
	int p;
};


void lerQuantidade(int *n){
	scanf("%d", n);
    getchar();
    //printf("quantidade lida: %d\n",*n);
}

TADsubm *alocaSubm(TADsubm *S, int n){
	int i;
	for (i=0; i < n; i++){
   		S = malloc (n * sizeof (TADsubm)) ;
	}
	return S;
}


TADsubm *desalocaSubm(TADsubm *S){
	free (S);
	return S;
}


TADcorr *alocaCorr(TADcorr *C, int n){
	int i;
	for (i=0; i < n; i++){
   		C = malloc (n * sizeof (TADcorr)) ;
	}
	return C;
}


TADcorr *desalocaCorr(TADcorr *C){
	free (C);
	return C;
}


int testaCorreto(char julg[]){
	//printf("ENTRANDO COM: %s\n", julg);
	if (strcmp(julg, "correto") ==0){
		//printf("entrei no if!!!\n");
		return 0;
	}else if (strcmp(julg, "incompleto") ==0){
		return 1;
	}else{
		return -1;
	}
}

void calculaP(int *p, TADsubm *S, int n, TADcorr *C){
	int sumParcial = 0, i,j;
	for (i=0; i <n; i++){
		//printf("i vale %d\n\n", i);
		if ((testaCorreto(S[i].julg) == 0)){
			//printf("S[%d] = %s correto \n\n", i, S[i].id);
			for(j=0; j<=i; j++){
				//printf("buscando a anterior 73\n");
				//printf("S[j(%d)] = %s e S[i(%d)] = %s \n",j, S[j].id,i,S[i].id);
				if((strcmp(S[i].id, S[j].id) ==0)){
					//printf("encontrei em j valendo %d, que e igual a i valendo %d\n", j,i);
					//printf("soma era %d", sumParcial);
					sumParcial = sumParcial + S[i].t + C[j].p;
					//printf("soma ficou %d.pela soma de %d + %d\n", sumParcial,S[i].t, C[j].p);
					break;
				}

			} //correto
		}else{
			//printf("S[%d] = %s incorreto\n\n", i, S[i].id);
			for (j=0; j<=i; j++){
				//printf("buscando a anterior 86\n");
				//printf("S[j(%d)] = %s e S[i(%d)] = %s \n",j, S[j].id,i,S[i].id);

				if((strcmp(S[i].id, S[j].id) ==0)){
					C[j].p = C[j].p + 20;
					//printf("encontrei em j valendo %d, que e igual a i valendo %d. a P em j é %d\n", j,i,C[j].p);
					break;
				}
			}


		}

	}
	*p = sumParcial;

}

void lerSubm(TADsubm *S, int n, int *c, TADcorr *C){
  int i;

  //printf("c agora vale %d\n", *c);
  for (i=0; i <n; i++){
  	scanf("%s", S[i].id);
  	getchar();
  	strcpy(C[i].id, S[i].id);
  	scanf("%d", &S[i].t);
  	getchar();

  	scanf("%s", S[i].julg);
  	getchar();
  	C[i].p = 0;
  	//printf("LEVANDO PARA O TESTEEEEE: %s, \n",S[i].julg);
  	if((testaCorreto(S[i].julg) == 0)){
  		*c = *c + 1;

  	}
  
  	//printf("o trem agora vale %d\n",testaCorreto(S[i].julg));
  	//printf("c agora vale %d por causa do indice [%d]\n", *c, i);
  	;
  }
}

void printSaida(TADsubm *S, int n, int c, int p){
	printf("%d %d\n", c,p);
}