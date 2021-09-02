/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 1*/

#include <stdio.h>

void preenche(int m[10][10], int *l, int *c);
void preenche(int m[10][10], int *l, int *c){
	int i, j;
	for (i=0; i<*l; i++){
			for (j=0;j<*c;j++){
			printf("\nDigite o valor (Linha %d, Coluna %d):",i+1,j+1);
			scanf("%d",&m[i][j]);
			}
		}
}

void imprime(int r[10][10], int l, int c);
void imprime(int r[10][10], int l, int c){
	int i,j;
	for(i=0; i<l; i++) {
			for(j=0; j<c; j++) {
				printf("%d ", r[i][j]);
			}
			printf("\n\n");
		}
		printf("\n");

}



int main(){
	int l1,c1,l2,c2,i,j,aux=0,x;
	int m1[10][10],m2[10][10],r[10][10];;

	printf("Digite o número de linhas e colunas da Matriz I (nessa ordem): ");
	scanf("%d%d",&l1,&c1);
	printf("Digite o número de linhas e colunas da Matriz II (nessa ordem): ");
	scanf("%d%d",&l2,&c2);

	

	if (l1!=c2){
		printf("Essas matrizes não podem ser multiplicadas!");
		return 0;
	}else{
		printf("\n\n======PREENCHENDO A MATRIZ I======\n");
		preenche(m1, &l1, &c1);
		printf("\n\n======PREENCHENDO A MATRIZ II======\n");
		preenche(m2, &l2, &c2);


		printf("\n\n======RESULTADO:======\n");
		for(i=0; i<l1; i++) {
		for(j=0; j<c2; j++) {
			r[i][j] = 0;
			for(x=0; x<l2; x++) {
				aux = aux + m1[i][x] * m2[x][j];
			}
			r[i][j] = aux;
			aux = 0;
		}
		}
		imprime(r, l1, c2);
	}
	return 0;
}