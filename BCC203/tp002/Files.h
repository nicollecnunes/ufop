#ifndef FILES_H
#define FILES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Util.h"

void criarArquivos(FILE** arqLEs, FILE** arqLi, FILE** arqEi, FILE** arqTxt, int situacao, int n);

void txt2Bin(FILE* txtOrigem, FILE* binFinal, int n);

void bin2Txt(FILE* binOrigem, FILE* txtFinal, int n);

#endif