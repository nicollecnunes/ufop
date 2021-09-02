/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 1*/

#include <stdio.h>
char arq[50];

struct Dieta{
	char nome[50];
	double peso;
	double cal;
	double relacao;
};

void leitor(char arq[], struct Dieta diet[], int *n){
	FILE *arquivo;
	int i;

	arquivo = fopen(arq, "r");

	fscanf(arquivo, "%d", n);

	for (i=0; i<*n; i++){
		fscanf(arquivo, "%s", diet[i].nome);
		fscanf(arquivo, "%lf", &diet[i].peso);
		fscanf(arquivo, "%lf", &diet[i].cal);	
		diet[i].relacao = (diet[i].cal/diet[i].peso);
	}

	fclose(arquivo);
	//achaeimprime(diet, n);

}

void achaeimprime(struct Dieta diet[], int n){
	int i;
	double maior = diet[i].relacao;
	for (i=0; i<n; i++){
		if (diet[i].relacao>maior){
			maior = diet[i].relacao;
			break;
		}
	}

	printf("\n\nALIMENTO		cal/grama\n");
	printf("=================================\n");
	for (i=0; i<n; i++){
		printf("%s", diet[i].nome);
		printf("		");
		printf("%.2lf", diet[i].relacao);
		if (diet[i].relacao==maior){
			printf("*");
		}
		printf("\n");

	}

}


int main(){
	int n;
	struct Dieta diet[100];

	printf("Digite o nome do arquivo: ");
	scanf("%s", arq);

	leitor(arq, diet, &n);
	achaeimprime(diet, n);


	return 0;
}