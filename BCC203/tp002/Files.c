#include "Files.h"
#include "Util.h"

// cria os arquivos necessários
void criarArquivos(FILE** arqLEs, FILE** arqLi, FILE** arqEi, FILE** arqTxt, int situacao, int n){
	FILE *arqBin;

	switch(situacao){
		case 1:
		{ // 1 - arquivo ordenado ascendentemente
			if((arqBin = fopen("PROVAO1.bin", "wb")) == NULL){
				printf("Erro com o arquivo PROVAO1.bin\n");
				exit(1);
			}
            // converte o arquivo txt em binario
			txt2Bin(*arqTxt, arqBin, n);
			fclose(arqBin);

			if((*arqLi = fopen("PROVAO1.bin", "r+b")) == NULL){
				printf("Erro com o arquivo PROVAO1.bin\n");
				exit(1);
			}

			if((*arqEi = fopen("PROVAO1.bin", "r+b")) == NULL){
				printf("Erro com o arquivo PROVAO1.bin\n");
				exit(1);
			}

			if((*arqLEs = fopen("PROVAO1.bin", "r+b")) == NULL){
				printf("Erro com o arquivo PROVAO1.bin\n");
				exit(1);
			}

			break;
		}

		case 2:
		{ // 2 - arquivo ordenado descendentemente
			if((arqBin = fopen("PROVAO2.bin", "wb")) == NULL){
                printf("Erro com o arquivo PROVAO2.bin\n");
				exit(1);
			}

			txt2Bin(*arqTxt, arqBin, n);

			fclose(arqBin);

			if((*arqLi = fopen("PROVAO2.bin", "r+b")) == NULL){
				printf("Erro com o arquivo PROVAO2.bin\n");
				exit(1);
			}

			if((*arqEi = fopen("PROVAO2.bin", "r+b")) == NULL){
				printf("Erro com o arquivo PROVAO2.bin\n");
				exit(1);
			}

			if((*arqLEs = fopen("PROVAO2.bin", "r+b")) == NULL){
				printf("Erro com o arquivo PROVAO2.bin\n");
				exit(1);
			}

			break;
		}

		case 3:
		{ // 3 - arquivo desordenado aleatoriamente
			if((arqBin = fopen("PROVAO3.bin", "wb")) == NULL){
        		printf("Erro com o arquivo PROVAO3.bin\n");
				exit(1);
			}
            // converte o .txt em .bin
			txt2Bin(*arqTxt, arqBin, n);
			fclose(arqBin);

			if((*arqLi = fopen("PROVAO3.bin", "r+b")) == NULL){
				printf("Erro com o arquivo PROVAO3.bin\n");
				exit(1);
			}

			if((*arqEi = fopen("PROVAO3.bin", "r+b")) == NULL){
				printf("Erro com o arquivo PROVAO3.bin\n");
				exit(1);
			}

			if((*arqLEs = fopen("PROVAO3.bin", "r+b")) == NULL){
				printf("Erro com o arquivo PROVAO3.bin\n");
				exit(1);
			}

			break;
		}
	}
}

// le um .txt e converte-o em .bin
void txt2Bin(FILE* txtOrigem, FILE* binFinal, int n){
	long int nroInscricao;
	double nota;
	char estado[3];
	char cidade[51];
	char curso[31];

	int i = 0;

	while(i < n){
		fscanf(txtOrigem, "%ld", &nroInscricao);
		fscanf(txtOrigem, "%lf", &nota);
		fgets(estado, 2, txtOrigem);
		fgets(cidade, 50, txtOrigem);
		fgets(curso, 30, txtOrigem);

		Aluno* aluno = malloc(sizeof(Aluno));
		aluno->inscricao = nroInscricao;
		aluno->nota = nota;
		strcpy(aluno->estado, estado);
		strcpy(aluno->cidade, cidade);
		strcpy(aluno->curso, curso);
		// aluno->isMarked = 0;

		fwrite(aluno, sizeof(Aluno), 1, binFinal);
		free(aluno);

		i++;
	}
}

// le um .bin e converte-o em .txt
void bin2Txt(FILE* binOrigem, FILE* txtFinal, int n){
	long int nroInscricao;
	double nota;
	char estado[3];
	char cidade[51];
	char curso[31];

	int i = 0;
    Aluno* aluno = malloc(sizeof(Aluno));

	while(fread(aluno, sizeof(Aluno), 1, binOrigem) == 1){
		nroInscricao = aluno->inscricao;
		nota = aluno->nota;
		strcpy(estado, aluno->estado);
		strcpy(cidade, aluno->cidade);
		strcpy(curso, aluno->curso);

        formatInscricao(nroInscricao, 1, txtFinal);
        formatNota(nota, 1, txtFinal);

		fprintf(txtFinal, "%-s %-s %-s\n", estado, cidade, curso);
		i++;
	}
	//fclose(binOrigem);

    free(aluno);
	remove("PROVAO.bin");
	remove("PROVAO1.bin");
	remove("PROVAO2.bin");
}

void transformaFitas(FitasPrimeiroMetodo *fitas, int quantidade){
    char nome_arquivo[50];
    char nome_arquivo_leitura[50];
    
    //Leitura das fitas binarias, passando para txt
    FILE *fitas_entradas_leitura[QUANTIDADE_FITAS];
    for (int i = 0; i < QUANTIDADE_FITAS; ++i) {
        sprintf(nome_arquivo, "fitaEntrada%d.bin", i + 1);
        fitas->fita_entrada[i] = fopen(nome_arquivo, "rb");
        strcpy(nome_arquivo_leitura, "");
        sprintf(nome_arquivo_leitura, "fitaEntradaLeitura%d.txt", i + 1);
        fitas_entradas_leitura[i] = fopen(nome_arquivo_leitura, "w");
        bin2Txt(fitas->fita_entrada[i], fitas_entradas_leitura[i], quantidade);
    }
    for (int i = 0; i < QUANTIDADE_FITAS; ++i) {
        fclose(fitas->fita_entrada[i]);
        fclose(fitas_entradas_leitura[i]);
    }
}
