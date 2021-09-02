/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 3*/

#include <stdio.h>
char arq[50];

struct Aluno{
	char nome[50];
	double nota;
	double freq;
	
};

void leitor(char arq[], struct Aluno alu[], double *nm, double *fm, double *pa, int *tot){
	FILE *arquivo;
	int i=0;

	arquivo = fopen(arq, "r");


	while (!feof(arquivo)){
		fscanf(arquivo, "%s", alu[i].nome);
		fscanf(arquivo, "%lf", &alu[i].nota);
		*nm = *nm + alu[i].nota;
		if (alu[i].nota>=6){
			*pa = *pa + 1;
		}
		fscanf(arquivo, "%lf", &alu[i].freq);
		*fm = *fm + alu[i].freq;	
		i++;
	}
	i--;
	*tot = i;

	fclose(arquivo);

	*nm = *nm / i;
	*pa = *pa * 100 / i;
	*fm = *fm / i;

}


int main(){
	int tot=0, i;
	double nm=0, fm=0, pa=0;
	struct Aluno alu[100];
	printf("Digite o nome do arquivo: ");
	scanf("%s", arq);

	leitor(arq, alu, &nm, &fm, &pa, &tot);

	printf("\nNOTA MÉDIA: %.1lf", nm);
	printf("\nFREQUENCIA MÉDIA: %.0lf%%", fm);
	printf("\nPERCENTUAL DE APROVAÇÃO: %.0lf%%", pa);

	printf("\n\nNOME DOS ALUNOS COM NOTA ACIMA DA MÉDIA:\n");

	for (i=0; i<tot; i++){
		if (alu[i].nota>nm){
			printf("%s\n", alu[i].nome);
		}
	}


}