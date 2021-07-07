#include "lista.h"
#include<stdio.h>
#include<string.h>
#define MAX_STR 1200

int main(){
    TLista original, nova;
    char str[MAX_STR], str2[MAX_STR], str3[20];
    char* token;
    TItem x;

    TLista_Inicia(&original);
    TLista_Inicia(&nova);

    //iniciar listas

    fgets (str, MAX_STR, stdin);
    str[strcspn(str, "\n")] = 0;

    //printf("EU LI ISSO AQUI: %s\n", str);

    //tokenizacao da string original, divide em strings delimitadas por espaco em branco
    token = strtok(str, " ");

    while (token != NULL) {
     	strcpy(x.nome, token);
    	//printf("nome %d: %s\n", i, x.nome);
    	TLista_InsereFinal(&original, x);
      	token = strtok(NULL, " ");
    }
    //printf("saiu aqui\n");

	//TLista_Imprime(&original);

    fgets (str2, MAX_STR, stdin);
    str2[strcspn(str2, "\n")] = 0;

    //tokenizacao da string original, divide em strings delimitadas por espaco em branco
    token = strtok(str2, " ");

    while (token != NULL) {
      strcpy(x.nome, token);
      TLista_InsereFinal(&nova, x);
      token = strtok(NULL, " ");
    }


    scanf("%s", str3);

    if((strcmp(str3,"nao")==0)){
    	TLista_append(&original, &nova);
    	TLista_Imprime(&original);
    }else{
    	TLista_include(&original, &nova, str3);
    }



    //ao final as duas listas estarao unificadas, entao basta esvaziar a original

    return 0;//nao remova
}
