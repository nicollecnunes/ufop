#include "ordenacao.h"
#include <stdio.h>

int main ()
{
	int n, k;
  	TipoAluno *alunos;
  	alunos = NULL;

	scanf("%d", &n);
	scanf("%d", &k);

    //printf("n: %d k: %d\n", n,k);


    alunos = alocaAlunos(alunos, n);
    preenche(alunos, n);
    ordena(alunos, n);
    print(alunos, k);
    desalocaAlunos(alunos);

	//imprimir o resultado
	//desalocar o vetor
  return 0;
}
