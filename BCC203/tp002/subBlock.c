#include "subBlock.h"

void mainSubBlock(AlunoMarcas *v1, FitasPrimeiroMetodo *fitas, int quantidade, Analise *a)
{
  Aluno *ordenados = (Aluno *)malloc(QUANTIDADE_MEMORIA_INTERNA * sizeof(Aluno));

  fitasBinariaModoEscrita(fitas, 1);

  // Lê e ordena os primeiros 20 registros para completar a fila de prioridade
  readInitialBlock(v1, a);
  quantidade -= QUANTIDADE_MEMORIA_INTERNA;
  int pointer = QUANTIDADE_MEMORIA_INTERNA;

  int indiceOrd = 0;
  int controlador_fitas = 0;
  while (quantidade > 0)
  {
    while (!isAllMarked(v1, a))
    { // confere se todos estão marcados para terminar um bloco
      AlunoMarcas aux = v1[0];
      // lê o próximo registro
      readNextAluno(v1[0].aluno, pointer, a);

      // criando o vetor que será levado para a fita
      ordenados[indiceOrd] = v1[0].aluno;
      indiceOrd++;

      compareNewAluno(&v1[0], aux, a);             // Marca o novo registro se necessário
      heapSort(v1, QUANTIDADE_MEMORIA_INTERNA, a); // Reordena a fila de prioridade
      quantidade--;
      pointer++;
    }
    for (int i = 0; i < QUANTIDADE_MEMORIA_INTERNA; i++)
    {
      v1[i].isMarked = 0;
    }
    indiceOrd = 0;
    // preencheFitasBlocos(ordenados, fitas, quantidade, controlador_fitas);
    novaEscrita(a);
    // Cria as fitas
    fwrite(ordenados, sizeof(Aluno), QUANTIDADE_MEMORIA_INTERNA, fitas->fita_entrada[controlador_fitas]);
    controlador_fitas++;
    if (controlador_fitas >= QUANTIDADE_FITAS)
      controlador_fitas = 0;

    heapSort(v1, QUANTIDADE_MEMORIA_INTERNA, a);
  }

  fechaFitas(fitas, 1);
}

void readInitialBlock(AlunoMarcas *v1, Analise *a)
{
  FILE *arqBin = fopen("PROVAO.bin", "rb");

  for (int i = 0; i < QUANTIDADE_MEMORIA_INTERNA; i++)
  {
    if (!fread(&v1[i].aluno, sizeof(Aluno), 1, arqBin))
    {
      novaLeitura(a);
      printf("Erro no primeiro bloco\n");
    }
    v1[i].isMarked = 0;
  }

  heapSort(v1, QUANTIDADE_MEMORIA_INTERNA, a);

  fclose(arqBin);
}

void readNextAluno(Aluno next, int pointer, Analise *a)
{
  FILE *arqBin = fopen("PROVAO.bin", "rb");
  fseek(arqBin, pointer * sizeof(Aluno), SEEK_SET);
  novaLeitura(a);
  if (!fread(&next, sizeof(Aluno), 1, arqBin))
    printf("Erro no primeiro bloco readNext\n");
  fclose(arqBin);
}

int isAllMarked(AlunoMarcas *v1, Analise *a)
{
  for (int i = 0; i < QUANTIDADE_MEMORIA_INTERNA; i++)
  {
    novaComparacao(a);
    if (v1[i].isMarked == 0)
      return 0;
  }
  return 1;
}

void compareNewAluno(AlunoMarcas *v1, AlunoMarcas oldAluno, Analise *a)
{
  novaComparacao(a);
  if (v1[0].aluno.nota <= oldAluno.aluno.nota)
  {
    v1[0].isMarked = 1;
  }
}