/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 2*/

#include <stdio.h>


struct Aluno{
	char nome[50];
	double nota;
	double freq;
	
};

void escreve(int n, struct Aluno alu[]){
	FILE *file;
	int i;

	file = fopen("alunos.txt", "a");
	for (i=0; i<n; i++){
		fprintf(file, "%s", alu[i].nome);
		fprintf(file, " ");
		fprintf(file, "%.2lf", alu[i].nota);
		fprintf(file, " ");
		fprintf(file, "%.1lf", alu[i].freq);
		fprintf(file, "\n");
	}


	fclose(file);
}


int main(){
	int n, i;
	struct Aluno alu[100];
	
	printf("Digite o número de alunos: ");
	scanf("%d", &n);


	for(i=0; i<n; i++){
		printf("\n=====CADASTRO=====\n");
		printf("Digite o nome do aluno %d: ", i+1);
		scanf("%s", alu[i].nome);
		printf("Digite a nota: ");
		scanf("%lf", &alu[i].nota);
		printf("Digite a frequência (0<=f<=100): ");
		scanf("%lf", &alu[i].freq);
		
	}

	escreve(n, alu);

}