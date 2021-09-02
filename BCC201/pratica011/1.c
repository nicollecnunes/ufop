/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 1*/

#include <stdio.h>

struct Aluno{
	char nome[50];
	int mat;
	int nota[10];
	
};

struct Aluno encontraAluno(struct Aluno alu[], int n, int fmat){
	int a;
	for (a=0; a<n; a++){
		if (fmat==alu[a].mat){
			return alu[a];
			break;
		}
	}



}


int main(){
	int n,m,i,j,st=0, fmat;
	double med=0.0;
	struct Aluno alu[100];
	do{
		printf("Digite o número de alunos (n<=100): ");
		scanf("%d", &n);
	}while(n>100);

	do{
		printf("Digite a quantidade de notas (m<=10): ");
		scanf("%d", &m);
	}while(m>10);

	for(i=0; i<n; i++){
		printf("\n=====CADASTRO=====\n");
		printf("Digite o nome do aluno %d: ", i+1);
		getchar();
		fgets(alu[i].nome, 40 ,stdin);
		printf("Digite a matrícula : ");
		scanf("%d", &alu[i].mat);
		for (j=0; j<m; j++){
			printf("Digite a %dª nota : ", j+1);
			scanf("%d", &alu[i].nota[j]);
			st = st + alu[i].nota[j];

		}
	}
	st = st / (n*m);

	printf("\nMÉDIA DE TODAS AS NOTAS: %d", st);

	printf("\n\n=====CONSULTA=====\n");
	printf("Digite sua matrícula: ");
	scanf("%d", &fmat);

	for (i=0; i<m; i++){
		med = med + encontraAluno(alu, n, fmat).nota[i];
	}
	med = med / m;

	printf("NOME: %s\n", encontraAluno(alu, n, fmat).nome);
	printf("MÉDIA DE NOTAS: %.2lf\n", med);



	return 0;
}