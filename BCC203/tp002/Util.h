#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

#define QUANTIDADE_FITAS 20
#define QUANTIDADE_MEMORIA_INTERNA 20

typedef struct arquivo{
    FILE *fita_entrada[QUANTIDADE_FITAS];
    FILE *fita_saida[QUANTIDADE_FITAS];

    //Quantos blocos possui cada fita/saida
    int quantidade_bloco_fita_entrada[QUANTIDADE_FITAS];
    int quantidade_bloco_fita_saida[QUANTIDADE_FITAS];

    //Leituras ja feitas em cada fitas entrada
    int quantidade_leitura_bloco_fita_entrada[QUANTIDADE_FITAS];

    //Escritats ja feitas em cada fita saida
    int quantidade_escrita_bloco_fita_saida[QUANTIDADE_FITAS];

    //Cantador  de quantos blocos ja foram lidos de cada fita
    int contador_blocos_lidos_entrada[QUANTIDADE_FITAS];
    int contador_blocos_lidos_saida[QUANTIDADE_FITAS];
} FitasPrimeiroMetodo;

typedef struct aluno{
    long int inscricao;
    double nota;
    char estado[3];
    char cidade[51];
    char curso[31];
    //int isMarked;
} Aluno;

typedef struct alunoMarcas{
    Aluno aluno;
    int isMarked;
} AlunoMarcas;

typedef struct memoriaInterna{
    Aluno *memoria_interna;
    int *fita;
    int disponivel;
} MemoriaInterna;

typedef struct intercalacaoMetodo1{
    int fita;
    int quantidade_bloco;
    int registros_lidos;

} IntercalacaoMetodo1;

typedef struct analise{
    int nLeitura;
    int nEscrita;
    int nComparacoes;
    clock_t tInicial;
    clock_t tFinal;
    double tTotal;
}Analise;

int tratarErros(int argc, char* argv[]);

int temArgumentoOpcional(int argc);

void imprimeArquivo(FILE* arq, int n);

void imprimeAluno(Aluno a);

int digitosDouble(double n, int cont);

int digitosLong(long int n, int cont);

void formatInscricao(long int n, int noArquivo, FILE* arq);

void formatNota(double n, int noArquivo, FILE* arq);

void inicializaFitas(FitasPrimeiroMetodo *fitas);

void inicializaVetorMemoriaInterna(MemoriaInterna *memoriaInterna);

void fitasBinariaModoLeitura(FitasPrimeiroMetodo *fitas, int entrada_saida);

void fitasBinariaModoEscrita(FitasPrimeiroMetodo *fitas, int entrada_saida);

//void transformaFitas(FitasPrimeiroMetodo *fitas, int quantidade);

//void preencheFitasBlocos(Aluno *v1, FitasPrimeiroMetodo *fitas, int quantidade, int controlador_fitas);

void fechaFitas(FitasPrimeiroMetodo *fitas, int entrada_saida);

void iniciaAnalise(Analise* a);

void novaLeitura(Analise* a);

void novaEscrita(Analise* a);

void novaComparacao(Analise* a);

void iniciaTempo(Analise* a);

void finalizaTempo(Analise* a);

void imprimirAnalise(Analise* a);
#endif