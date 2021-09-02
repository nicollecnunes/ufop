/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 5*/

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
		fscanf(arquivo, "%lf", &alu[i].freq);
		i++;
	}
	*tot = i-1;

	fclose(arquivo);
}


int main(){
	int tot=0, i;
	double nm=0, fm=0, pa=0;
	struct Aluno alu[100];
	printf("Digite o nome do arquivo: ");
	scanf("%s", arq);

	leitor(arq, alu, &nm, &fm, &pa, &tot);

	FILE *arquivobi = fopen("alunosbinario.bin", "w+b");
	fwrite(&alu, sizeof(struct Aluno),tot, arquivobi);
	
	i=0;
	while (i<tot){
		fread(&alu[i].nome, sizeof(char), 1, arquivobi);
		fread(&alu[i].nota, sizeof(double), 1, arquivobi);
		nm = nm + alu[i].nota;
		if (alu[i].nota>=6){
			pa = pa + 1;
		}
		fread(&alu[i].freq, sizeof(double), 1, arquivobi);
		fm = fm + alu[i].freq;	
		i++;
	}
	fclose(arquivobi);
	nm = nm / tot;
	pa = pa * 100 / tot;
	fm = fm / tot;

	


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