#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#ifndef TRANSFER_FILE_TRANSFER_H
#define TRANSFER_FILE_TRANSFER_H

#define MAX_LINE 4096
#define LINSTENPORT 7788
#define SERVERPORT 8877
#define BUFFSIZE 4096
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

#endif

void writefile(int welcomeSocket, FILE *fp){
    ssize_t n;
    char buff[MAX_LINE] = {0};

    while ((n = recv(welcomeSocket, buff, MAX_LINE, 0))) {
        if (n == -1){
            perror("[ERRO] Não foi possível receber o arquivo");
            exit(1);
        }
        

        if (fwrite(buff, sizeof(char), n, fp) != n){
            perror("[ERRO] Erro ao executar fwrite()");
            exit(1);
        }
        memset(buff, 0, MAX_LINE);
    }
}

void checkFile(int welcomeSocket){
    char filename[BUFFSIZE] = {0};
    //bzero(filename, MAX);
    
    if (recv(welcomeSocket, filename, BUFFSIZE, 0) == -1){
        perror("[ERRO] Não foi possível receber o nome do arquivo.");
        exit(1);
    }

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("[ERRO] Não foi possível abrir o arquivo.");
        exit(1);
    }

    writefile(welcomeSocket, fp);
    puts("Arquivo recebido com sucesso");

    fclose(fp);
}

// Função designada para chat entre cliente e servidor
void redirect(int welcomeSocket){
    char buffer[MAX];
    int n;
    // loop infinito para o chat
    do{
        bzero(buffer, MAX);

        // le a mensagem do cliente e copia para o buffer
        recv(welcomeSocket, buffer, sizeof(buffer), 0);

        if(strncmp("1", buffer, 1) == 0){
            printf("Recebendo o arquivo...\n");
            //bzero(buffer, MAX);
            checkFile(welcomeSocket);
            send(welcomeSocket, "Arquivo recebido...", sizeof(buffer), 0);
        } else if(strncmp("2", buffer, 1) == 0){
            bzero(buffer, MAX);
            recv(welcomeSocket, buffer, sizeof(buffer), 0);

            // printa o buffer que contém o conteúdo do cliente
            printf("\nMensagem do cliente: %s\t Resposta para o cliente : ", buffer);
            
            bzero(buffer, MAX);
            scanf("%[^\n]%*c", buffer);
            strcat(buffer, "\n");

            // e envia o buffer para o cliente
            send(welcomeSocket, buffer, sizeof(buffer), 0);
            printf("\n...Aguardando mensagem do cliente...\n\n");
        } else {
            send(welcomeSocket, buffer, sizeof(buffer), 0);
        }

    }  while(strncmp("0", buffer, 1) != 0);


    printf("Cliente solicitou fechar conexão...\n");
    
}


// Driver connectionChattion
int main(){
    int welcomeSocket, newSocket, addrlen;
    struct sockaddr_in servaddr, clientaddr;

    // cria o socket e verificação
    welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (welcomeSocket == -1) {
        printf("Falha na criação do socket...\n");
        exit(0);
    }
    else
        printf("Socket criado com sucesso...\n");
    bzero(&servaddr, sizeof(servaddr));

    // instancia IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // conecta o socket recem criado a um IP e verificação
    if ((bind(welcomeSocket, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Ligação com o socket falhou...\n");
        exit(0);
    }
    else
        printf("Ligação com socket criada com sucesso...\n");

    // agora o servidor está pronto para ouvir e verificar
    if ((listen(welcomeSocket, 5)) != 0) {
        printf("Falha na escuta...\n");
        exit(0);
    }
    else
        printf("Servidor ouvindo..\n");
    addrlen = sizeof(clientaddr);

    // aceita os pacotes de dados do cliente e verifica 
    newSocket = accept(welcomeSocket, (SA*)&clientaddr, &addrlen);
    if (newSocket < 0) {
        printf("Falha na aceitação do servidor...\n");
        exit(0);
    }
    else
        printf("Servidor aceitou o cliente...\n");

    // função para conversar entre cliente e servidor
    redirect(newSocket);

    // depois de conversar fecha o socket
    close(newSocket);

    return 0;
}