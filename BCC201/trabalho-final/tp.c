/*Nicolle Canuto Nunes - 20.1.4022 - 
 *TRABALHO PRÁTICO - RESTA UM*/
#include"CORES.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


int checa(int **mat, int nx, int ny, char x, char y,int l, int c);
void move(int **mat, int nx, int ny, char x, char y, char mov);
void imprimeexe(int exe1[7][7],int exe2[7][7], int exe3[7][7]);

void cabecalho(){ // função cabeçalho, é chamada o tempo todo quando a tela é "resetada"
	printf(MAGENTA("\n=====================================================================\n"));
	printf(MAGENTA(" ______    _______  _______  _______  _______      __   __  __   __\n"));
	printf(MAGENTA("|    _ |  |       ||       ||       ||   _   |    |  | |  ||  |_|  |\n"));
	printf(MAGENTA("|   | ||  |    ___||  _____||_     _||  |_|  |    |  | |  ||       |\n"));
	printf(MAGENTA("|   |_||_ |   |___ | |_____   |   |  |       |    |  |_|  ||       |\n"));
	printf(MAGENTA("|    __  ||    ___||_____  |  |   |  |       |    |       ||       |\n"));
	printf(MAGENTA("|   |  | ||   |___  _____| |  |   |  |   _   |    |       || ||_|| |\n"));
	printf(MAGENTA("|___|  |_||_______||_______|  |___|  |__| |__|    |_______||_|   |_|\n\n"));
	printf(MAGENTA("======================================================================\n\n"));
}

