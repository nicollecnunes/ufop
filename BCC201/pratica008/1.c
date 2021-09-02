/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 1*/

#include <stdlib.h>
#include <stdio.h>

int verifica(int **mat, int n){
	int sl=0, sl1=0, sc=0,sc1=0, sdp =0, sds=0, i,j,i1,j1;

	for (i1=0;i1<n;i1++){
			for (j1=0;j1<n;j1++){
				for (i=0;i<n;i++){
					for (j=0;j<n;j++){
						if((mat[i1][j1] == mat [i][j]) && (i!=i1) && (j!=j1)){
							return 1;
							break;				
						}
					}
				}
			}
	} //nao tem repetido se chegou aqui

	for (j=0;j<n;j++){
		sl1 = sl1 + mat[1][j];
	}

	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			sl = sl + mat[i][j];
		}
		if (sl1 != sl){
			return 1;
			break;
		}
		sl=0;
	} // soma das linhas e igual se chegou aqui


	for (i=0;i<n;i++){
		sc1 = sc1 + mat[i][1];
	}

	for (j=0;j<n;j++){
		for (i=0;i<n;i++){
			sc = sc + mat[i][j];
		}
		if (sc1 != sc){
			return 1;
			break;
		}
		sc =0;
	} // soma das colunas e igual se chegou aqui

	if(sc1 != sl1){
		return 1;
	}//soma c=l


	for (i=0;i<n;i++){
		sdp = sdp + mat[i][i];
	}// soma da d. principal

	i=0;
	while (i<n){
		for (j=n-1;j>=0;j--){
			sds = sds + mat[i][j];
			i++;
		}
	}

	if (sdp == sds){
		return 0;
	}else{
		return 1;
	}

	


}

void lib(int **mat, int n){
	int i;
	for(i=0;i<n;i++){
		free(mat[i]);
	}
	free(mat);

}

int main(){
	int **mat;
	int n,i,j;
	printf("Digite o valor de n:\n");
	scanf("%d", &n);

	mat = malloc( n * sizeof(int*)); //(int**) 

	for(i=0;i<n;i++){
		mat[i] = malloc(sizeof(int)* n); //(int*) 
	}

	printf("Digite os valores da matriz %dx%d",n,n);
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			scanf("%d", &mat[i][j]);
		}					
	}
	if (verifica(mat, n) == 0){
		printf("A matriz é um quadrado mágico!\n");

	}else{
		printf("A matriz NÃO é um quadrado mágico!\n");

	}

	lib(mat, n);
	

	
	return 0;
}