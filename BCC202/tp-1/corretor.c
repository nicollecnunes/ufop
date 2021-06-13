#include "corretor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct subm {
  char id[1];
  int t;
  char julg[20];
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

void calculaP(int *p, TADsubm *S, int n){
	int sumParcial = 0, i,j, uc;
	for (i=0; i<n; i++){
		j = i;
		if((testaCorreto(S[i].julg) == 0)){
			//printf("%s ja estava certa de cara!\n", S[i].id);
			*p = *p + S[i].t;
			//printf("P esta valendo %d\n", *p);
			uc = i;

		}else{
			while ((testaCorreto(S[j].julg) == 1) && (strcmp(S[i].id, S[j].id) ==0)){
				//printf("a letra %s esta incorreta. somando 20...\n", (S[j].id));
				sumParcial = sumParcial + 20;
				j = j + 1;
			}
			if ((testaCorreto(S[j].julg) == 1)){
				//printf("julgamento do SJ ok\n");
				//printf("%s e %s\n", S[i].id, S[j].id);
			}

			if((testaCorreto(S[j].julg) == 0) && (strcmp(S[uc].id, S[j].id) !=0)){
				//printf("%s (j-1 )esta correta. passando a soma... de %d do acerto e %d da soma ate aqui \n", (S[j].id), S[j].t, sumParcial);
				*p = *p + sumParcial + S[j].t;
				//printf("P esta valendo %d\n", *p);
				i = j;
			}else{
				//printf("a letra %s nunca se corrigiu!! zerando...\n",(S[j].id));
		}
		sumParcial = 0;

		}
		

	}

}

void lerSubm(TADsubm *S, int n, int *c){
  int i;

  //printf("c agora vale %d\n", *c);
  for (i=0; i <n; i++){
  	scanf("%c", S[i].id);
  	getchar();
  	scanf("%d", &S[i].t);
  	getchar();
  	scanf("%s", S[i].julg);
  	getchar();
  	//printf("LEVANDO PARA O TESTEEEEE: %s, \n",S[i].julg);;
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