int** criajogorand(int *linhas, int *colunas){ //caso a pessoa não tenha carregado um arquivo, essa função é chamada
	int t=0,j,i,o,ale;
	int **mat;

	printf("Não foi possível ler seu arquivo :( \n");
	printf("Vamos gerar um jogo pra você! Escolha uma opção: \n\n");

	printf("1) Escolher entre jogos padrão\n"); //6 opções de jogos no formato padrão (cruz no 7x7). todos tem solução
	printf("2) Gerar um jogo aleatório\n"); // jogo totalmente aleatório em relação as dimensões
	scanf("%d", &o);

	if (o == 1){
		*linhas =7;
		*colunas =7;
		printf("Escolha seu tabuleiro!\n\n"); 

		int exemplo1[7][7] = {{-1,-1,0,0,0,-1,-1},
 							 {-1,-1,0,1,0,-1,-1},
							 {0,0,1,1,1,0,0},
							 {0,0,0,1,0,0,0},
							 {0,0,0,1,0,0,0},
							 {-1,-1,0,0,0,-1,-1},
							 {-1,-1,0,0,0,-1,-1}};	
		int exemplo2[7][7] = {{-1,-1,0,0,0,-1,-1},
 							 {-1,-1,0,1,0,-1,-1},
							 {0,0,0,1,0,0,0},
							 {0,1,1,1,1,1,0},
							 {0,0,0,1,0,0,0},
							 {-1,-1,0,1,0,-1,-1},
							 {-1,-1,0,0,0,-1,-1}};
		int exemplo3[7][7] = {{-1,-1,1,1,1,-1,-1},
 							 {-1,-1,1,1,1,-1,-1},
							 {1,1,1,1,1,1,1},
							 {1,1,1,0,1,1,1},
							 {1,1,1,1,1,1,1},
							 {-1,-1,1,1,1,-1,-1},
							 {-1,-1,1,1,1,-1,-1}};

		imprimeexe(exemplo1, exemplo2, exemplo3); //imprime os três tabuleiros padrão, lado a lado
		printf("\n       1) CRUZ                   2) MAIS                  3) PADRÃO\n\n\n\n");

		int exemplo4[7][7] = {{-1,-1,0,0,0,-1,-1},
 							 {-1,-1,0,1,0,-1,-1},
							 {0,0,1,1,1,0,0},
							 {0,1,1,1,1,1,0},
							 {1,1,1,1,1,1,1},
							 {-1,-1,0,0,0,-1,-1},
							 {-1,-1,0,0,0,-1,-1}};
		int exemplo5[7][7] = {{-1,-1,0,1,0,-1,-1},
 							 {-1,-1,1,1,1,-1,-1},
							 {0,0,0,1,0,0,0},
							 {0,0,0,1,0,0,0},
							 {0,0,0,1,0,0,0},
							 {-1,-1,1,1,1,-1,-1},
							 {-1,-1,1,1,1,-1,-1}};	 
		int exemplo6[7][7] = {{-1,-1,1,1,1,-1,-1},
 							 {-1,-1,1,1,1,-1,-1},
							 {0,0,1,1,1,0,0},
							 {0,0,1,0,1,0,0},
							 {0,0,0,0,0,0,0},
							 {-1,-1,0,0,0,-1,-1},
							 {-1,-1,0,0,0,-1,-1}};

		imprimeexe(exemplo4, exemplo5, exemplo6); //imprime mais três tabuleiros padrão, lado a lado
		printf("\n     4) PRÂMIDE                 5) SETA                  6) LAREIRA\n");
		
		scanf("%d",&t);

		system("clear");

		if (t==1){	//a pessoa escolheu o 1) CRUZ
			mat = (int**) malloc(sizeof(int*)* *linhas); 

			for(i=0;i<*linhas;i++){
				mat[i] = (int*) malloc(sizeof(int)* *colunas); 
			}

			for (i=0; i<*linhas; i++){
				for (j=0; j<*colunas; j++){
					 mat[i][j] = exemplo1[i][j];
				}
			} 
		}else if(t==2){ //a pessoa escolheu o 2) MAIS
			mat = (int**) malloc(sizeof(int*)* *linhas); 

			for(i=0;i<*linhas;i++){
				mat[i] = (int*) malloc(sizeof(int)* *colunas); 
			}

			for (i=0; i<*linhas; i++){
				for (j=0; j<*colunas; j++){
					 mat[i][j] = exemplo2[i][j];
				}
			} 
		}else if(t==3){ //a pessoa escolheu o 3) PADRÃO
			mat = (int**) malloc(sizeof(int*)* *linhas); 

			for(i=0;i<*linhas;i++){
				mat[i] = (int*) malloc(sizeof(int)* *colunas); 
			}

			for (i=0; i<*linhas; i++){
				for (j=0; j<*colunas; j++){
					 mat[i][j] = exemplo3[i][j];
				}
			} 
		}else if(t==4){ //a pessoa escolheu o 4) PIRÂMIDE
			mat = (int**) malloc(sizeof(int*)* *linhas); 

			for(i=0;i<*linhas;i++){
				mat[i] = (int*) malloc(sizeof(int)* *colunas); 
			}

			for (i=0; i<*linhas; i++){
				for (j=0; j<*colunas; j++){
					 mat[i][j] = exemplo4[i][j];
				}
			} 
		}else if(t==5){ //a pessoa escolheu o 5) SETA
			mat = (int**) malloc(sizeof(int*)* *linhas); 

			for(i=0;i<*linhas;i++){
				mat[i] = (int*) malloc(sizeof(int)* *colunas); 
			}

			for (i=0; i<*linhas; i++){
				for (j=0; j<*colunas; j++){
					 mat[i][j] = exemplo5[i][j];
				}
			} 
		}else if(t==6){ //a pessoa escolheu o 6) LAREIRA
			mat = (int**) malloc(sizeof(int*)* *linhas); ''

			for(i=0;i<*linhas;i++){
				mat[i] = (int*) malloc(sizeof(int)* *colunas); 
			}

			for (i=0; i<*linhas; i++){
				for (j=0; j<*colunas; j++){
					 mat[i][j] = exemplo6[i][j];
				}
			} 
		}
		return mat;
	}else if (o == 2){
		do{
			system("clear");
			cabecalho();
			printf("Escolha o tamanho do seu tabuleiro!\n\n"); //caso a pessoa queira um tabuleiro aleatório

			printf("1) Jogo do Flash (No máximo 5x5)\n");
			printf("2) Passa Tempo (Maior que 3x3, No máximo 10x10)\n");
			printf("3) Passa Anos (Maior que 10x10, no máximo 20x20)\n");

			scanf("%d", &t);
		}while((t!=1)&&(t!=2)&&(t!=3));
		
		system("clear");

		if (t==1){	//geram as dimensões com base na escolha da pessoa
			*linhas = rand () % (5-1+1) + 1;		
			*colunas = rand () % (5-1+1) + 1;  
		}else if(t==2){
			*linhas = rand () % (10-4+1) + 1;		
			*colunas = rand () % (10-4+1) + 1; 
		}else if(t==3){
			*linhas = rand () % (20-11+1) + 10;		
			*colunas = rand () % (20-11+1) + 10; 
		}
	}

	
	mat = (int**) malloc(sizeof(int*)* *linhas); 

	for(i=0;i<*linhas;i++){
		mat[i] = (int*) malloc(sizeof(int)* *colunas); 
	}

	
	for (i=0; i<*linhas; i++){ //preenche a matriz com -1,0 e 1. falei sobre essa parte na seção 2.2 do relatório
		for (j=0; j<*colunas; j++){
			ale = rand()%100;
			if(ale<=8){
				mat[i][j] = -1;
			}else if((ale<=58) &&(ale>8)){
				mat[i][j] = 0;
			}else{
				mat[i][j] = 1;
			}
		}
	}
	return mat;
}

