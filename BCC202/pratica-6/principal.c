#include "pilha.h"
#include <stdio.h>
#include <string.h>

int main()
{
        Pilha pilha;
        char ch;
        Item item;

        Pilha_Inicia(&pilha);

        while (scanf("%c", &ch)!=EOF){
            item.key =ch;
            if(item.key == '('){
                item.key ='x';
                //printf("adicionando x\n");
                Pilha_Push(&pilha, item);
            }else if(item.key == ')'){
                item.key ='x';
                if(Pilha_EhVazia(&pilha)){
                    Pilha_Push(&pilha, item);
                    break;
                }
                //printf("removendo x\n");
                Pilha_Pop(&pilha, &item);

            }
        }

        if(Pilha_EhVazia(&pilha)){
            printf("correto\n");
        }else{
            //TLista_Imprime(&pilha);
            printf("incorreto\n");

        }

        //determinar o resultado

        Pilha_Esvazia(&pilha);

        return 0;//nao remova
}
