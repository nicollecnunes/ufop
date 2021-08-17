#include "arvore.h"
#include <stdio.h>

int main ()
{
	int n, no;
	TArvore *arvore;
	TItem AuxItem;

	//ler n
	scanf("%d", &n);

	//ler o primeiro no e criar a raiz da arvore
	scanf("%d", &no);
	AuxItem.chave = no;
	//pRaiz = TNo_Cria(AuxItem);

	TArvore_Inicia (arvore);
	TArvore_Insere_Raiz (arvore, AuxItem);

	for(int i = 1; i<n; i++) {
		//ler o no
		scanf("%d", &no);
		AuxItem.chave = no;
		//inserir na arvore	
		TArvore_Insere (arvore,AuxItem);					
	}


	//gerar percurso em ordem prefixa
	printf("PREFIXA:");
	Prefixa(*arvore);
	//gerar percurso em ordem infixa
	printf("\nINFIXA:");
	Infixa(*arvore);
	//gerar percurso em ordem posfixa
	printf("\nPOSFIXA:");
	Posfixa(*arvore);
	
	
	

	return 0;
}