void imprimeexe(int exe1[7][7],int exe2[7][7], int exe3[7][7]){ //imprime 3 exemplos, lado a lado
	int i1, j1;
	for (i1=0; i1<7; i1++){
		for (j1=0; j1<7; j1++){
			if ((exe1[i1][j1])==1){
				printf(BG_MAGENTA(BOLD(" * ")));
			}else if((exe1[i1][j1])==-1){
				printf(BG_WHITE("   "));
			}else if((exe1[i1][j1])==0){
				printf(BG_MAGENTA(BLACK(" - ")));
			}
		}
		printf("     ");
		for (j1=0; j1<7; j1++){
			if ((exe2[i1][j1])==1){
				printf(BG_MAGENTA(BOLD(" * ")));
			}else if((exe2[i1][j1])==-1){
				printf(BG_WHITE("   "));
			}else if((exe2[i1][j1])==0){
				printf(BG_MAGENTA(BLACK(" - ")));
			}
		}
		printf("     ");
		for (j1=0; j1<7; j1++){
			if ((exe3[i1][j1])==1){
				printf(BG_MAGENTA(BOLD(" * ")));
			}else if((exe3[i1][j1])==-1){
				printf(BG_WHITE("   "));
			}else if((exe3[i1][j1])==0){
				printf(BG_MAGENTA(BLACK(" - ")));
			}
		}
		printf("\n");
	}
}


int** criajogo(int *linhas, int *colunas, char **argv){ //lê e aloca a matriz do arquivo carregado pela pessoa
	int **mat;
	int i, j;

	FILE *arquivo;
	arquivo = fopen(argv[1], "r");

	fscanf(arquivo, "%d", linhas);
	fscanf(arquivo, "%d", colunas);

	mat = (int**) malloc(sizeof(int*)* *linhas); 

	for(i=0;i<*linhas;i++){
		mat[i] = (int*) malloc(sizeof(int)* *colunas); 
	}


	for (i=0; i<*linhas; i++){
		for (j=0; j<*colunas; j++){
			fscanf(arquivo, "%d", &mat[i][j]);
		}
	}
	printf("Arquivo lido com sucesso! Iniciando o seu jogo... \n\n");
	system("clear");

	fclose(arquivo);
	return mat;
}
	

void imprimemat(int **mat, int *linhas, int *colunas){ //imprime o jogo atual. função chamada o tempo todo, após o cabeçalho
	int i, j;
	char n,m = 'A';

	printf("\n\n");
	printf("                      ");
    for (n = 'A'; n < *colunas + 65; n++){ // imprime A,B,C.. em uma linha, de acordo com qts colunas tem a matriz
        printf(MAGENTA(BOLD(" %c ")), n);
    }
    printf("\n\n");

	for (i=0; i<*linhas; i++){
		printf(MAGENTA(BOLD(" %19c  ")), m);; //imprime A,B,C.. antes de cada linha (em uma coluna), de acordo com o nº de Linhas
		for (j=0; j<*colunas; j++){
			if ((mat[i][j])==1){
				printf(BG_MAGENTA(BOLD(" * "))); //substitui 1 por *
			}else if((mat[i][j])==-1){
				printf(BG_WHITE("   ")); //substitui -1 por espaço
			}else if((mat[i][j])==0){
				printf(BG_MAGENTA(BLACK(" - "))); //substitui 0 por -
			}
		}
		printf("\n");
		m++;
	}
	printf("\n");
}

void criafile(int **mat, int *linhas, int *colunas, char name[]){// cria um .txt com o nome passado pela pessoa no comando de salvar
	FILE *file;
	int i,j;

	strcat(name, ".txt");
	printf("Nome do arquivo: %s", name);

	file = fopen(name, "w");

	fprintf(file, "%d ", *linhas);
	fprintf(file, "%d", *colunas);
	fprintf(file, "\n\n");


	for (i=0; i<*linhas; i++){
		for (j=0; j<*colunas; j++){
			fprintf(file, "%3d ", mat[i][j]);
		}
		fprintf(file, "\n");
	}
	printf("\nSeu jogo foi salvo no estado atual!\n");
	fclose(file);
}

