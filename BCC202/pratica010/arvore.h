# ifndef arvore_h
# define arvore_h


typedef long TChave;

typedef struct {
    TChave chave;
} TItem ;

typedef struct No {
    TItem item;
    struct No *pEsq;
    struct No *pDir;
} TNo ;

typedef TNo *TArvore;

void TArvore_Inicia (TNo **pRaiz);
void TArvore_Insere_Raiz (TNo **ppRaiz , TItem x);
int TArvore_Insere (TNo **ppRaiz , TItem x);
TNo *TNo_Cria (TItem x);
void Prefixa(TNo *p);
void Infixa(TNo *p);
void Posfixa(TNo *p);

# endif
