#ifndef gArquivo_h
#define gArquivo_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "arvBinaria.h"

void geradorRegistros(TRegistro *reg, int quantidade, int situacao);

void geradorArquivo(int quantidade, int situacao, TRegistro *registros);

#endif