int vesepode(int **mat, char dir[], char x, char y, int linhas, int colunas){ //ve se o pino existe e chama as funçoes para validar/mover
	x = x-65;
	y = y-65;
	char mov;

	if ((mat[(int) x][(int) y])==1){
		if (dir[0] == 'c'){//cima: -1 nas linhas
			if ((checa(mat, -1, 0, x, y, linhas, colunas)) == 0){
				mov ='c';
				move(mat, -1, 0, x, y, mov);
				return 0;
			}else{
				system("clear");
				printf(RED("\nMovimento inválido!    "));
				return 1;
			}
		}else if (dir[0] == 'b'){//baixo: +1 nas linhas
			if ((checa(mat, +1, 0, x, y, linhas, colunas)) == 0){
				mov ='b';
				move(mat, +1, 0, x, y,mov);
				return 0;
			}else{
				system("clear");
				printf(RED("\nMovimento inválido!    "));
				return 1;	
			}
		}else if (dir[0] == 'e'){//esquerda: -1 nas colunas
			if ((checa(mat, 0, -1, x, y, linhas, colunas)) == 0){
				mov ='e';
				move(mat, 0, -1, x, y,mov);
				return 0;
			}else{
				system("clear");
				printf(RED("\nMovimento inválido!    "));
				return 1;			
			}		
		}else if (dir[0] == 'd'){//direita: +1 nas colunas
			if ((checa(mat, 0, +1, x, y, linhas, colunas)) == 0){
				mov ='d';
				move(mat, 0, +1, x, y,mov);
				return 0;
			}else{
				system("clear");
				printf(RED("\nMovimento inválido!    "));
				return 1;
			}
		}
	}	
	system("clear");
	printf(RED("\nMovimento inválido!    "));
	return 1;
}

int checa(int **mat, int nx, int ny, char x, char y, int l, int c){ //valida o movimento completamente
	if ((x<l) && (y<c) && ((mat[(int) x][(int) y])==1)){ //ve se XY do pino está dentro da matriz e se o pino existe
		if ((x + nx < l) && (y + ny < c) && (x + (2 * nx) < l) && (y + (2 * ny) < c)){//ve se a nova posição e a do pino a ser comido está dentro
			if ((x + nx >= 0) && (y + ny >= 0) && (x + (2 * nx) >= 0) && (y + (2 * ny) >= 0)){//ve se a nova posição e a do pino nao sao negativos
				if (((mat[x + nx][y + ny])==1)&&((mat[x + (2 * nx)][y + (2 * ny)])==0)){ //ve se existe o pino a ser comido e se a posição final é vazia
					return 0;
				}else{
					return 1;
				}
			}else{
				return 1;
			}		
		}else{
			return 1;
		}
	}else{
		return 1;
	}
			
}

void move(int **mat, int nx, int ny, char x, char y, char mov){ //faz o movimento
	mat[(int)x][(int)y] = 0; //a casa que o pino estava fica vazia
	mat[x + nx][y + ny] = 0; //o pino que estava no trajeto é comido
	mat[x + (2 * nx)][y + (2 * ny)] = 1; //o pino que moveu vai pra posição final
	printf(GREEN("Movido: %c %c%c"),mov, x+65, y+65);
}

int jogavel(int **mat, int linhas, int colunas){//ve se ainda há movimentos possiveis
	int mov=0,i,j, pin=0;
	for (i=0; i<linhas; i++){
		for (j=0; j<colunas; j++){
			if (mat[i][j] == 1){ //mesmo que essa validação ja exista em checa(), é bom fazer antes pra ter menos execuções
				pin++;
				if ((checa(mat, -1, 0, i, j, linhas, colunas)) == 0){ //cima
					//printf("pode em: %d %d para cima\n", i,j);
					mov++;
				}if ((checa(mat, +1, 0, i, j, linhas, colunas)) == 0){ //baixo
					//printf("pode em: %d %d para baixoa\n", i,j);
					mov++;
				}if ((checa(mat, 0, -1, i, j, linhas, colunas)) == 0){ //esquerda
					//printf("pode em: %d %d para esquerda\n", i,j);
					mov++;
				}if ((checa(mat, 0, +1, i, j, linhas, colunas)) == 0){ //direita
					//printf("pode em: %d %d para direita\n", i,j);
					mov++;
				}
			}						
		}
	}if(mov!=0){
		system("clear");
		printf(" Vejo %d movimentos possíveis!\n", mov);
		return 0;

	}else{
		system("clear");
		printf("Sem movimentos possíveis! FIM DE JOGO. ");
		printf(GREEN("%d pino restantes.\n"), pin);
		if(pin == 1){//se nao tem mais movimentos e só tem 1 pino, a pessoa vence		
			cabecalho();
			printf(GREEN(" _______  _______  __    _  __   __  _______  __   __ \n"));
			printf(GREEN("|       ||   _   ||  |  | ||  | |  ||       ||  | |  |\n"));
			printf(GREEN("|    ___||  |_|  ||   |_| ||  |_|  ||   _   ||  | |  |\n"));
			printf(GREEN("|   | __ |       ||       ||       ||  | |  ||  |_|  |\n"));
			printf(GREEN("|   ||  ||       ||  _    ||       ||  |_|  ||       |\n"));
			printf(GREEN("|   |_| ||   _   || | |   ||   _   ||       ||       |\n"));
			printf(GREEN("|_______||__| |__||_|  |__||__| |__||_______||_______|\n\n"));
			imprimemat(mat, &linhas, &colunas);
		}else{ //se nao tem mais movimentos e tem mais de um pino, a pessoa perdeu
			cabecalho();
			printf(RED(" _______  _______  ______    ______   _______  __   __ \n"));
			printf(RED("|       ||       ||    _ |  |      | |       ||  | |  |\n"));
			printf(RED("|    _  ||    ___||   | ||  |  _    ||    ___||  | |  |\n"));
			printf(RED("|   |_| ||   |___ |   |_||_ | | |   ||   |___ |  |_|  |\n"));
			printf(RED("|    ___||    ___||    __  || |_|   ||    ___||       |\n"));
			printf(RED("|   |    |   |___ |   |  | ||       ||   |___ |       |\n"));
			printf(RED("|___|    |_______||___|  |_||______| |_______||_______|\n\n"));
			imprimemat(mat, &linhas, &colunas);
		}	
		return 1;
	}
}

