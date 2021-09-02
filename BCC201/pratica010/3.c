/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 3*/
#include <stdio.h>

void transp(int a[10][10], int l, int c){
	int at[l][c], i,j;

	for (i=0; i<l; i++){
		for (j=0; j<c; j++){
			at[j][i] = a[i][j];
		}
	}

	for (i=0; i<l; i++){
		for (j=0; j<c; j++){
			printf("%d ", at[i][j]);
		}
		printf("\n");
	}


}

int main(){
	int l,i,j, a[10][10];
	printf("Digite n: ");
	scanf("%d",&l);

	while (l >10){
		printf("Por favor, digite um n <= 10");
		printf("Digite n: ");
		scanf("%d",&l);
	}
	int c=l;



	printf("\n\nPREENCHENDO A MATRIZ\n");
	for (i=0; i<l; i++){
		for (j=0;j<c;j++){
			printf("\nDigite o valor (Linha %d, Coluna %d):",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	transp(a,l,c);
		
	return 0;
}