#include "Util.h"

int tratarErros(int argc, char* argv[]){
    char ordena[10];
    int metodo;
    int quantidade;
    int situacao;

    if (argc < 4)
    {
        printf("Por favor, informe todos os comandos de execucao, voce informou apenas %d\n", argc);
        return -1;
    }

    strcpy(ordena, argv[1]);  // tem que ser a palavra "ordena"
    if (strcmp(ordena, "ordena")){
        printf("O comando digitado foi: %s (argv[1])\n", ordena);
        printf("Comando invalido. Comandos disponiveis:\n- ordena");
        return -1;
    }

    metodo = atoi(argv[2]);
    if (metodo != 1 && metodo != 2 && metodo != 3){
        printf("O metodo digitado foi: %d (argv[2])\n", metodo);
        printf("Metodo invalido. Metodos disponiveis:\n(1) Intercalação (2f fitas) com qualquer método de ordenação interna\n(2) Intercalação (2f fitas) com a técnica de seleção por substituição\n(3) Quicksort externo");
        return -1;
    }

    quantidade = atoi(argv[3]);
    if (quantidade <= 0){
        printf("O arquivo nao possui dados (quantidade = 0)\n");
        return -1;
    }

    situacao = atoi(argv[4]);
    if (situacao != 1 && situacao != 2 && situacao != 3){
        printf("A situacao digitada foi: %d (argv[4])\n", situacao);
        printf("Situacao invalida. Situacoes disponiveis:\n1 (arquivo ordenado ascendentemente)\n2 (arquivo ordenado descendentemente)\n3 (arquivo desordenado aleatoriamente)");
        return -1;
    }

    return 0;
}

int temArgumentoOpcional(int argc){
    if (argc == 6)
    {
        return 1;
    } 
    else return 0;
}

void imprimeArquivo(FILE* arq, int n){
    Aluno a;
    int i = 1;
    
    rewind(arq);
    // varredura no arquivo
    while(i <= n && fread(&a, sizeof(Aluno), 1, arq) == 1){
        imprimeAluno(a);
        i++;
    }
    rewind(arq);
}

void imprimeAluno(Aluno a){
    formatInscricao(a.inscricao, 0, NULL);
    formatNota(a.nota, 0, NULL);
    printf("%.2s ",a.estado);
    printf("%.30s ",a.cidade);
    printf("%.50s\n",a.curso);
}

int digitosDouble(double n, int cont){
    if (n < 1.0)
        return cont;
    else
        return digitosDouble(n/10.0, ++cont);
}

int digitosLong(long int n, int cont){
    if (n <= 0)
        return cont;
    else
        return digitosLong(n/10, ++cont);  
}

void formatInscricao(long int n, int noArquivo, FILE* arq){
    // se noArquivo == 0, usa o print normal, se nao, significa que sera escrito no arquivo
    int i, zeros = 8 - digitosLong(n,0);

    if (noArquivo){
        for ( i = 0; i < zeros; i++)
            fprintf(arq,"0");
        fprintf(arq,"%ld ",n);
    }
    else{
        for ( i = 0; i < zeros; i++)
            printf("0");
        printf("%ld ",n);    
    }

}

void formatNota(double n, int noArquivo, FILE* arq){
    int i, zeros = 3 - digitosDouble(n,0);

    if (noArquivo){
        if(n>=0.0 && n<=1.0)
            fprintf(arq,"00");
        else
        {
            for( i=0; i<zeros; i++)
                fprintf(arq,"0");
        }
        fprintf(arq,"%.1lf ",n);
    }
    else{
        if(n >= 0.0 && n <= 1.0)
            printf("00");
        else{
            for( i=0; i<zeros; i++)
                printf("0");
        }
        printf("%.1lf ",n);
    }
}

void inicializaFitas(FitasPrimeiroMetodo *fitas){
    for(int i = 0; i < QUANTIDADE_FITAS; i++) {
        fitas->quantidade_bloco_fita_entrada[i] = 0;
        fitas->quantidade_bloco_fita_saida[i] = 0;
        fitas->quantidade_leitura_bloco_fita_entrada[i] = 0;
        fitas->quantidade_escrita_bloco_fita_saida[i] = 0;
    }
}

