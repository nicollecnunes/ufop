#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct aluno{
    long int inscricao;
    double nota;
    char estado[3];
    char cidade[51];
    char curso[31];
} Aluno;

int tratarErros(int argc, char* argv[]);

int temArgumentoOpcional(int argc, char* argv[]);

void imprimeArquivo(FILE* arq, int n);

void imprimeAluno(Aluno a);

int digitosDouble(double n, int cont);

int digitosLong(long int n, int cont);

void formatInscricao(long int n, int noArquivo, FILE* arq);

void formatNota(double n, int noArquivo, FILE* arq);

#endif