# ifndef ordenacao_h
# define ordenacao_h

typedef struct{
	char nome[50];
} TipoAluno;

//Manter como especificado
void ordena(TipoAluno *alunos, int n);
//Manter como especificado
TipoAluno *alocaAlunos(TipoAluno *alunos, int n);
//Manter como especificado
TipoAluno *desalocaAlunos(TipoAluno *alunos);

void ordena(TipoAluno *alunos, int n);

void preenche(TipoAluno *alunos, int n);

void print(TipoAluno *alunos, int n);
# endif