void inicializaVetorMemoriaInterna(MemoriaInterna *memoriaInterna){
    memoriaInterna->memoria_interna = malloc(QUANTIDADE_MEMORIA_INTERNA * sizeof(Aluno));
    memoriaInterna->fita = malloc(QUANTIDADE_MEMORIA_INTERNA * sizeof(int));

    for (int i = 0; i < QUANTIDADE_MEMORIA_INTERNA; ++i) {
        memoriaInterna->memoria_interna[i].nota = -1.0;
        memoriaInterna->fita[i] = 0;
    }
    memoriaInterna->disponivel = QUANTIDADE_MEMORIA_INTERNA;
}

void desalocaMemoriaInterna(MemoriaInterna *memoriaInterna){
    free(memoriaInterna->memoria_interna);
    free(memoriaInterna->fita);
}

//Abri em modo leitura as fitas, 1 para fitas de entrada e 2 para fitas de saida
void fitasBinariaModoLeitura(FitasPrimeiroMetodo *fitas, int entrada_saida){
    char nome_arquivo[50];

    if(entrada_saida == 1) {
        for (int i = 0; i < QUANTIDADE_FITAS; i++) {// Abrindos as fitas de entrada
            strcpy(nome_arquivo, "");
            sprintf(nome_arquivo, "fitaEntrada%d.bin", i + 1);
            fitas->fita_entrada[i] = fopen(nome_arquivo, "rb");
        }
    }

    if(entrada_saida == 2){
        for (int i = 0; i < QUANTIDADE_FITAS; i++) {// Abrindos as fitas de saida
            strcpy(nome_arquivo, "");
            sprintf(nome_arquivo, "fitaSaida%d.bin", i + 1);
            fitas->fita_saida[i] = fopen(nome_arquivo, "rb");
        }
    }
}

//Abri em modo escrita as fitas, 1 para fitas de entrada e 2 para fitas de saida
void fitasBinariaModoEscrita(FitasPrimeiroMetodo *fitas, int entrada_saida){
    char nome_arquivo[50];
    if(entrada_saida == 1) {
        for (int i = 0; i < QUANTIDADE_FITAS; i++) {// Abrindos as fitas de entrada
            strcpy(nome_arquivo, "");
            sprintf(nome_arquivo, "fitaEntrada%d.bin", i + 1);
            fitas->fita_entrada[i] = fopen(nome_arquivo, "ab");
        }
    }

    if(entrada_saida == 2){
        for (int i = 0; i < QUANTIDADE_FITAS; i++) {// Abrindos as fitas de saida
            strcpy(nome_arquivo, "");
            sprintf(nome_arquivo, "fitaSaida%d.bin", i + 1);
            fitas->fita_saida[i] = fopen(nome_arquivo, "wb");
        }
    }
}

void fechaFitas(FitasPrimeiroMetodo *fitas, int entrada_saida){
    if(entrada_saida == 1) {
        for (int i = 0; i < QUANTIDADE_FITAS; ++i)
            fclose(fitas->fita_entrada[i]);
    }

    if(entrada_saida == 2) {
        for (int i = 0; i < QUANTIDADE_FITAS; ++i)
            fclose(fitas->fita_saida[i]);
    }
}

void iniciaAnalise(Analise* a)
{
    a->nLeitura = 0;
    a->nEscrita = 0;
    a->nComparacoes = 0;
    a->tTotal = 0.0;
}

void novaLeitura(Analise* a)
{
    a->nLeitura++;
}

void novaEscrita(Analise* a)
{
    a->nEscrita++;
}

void novaComparacao(Analise* a)
{
    a->nComparacoes++;
}

void iniciaTempo(Analise* a)
{
    a->tInicial = clock();
}

void finalizaTempo(Analise* a)
{
    a->tFinal = clock();
    a->tTotal = (a->tFinal - a->tInicial)*1000.0/CLOCKS_PER_SEC;
}

void imprimirAnalise(Analise* a)
{
    printf("ANALISE: \n");
    printf("Numero de transferencias de leitura: %d\n",a->nLeitura);
    printf("Numero de transferencias de escrita: %d\n",a->nEscrita);
    printf("Numero de comparacoes: %d\n",a->nComparacoes);
    printf("Tempo de execucao: %lfms\n",a->tTotal);
}