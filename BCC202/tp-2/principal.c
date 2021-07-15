#include "ordenacao.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX_STR 1200

int main(){
    TLista lista;
    char str[MAX_STR];
    char* token;
    TPais x;

    listaInicia(&lista);

    fgets (str, MAX_STR, stdin);
    str[strcspn(str, "\n")] = 0;

    printf("EU LI ISSO AQUI: %s\n", str);

    //tokenizacao da string original, divide em strings delimitadas por espaco em branco
    token = strtok(str, " ");

    while (token != NULL) {
        printf("passando o %s para nome..\n", token);
     	strcpy(x.nome, token);
        token = strtok(NULL, " ");


        printf("passando o %s para ouro..\n", token);
        x.ouro = atoi(token);
        token = strtok(NULL, " ");

        printf("passando o %s para prata..\n", token);
        x.prata = atoi(token);
        token = strtok(NULL, " ");

        printf("passando o %s para bronze..\n", token);
        x.bronze = atoi(token);
        token = strtok(NULL, " ");

        ordenaLista(&lista, &x);
        TLista_Imprime(&lista);
    }

    printf("final: ");
    TLista_Imprime(&lista);
    printf("\n");

    return 0;
}