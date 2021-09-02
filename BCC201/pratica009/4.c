/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 4*/

#include <stdio.h>

int main(){
	int n=101,a=0;
	double me=0.0;
	while(n>100){
		printf("Digite o o número N de alunos, tal que N<100\n");
		scanf("%d",&n);
	}
	int p1[n], p2[n];
	while(a<n){
		printf("Digite a nota do %dº aluno na prova 1\n", a+1);
		scanf("%d",&p1[a]);
		printf("Digite a nota do %dº aluno na prova 2\n", a+1);
		scanf("%d",&p2[a]);
		a++;
	}
	a=0;

	while (a<n){
		me = (p1[a]*1.0 + p2[a])/2;
		printf("\n========================\n");
		printf("ALUNO %d\n", a+1);
		printf("MÉDIA %.2lf\n", me);
		printf("SITUAÇÃO: ");
		if (me>=60){
			printf("APROVADO\n");
		}else{
			printf("REPROVADO\n");
		}
		a++;
	}
	return 0;
}