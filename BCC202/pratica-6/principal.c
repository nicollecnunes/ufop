#include "pilha.h"
#include <stdio.h>
#include <string.h>

int main()
{
        Pilha pilha;
        char ch;
        Item item;

        Pilha_Inicia(&pilha);

        while (scanf(" %c", &ch)!=EOF){
            //printf("acabei de ler o %s\n", &ch);
            if((strcmp(&ch, "("))==0){
                printf("adicionando x\n");
                item.key= 'x';
                Pilha_Push(&pilha, item);
            }else if((strcmp(&ch, ")"))==0){
                if(Pilha_EhVazia(&pilha)){
                    Pilha_Push(&pilha, item);
                    break;
                }
                printf("removendo x\n");
                item.key= 'x';
                Pilha_Push(&pilha, item);

            }
        }

        if(Pilha_EhVazia(&pilha)){
            printf("correto\n");
        }else{
            printf("incorreto\n");

        }

        //determinar o resultado

        Pilha_Esvazia(&pilha);

        return 0;//nao remova
}