void ajuda(int x, int **mat, int linhas, int colunas){
	int m=0,i,j;
	char mov;
		do{
			for (i=0; i<linhas; i++){
				for (j=0; j<colunas; j++){
					if ((checa(mat, -1, 0, i, j, linhas, colunas)) == 0){ //cima
						mov = 'c';
						move(mat, -1, 0, i, j,mov);
						m++;
						j=colunas;
						i=linhas;
						break;
					}
					if ((checa(mat, +1, 0, i, j, linhas, colunas)) == 0){ //baixo
						mov = 'b';
						move(mat, +1, 0, i, j, mov);	
						m++;
						j=colunas;
						i=linhas;
						break;
					}
					if ((checa(mat, 0, -1, i, j, linhas, colunas)) == 0){ //esquerda
						mov = 'e';
						move(mat, 0, -1, i, j, mov);	
						m++;
						j=colunas;
						i=linhas;
						break;
					}
					if ((checa(mat, 0, +1, i, j, linhas, colunas)) == 0){ //direita
						mov = 'd';
						move(mat, 0, +1, i, j, mov);
						m++;
						j=colunas;
						i=linhas;
						break;
					}				
				}//"m" deve atingir x
			}
		}while((m<x) && (jogavel(mat, linhas, colunas))==0);
		printf(GREEN(" Movimento(s) realizado(s)!"));
		if(m<x){
			printf(YELLOW(" Não foi possível realizar %d movimentos. \n%d Movimentos foram feitos. "), x, m);
		}
}


int main(int argc, char **argv){
	srand(time(NULL));
	int **mat;
	int linhas=0, colunas=0,n,i;
	char dir[10],x,y, name[20] = "aleatorio";
	cabecalho();

	
	if(argv[1]==NULL){//se a pessoa não passou o arquivo/deu algum problema
		mat = criajogorand(&linhas, &colunas);
		criafile(mat, &linhas, &colunas, name);
	}else{
		mat = criajogo(&linhas, &colunas, argv);
	}

	system("clear");
	while((jogavel(mat, linhas, colunas))==0){
		cabecalho();
		imprimemat(mat, &linhas, &colunas);
		printf("Digite o comando: \n");
		scanf("%s", dir);
		getchar();
		if((dir[0] == 'c') || (dir[0] == 'b') ||(dir[0] == 'e') ||(dir[0] == 'd')){
			scanf("%c %c", &x, &y);
			system("clear");
			vesepode(mat, dir, x, y, linhas, colunas);
		}else if(strcmp(dir, "ajuda")==0){
			scanf("%d", &n);
			system("clear");
			ajuda(n, mat, linhas,colunas);
		}else if(strcmp(dir, "salvar")==0){
			scanf("%s", name);
			getchar();
			system("clear");
			criafile(mat, &linhas, &colunas, name);
		}else if(strcmp(dir, "sair")==0){
			break;
		}		
	}

	for(i=0;i<linhas;i++){//libera a memoria
		free(mat[i]);
	}
	free(mat);
	
	return 0;
}