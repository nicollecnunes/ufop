#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define READ  0
#define WRITE 1

#define ASCII_K_1 107
#define ASCII_K_2 75
#define ASCII_S_1 83
#define ASCII_S_2 115
#define ASCII_MAIS 43
#define ASCII_MENOS 45


int main()
{
    int pipeSaldo[2];
    int pipeOpcao[2];
    int caractere = 0;

    printf("\n");
    printf("[+] Somar 100 UD\n");
    printf("[-] Subtrair 50 UD\n");
    printf("[s] Imprimir o saldo\n");
    printf("[k] Finalizar a execucao\n>>> ");

    if (pipe(pipeSaldo) < 0 || pipe(pipeOpcao) < 0)
    {
        printf("Erro na criação do pipe.\n");
        exit(1);
    }
    
    // testando escrita no pipe
    int aux = 0;
    if (write(pipeSaldo[WRITE], &aux, sizeof(int)) == -1)
    {
        printf("Erro na escrita\n");
        exit(1);
    }

    pid_t processoPai = getpid();
    pid_t processoFilho1 = fork();

    if (processoFilho1 < 0)
    {
        printf("Erro  na criação do fork 1.\n");
        exit(1);
    }
    fflush(stdin);

    pid_t processoFilho2 = -1;

    // garantindo mesmo pai
    if (getpid() == processoPai)
    {
        processoFilho2 = fork();
        if (processoFilho2 < 0)
        {
            printf("Erro  na criação do fork 2.\n");
            exit(1);
        }
        if (processoFilho2 == 0)
        {
            processoFilho1 = -1;
        }
    }

    if (getpid() == processoPai)
    {
        int x;
        while(caractere != ASCII_K_1 || caractere != ASCII_K_2)
        {

            do
            {
                caractere = (int)getchar();
            }while((caractere != ASCII_MAIS) && (caractere != ASCII_S_1) && (caractere != ASCII_S_2) && (caractere != ASCII_K_1) && (caractere != ASCII_K_2) && (caractere != ASCII_MENOS));

            if (caractere == ASCII_S_1 || caractere == ASCII_S_2)
            {
                // le, imprime e escreve
                read(pipeSaldo[READ], &x, sizeof(int));
                printf(">>> [PID-%d] Saldo: %dUD\n", getpid(), x);
                write(pipeSaldo[WRITE], &x, sizeof(int));
            }
            else
            {
                // so escreve
                write(pipeOpcao[WRITE], &caractere, sizeof(int));
            }

            // mata os processos
            if (caractere == ASCII_K_1 ||caractere == ASCII_K_2)
            {
                
                kill(processoFilho1, SIGKILL);
                kill(processoFilho2, SIGKILL);
                kill(getpid(), SIGKILL);
                exit(0);
            }
        }
    }

    else if (processoFilho1 == 0)
    { // soma
        int operacao;
        int x;

        do
        {
            read(pipeOpcao[READ], &operacao, sizeof(int));
            if (operacao == ASCII_MAIS)
            {   
                printf(">>> [PID-%d] Soma 100UD\n", getpid());  
                read(pipeSaldo[READ], &x, sizeof(int));
                x += 100;
                write(pipeSaldo[WRITE], &x, sizeof(int));
            }

            else
            {
                write(pipeOpcao[WRITE], &operacao, sizeof(int)); 
            }

        }while(operacao != ASCII_K_1 ||operacao != ASCII_K_2 );
    }

    else if (processoFilho2 == 0)
    { // subtrai
        int operacao;
        int x;

        do
        {
            read(pipeOpcao[READ], &operacao, sizeof(int));
            if(operacao == ASCII_MENOS)
            {
                printf(">>> [PID-%d] Subtrai 50UD\n", getpid());
                read(pipeSaldo[READ], &x, sizeof(int));
                x -= 50;
                write(pipeSaldo[WRITE], &x, sizeof(int));
            }

            else
            {
                write(pipeOpcao[WRITE], &operacao, sizeof(int)); 
            }

        }while(operacao != ASCII_K_1 ||operacao != ASCII_K_2);
    }
    
    return 0;
}