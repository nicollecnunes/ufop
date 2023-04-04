#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h> 
#include <arpa/inet.h> 

#define MAX 80
#define PORT 8080
#define SA struct sockaddr
#define MAX_LINE 4096
#define LINSTENPORT 7788
#define SERVERPORT 8877
#define BUFFSIZE 4096

void sendfile(FILE *fp, int welcomeSocket){
    int n;
    char sendline[MAX_LINE] = {0};

    while ((n = fread(sendline, sizeof(char), MAX_LINE, fp)) > 0){
        if (n != MAX_LINE && ferror(fp)){
            perror("[ERRO] Não foi possível ler o arquivo.");
            exit(1);
        }
        

        if (send(welcomeSocket, sendline, n, 0) == -1){
            perror("[ERRO] Não foi possível enviar o arquivo.");
            exit(1);
        }

        memset(sendline, 0, MAX_LINE);
    }
}

void checkFile(int welcomeSocket){
    char filename[30];

    printf("\nInforme o nome e extensão completos do arquivo: ");
    scanf("%[^\n]%*c", filename);
    
    if (filename == NULL){
        perror("[ERRO] Verifique o nome do arquivo.");
        exit(1);
    }

    char buff[BUFFSIZE] = {0};
    strncpy(buff, filename, strlen(filename));
    if (send(welcomeSocket, buff, BUFFSIZE, 0) == -1){
        perror("Can't send filename");
        exit(1);
    }

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL){
        perror("[ERRO] Não foi possível abrir o arquivo.");
        exit(1);
    }

    sendfile(fp, welcomeSocket);
    puts("Arquivo enviado...");

    fclose(fp);
}

void redirect(int welcomeSocket){
    char buffer[MAX];
    char opcao[2];
    int n;

    do{
        //limpando buffer
        bzero(buffer, sizeof(buffer));

        printf("\n0- Sair \t 1- Enviar arquivo \t 2- Enviar mensagem \n");
        scanf("%[^\n]%*c", buffer);

        if(strncmp("1", buffer, 1) == 0){
            send(welcomeSocket, buffer, sizeof(buffer), 0);
            checkFile(welcomeSocket);
        } else if(strncmp(buffer, "2", 1) == 0){
            send(welcomeSocket, buffer, sizeof(buffer), 0);
            printf("\nDigite uma mensagem: ");
            scanf("%[^\n]%*c", buffer);
            strcat(buffer, "\n");

            send(welcomeSocket, buffer, sizeof(buffer), 0);

            printf("\n...Aguardando resposta do servidor...\n\n");

            
            bzero(buffer, sizeof(buffer));
            recv(welcomeSocket, buffer, sizeof(buffer), 0);

            if(strncmp("0", buffer, 1) != 0)
                printf("\tServidor responde: : %s", buffer);
        }

    } while(strncmp(buffer, "2", 1) == 0);

    printf("Encerrando conexão com servidor...\n");
}

int main(){
    int welcomeSocket, connfd, port;
    struct sockaddr_in serverAddr, cli;
    char IP[30];

    // cria o socket com três argumentos
    // 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case)
    welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (welcomeSocket == -1) {
        printf("Falha na criação do socket...\n");
        exit(0);
    }
    else
        printf("Socket criado com sucesso..\n");

    bzero(&serverAddr, sizeof(serverAddr));

    printf("Informe a porta do servidor:\n");
    scanf("%d", &port);
    getchar();

    printf("Informe o IP do servidor:\n");
    scanf("%[^\n]%*c", IP);

    printf("\n");

    // instancia IP, PORT
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(IP);
    serverAddr.sin_port = htons(port);

    // conecta o cliente socket ao servidor
    if (connect(welcomeSocket, (SA*)&serverAddr, sizeof(serverAddr)) != 0) {
        printf("Falha na conexão com o servidor...\n");
        exit(0);
    }
    else
        printf("Conectado com o servidor..\n");

    // função para o chat
    redirect(welcomeSocket);

    // fecha o socket
    close(welcomeSocket);

    return 0;
}