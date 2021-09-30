
int ContaLinhas(char *arquivo)
{
  FILE *arq = fopen(arquivo, "r");

  int linhas = 0;
  char aux[60];

  while (fgets(aux, 60, arq) != NULL)
    linhas += 1;

  fclose(arq);
  return linhas;
}

void LeAlunosTxt(TADAluno **alunos)
{
  int matricula;
  char nome[30];
  float notas[3];
  int faltas;

  FILE *arq = fopen("alunos.txt", "r");

  for (int i = 0;
       fscanf(arq, "%d %[A-Z a-z] %f %f %f %d",
              &matricula, nome, &notas[0], &notas[1], &notas[2], &faltas) != EOF;
       i++)
  {
      alunos[i]->matricula = matricula;
      alunos[i]->nome = nome;
      alunos[i]->notas[0] = notas[0];
      alunos[i]->notas[1] = notas[1];
      alunos[i]->notas[2] = notas[2];
      alunos[i]->faltas = faltas;
  }
  fclose(arq);
}

void CriaConceitoTxt(TADAluno **alunos, int n)
{

  FILE *arq = fopen("conceitos.txt", "w");
  int matricula;
  char nome[30];
  char conceito;

  for (int i = 0; i < n; i++)
  {
    matricula = (alunos[i]->matricula);
    strcpy(nome, (alunos[i]->nome));
    conceito = CalculaConceito(alunos[i]);

    fprintf(arq, "%d %s  %c\n", matricula, nome, conceito);
  }

  fclose(arq);
}

char CalculaConceito(TADAluno *aluno)
{
  if (aluno->faltas > 18)
    return 'F';
  else
  {
    float media = (aluno->notas[0] + aluno->notas[1] + aluno->notas[2]) / 3;
    if (media < 6)
      return 'R';
    else if (media < 7.5)
      return 'C';
    else if (media < 9)
      return 'B';   
  }
  return 'A';
}
