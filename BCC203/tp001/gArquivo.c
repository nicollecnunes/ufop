#include "gArquivo.h"

void geradorRegistros(TRegistro *reg, int quantidade, int situacao)
{   
    int i, j;
    srand(time(NULL));
    if (situacao == 1)
    {
        for ( i = 0; i < quantidade; i++)
        { // for registros
            reg[i].chave = i + 1;

            reg[i].dado1 = rand() % 100 + 1;

            for ( j = 0; j < 500; j++)
                reg[i].dado2[j] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 26];

            for ( j = 0; j < 3000; j++)
                reg[i].dado3[j] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 26];
        }
    }

    else if (situacao == 2)
    {
        for ( i = 0; i < quantidade; i++)
        { // for registros
            reg[i].chave = quantidade - i;

            reg[i].dado1 = rand() % 100 + 1;

            for ( j = 0; j < 500; j++)
            {
                reg[i].dado2[j] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 26];
            }

            for ( j = 0; j < 3000; j++)
            {
                reg[i].dado3[j] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 26];
            }
        }
    }

    else if (situacao ==3)
    {
        for ( i = 0; i < quantidade; i++)
        { // for registros
            reg[i].chave = rand() % quantidade + 1;

            reg[i].dado1 = rand() % 100 + 1;

            for ( j = 0; j < 500; j++)
            {
                reg[i].dado2[j] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 26];
            }

            for ( j = 0; j < 3000; j++)
            {
                reg[i].dado3[j] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 26];
            }

            for ( j = 0; j < i; j++)
            {
                if (reg[j].chave == reg[i].chave && i != j)
                {
                    i--;
                    break;
                }
            }
        }
    }
}

void geradorArquivo(int quantidade, int situacao, TRegistro *registros)
{
    geradorRegistros(registros, quantidade, situacao);
    srand(time(NULL));
int i;
    FILE *arq = fopen("dados.bin", "wb");
    if (arq == NULL)
    {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    for ( i = 0; i < quantidade; i++)
    {
        fwrite(&registros[i], sizeof(TRegistro), 1, arq);
    }
    fclose(arq);
}
