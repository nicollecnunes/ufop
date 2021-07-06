#include "lista.h"
#include<stdio.h>
#include<string.h>
#define MAX_STR 1200

int main(){
    TLista original, nova;
    char str[MAX_STR], str2[MAX_STR], str3[20];
    char* token;
    TItem x;
    int i = 0;

    //iniciar listas

    fgets (str, MAX_STR, stdin);
    str[strcspn(str, "\n")] = 0;

    //tokenizacao da string original, divide em strings delimitadas por espaco em branco
    token = strtok(str, " ");

    while (token != NULL) {
      strcpy(x.nome, token);
      original.item[i].nome = x.nome;
      token = strtok(NULL, " ");
      i++;
    }
    original.pUltimo.item = i;

    fgets (str2, MAX_STR, stdin);
    str2[strcspn(str2, "\n")] = 0;

    //tokenizacao da string original, divide em strings delimitadas por espaco em branco
    token = strtok(str2, " ");

    i=0;
    while (token != NULL) {
      strcpy(x.nome, token);
      nova.item[i].nome = x.nome;
      token = strtok(NULL, " ");
      i++;
    }
    nova.pUltimo.item = i;

    scanf("%s", str3);
    if(*str3 == 'nao'){
    	TLista_append(&original, &nova);
    }else{
    	TLista_include(&original, &nova, str3);
    }

    TLista_Imprime(&original);



    //ao final as duas listas estarao unificadas, entao basta esvaziar a original

    return 0;//nao remova
}
