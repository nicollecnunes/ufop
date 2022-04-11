#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

#define ASCII_K_1 107
#define ASCII_K_2 75
#define ASCII_S_1 83
#define ASCII_S_2 115
#define ASCII_MAIS 43
#define ASCII_MENOS 45

int ch;
typedef struct 
{
    int saldo;
} tipoThread;

void *soma(void *t)
{
    tipoThread *aux = (tipoThread*)t;
    while(1) 
    {
        if(ch == ASCII_MAIS) 
        {
            printf( "[T:%d | PID:%d] Soma 100UD\n", (int)pthread_self(), getpid());
            aux->saldo += 100;
            ch = 0;
        } else if(ch == ASCII_K_1 || ch == ASCII_K_2) 
        {
            pthread_exit(0);
        }
    }
}

void *subtrai(void *t)
{
    tipoThread *aux = (tipoThread*)t;
    while(1) 
    {
        if(ch == ASCII_MENOS) 
        {
            printf( "[T:%d | PID:%d] Subtrai 50UD\n", (int)pthread_self(), getpid());
            aux->saldo -= 50;
            ch = 0;
        } else if(ch == ASCII_K_1 || ch == ASCII_K_2) 
        {
            pthread_exit(0);
        }
    }
}

void *imprimir(void *t)
{
    tipoThread *aux = (tipoThread*)t;
    while(1) 
    {
        if(ch == ASCII_S_1 || ch == ASCII_S_2) 
        {
            printf( "[T:%d | PID:%d] Imprimindo saldo = %dUD\n", (int)pthread_self(), getpid(), aux->saldo);
            ch = 0;
        } else if(ch == ASCII_K_1 || ch == ASCII_K_2) 
        {
            pthread_exit(0);
        }
    }
    
}


int main()

{
    tipoThread *t = (tipoThread *)malloc(sizeof(tipoThread));
    t->saldo = 0;
    
    printf("\n");
    printf("[+] - Somar 100 UD\n");
    printf("[-] - Subtrair 100 UD\n");
    printf("[s] - Exibir o valor do saldo\n");
    printf("[k] - Finalizar a execucao\n");
    
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, soma, (void *)t);
    pthread_create(&t2, NULL, subtrai, (void *)t);
    pthread_create(&t3, NULL, imprimir, (void *)t);
    
    do 
    {
        do 
        {
            ch = (int)getchar();
            getchar();
        } while(
            (ch != ASCII_MAIS) && 
            (ch != ASCII_MENOS) && 
            (ch != ASCII_S_1) && (ch != ASCII_S_2) && 
            (ch != ASCII_K_1) && (ch != ASCII_K_2)
        );
        
        if(ch == ASCII_K_1 || ch == ASCII_K_2) 
        {
            printf("Kill\n");
            pthread_kill(t1, 0);
            pthread_kill(t2, 0);
            pthread_kill(t3, 0);
        }
        
    } while(ch != ASCII_K_1 || ch != ASCII_K_2);

    return 0;
}