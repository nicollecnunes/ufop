#include "Intercalacao.h"
#include "Files.h"

//Funcao responsavel por fazer a intercalaco no metodo de ordenacao interna
void intercalaPrimeiroMetodo(int quantidade){
    MemoriaInterna memoriaInterna;
    FitasPrimeiroMetodo fitas;
    bool controla_laco_externo = true;
    int controla_fitas_entrada = 0;
    int controla_fitas_saida = 0;
    int controla_memoria_interna = 0;
    Aluno *aluno = malloc(sizeof(Aluno));
    int posicao;

    fitasBinariaModoLeitura(&fitas, 1);
    fitasBinariaModoEscrita(&fitas, 2);

    //Controla o primeiro laço responsavel por fazer toda a intercalacao
    //[TODO: uma condicao de parada sofisticada para o laco externo]
    while (controla_laco_externo){
        inicializaVetorMemoriaInterna(&memoriaInterna);

        //Laco de repeticao responsavel por preencher a memoria interna
        //E tambem, por controlar a leitura separada de cada bloco por fita
        while(memoriaInterna.disponivel){
            //Sai do laco caso o bloco da fita no momento ja foi percorrido
            if(fitas.quantidade_leitura_bloco_fita_entrada[controla_fitas_entrada] == 19) {
                controla_fitas_entrada++;

                if(controla_fitas_entrada == 19)
                    controla_fitas_entrada = 0;

                break;
            }

            //Le e joga na memoria a informacao da fita em questao
            if(fread(aluno, sizeof(*aluno), 1, fitas.fita_entrada[controla_fitas_entrada]) == 1){
                memoriaInterna.memoria_interna[controla_memoria_interna] = *aluno;

                //Percorrendo o bloco da fita em questao
                fitas.quantidade_leitura_bloco_fita_entrada[controla_fitas_entrada]++;
                //Informa a qual fita a informacao lida pertence
                memoriaInterna.fita[controla_memoria_interna] = controla_fitas_entrada;
                //Atualiza a quantidade de memoria disponivel
                controla_fitas_entrada++;
                memoriaInterna.disponivel--;
                break;
            }

            controla_fitas_entrada++;

            if(controla_fitas_entrada == 19)
                controla_fitas_entrada = 0;
        }

        //Memoria cheia
        //Ler o menor valor da memoria interna e escreve  na fita de saida
        if(memoriaInterna.disponivel == 0){
            posicao = menorValor(&memoriaInterna);
            *aluno = memoriaInterna.memoria_interna[posicao];
            fwrite(aluno, sizeof(*aluno), 1,fitas.fita_saida[controla_fitas_saida]);

            fitas.quantidade_escrita_bloco_fita_saida[controla_fitas_saida]++;

            liberaMemoriaInterna(&memoriaInterna, posicao);
        }

        controla_laco_externo = false;
    }

    fechaFitas(&fitas, 1);
    fechaFitas(&fitas, 2);
    free(aluno);
}

//Funcao responsavel por achar o menor valor no vetor, retorna a posicao
int menorValor(MemoriaInterna *memoriaInterna){
    double menor = memoriaInterna->memoria_interna[0].nota;
    int posicao = 0;

    for (int i = 0; i < QUANTIDADE_MEMORIA_INTERNA; ++i){
        if(memoriaInterna->memoria_interna[i].nota < menor && memoriaInterna->memoria_interna[i].nota != -1.0){
            menor = memoriaInterna->memoria_interna[i].nota;
            posicao = i;
        }
    }

    return posicao;
}

//Funcao responsavel por liberar um espaco da memoria interna e disponibilizar ela.
void liberaMemoriaInterna(MemoriaInterna *memoriaInterna, int posicao){
    memoriaInterna->memoria_interna[posicao].nota = -1;
    memoriaInterna->disponivel++;
}



