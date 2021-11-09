#include "arvoreBEstrela.h"

void InicializaBEstrela(TipoApontadorEstrela *Arvore)
{
  //inicializando como NULL para evitar erros
  *Arvore = NULL;
}

int PesquisaBEstrela(TRegistro *x, TipoApontadorEstrela Ap, Desempenho *d)
{
  int i;
  TipoApontadorEstrela Pagina;
  Pagina = Ap;

  if (Ap->Pt == Interna)
  {
    i = 1;

    //Fazendo pesquisa sequencial na paginas internas
    while (i < Pagina->UU.U0.ni && x->chave > Pagina->UU.U0.ri[i - 1])
    {
      i++;
      attComparacoes1(d, 1);//incrementa o contador de comparacoes 
    }
    attComparacoes1(d, 1);
    //Chamando a funcao de Pesquisa ate encontrar uma página folha
    if ((x->chave) < (Pagina->UU.U0.ri[i - 1]))
    {
      PesquisaBEstrela(x, Pagina->UU.U0.pi[i - 1], d);
    }
    else
    {
      PesquisaBEstrela(x, Pagina->UU.U0.pi[i], d);
    }
    return 1;
  }

  i = 1;
  //faz uma pesquisa sequencial dentro da pagina folha encontrada
  while (i < Pagina->UU.U1.ne && x->chave > Pagina->UU.U1.re[i - 1].chave)
  {
    i++;
    attComparacoes1(d, 1);
  }

  attComparacoes1(d, 1);
  if (x->chave == Pagina->UU.U1.re[i - 1].chave)
  {
    //retorna 1 se achar a chave
    *x = Pagina->UU.U1.re[i - 1];
    return 1; 
  }
  else
  {
    //retorna 0 se nao achar a chave
    return 0;
  }
}

void InsereNaPaginaBEstrela(TipoApontadorEstrela Ap, int Registro, TipoApontadorEstrela ApDir, Desempenho *d)
{
  bool NaoAchouPosicao;
  int k;
  k = Ap->UU.U0.ni;

  // Essa variavel irá controlar a posição atual
  NaoAchouPosicao = (k > 0);

  attComparacoes0(d, 1);

  while (NaoAchouPosicao)
  {
    attComparacoes0(d, 1);
    if (Registro >= Ap->UU.U0.ri[k - 1])
    {
      break;
    }
    // O registro e o apontador passa ma estar uma posição a frente
    Ap->UU.U0.ri[k] = Ap->UU.U0.ri[k - 1];
    Ap->UU.U0.pi[k + 1] = Ap->UU.U0.pi[k];

    k--;

    attComparacoes0(d, 1);
    if (k < 1)
    {
      NaoAchouPosicao = false;
    }
  }

  //caso tenha achado a posicao
  Ap->UU.U0.ri[k] = Registro;
  Ap->UU.U0.pi[k + 1] = ApDir;
  Ap->UU.U0.ni++;
  return;
}

int liberarArvoreBEstrela(TipoApontadorEstrela Ap)
{
  int i = 0;

  if (Ap == NULL)
  {
    return 0;
  }

  if (Ap->Pt == Interna)
  {
    // Verificação se a página é interna
    while (i <= Ap->UU.U0.ni)
    {
      // É realizada a procura do item mais à esquerda sendo chamada a propria função recursivamente.
      liberarArvoreBEstrela(Ap->UU.U0.pi[i]);
      i++;
    }
    free(Ap);
  }
  else
  {
    free(Ap);// Libera a página externa
  }

  return 1;
}

void ImprimeBEstrela(TipoApontadorEstrela arvore)
{
  //funcao para imprimir os elementos da arvore
  int i = 0;
  if (arvore == NULL)
  {
    return;
  }

  if (arvore->Pt == Interna)
  {
    while (i <= arvore->UU.U0.ni)
    {
      ImprimeBEstrela(arvore->UU.U0.pi[i]);
      i++;
    }
  }
  else
  {
    printf("[ ");
    while (i < arvore->UU.U1.ne)
    {
      printf("%d", arvore->UU.U1.re->chave);
      i++;
    }
    printf(" ]");
  }

  return;
}

int arvExternaBEstrela(TRegistro *Reg, int Situacao, int QuantidadeRegistros, Desempenho *d)
{
  TipoApontadorEstrela arvoreBEstrela;
  InicializaBEstrela(&arvoreBEstrela);
  TRegistro *registroBEstrela = (TRegistro *)malloc(QuantidadeRegistros * sizeof(TRegistro));

  attComparacoes0(d, 1);
  if (registroBEstrela == NULL)
  {
    // Verifica a memória
    printf("Não há memória suficiente.\n");
    return -1;
  }

  FILE *arq = fopen("dados.bin", "rb");

  attComparacoes0(d, 1);
  if (arq == NULL)
  {
    // Verifica se o arquivo existe
    printf("Erro na abertura do arquivo.\n");
    return -1;
  }

  inicializarAnalise(d);
  iniciaTimer(d);

  //switch de acordo com a situuacao de ordenacao dos arquivos
  switch (Situacao)
  {
  case 1: // Caso 1 : Arquivo em ordem crescente
    while (fread(registroBEstrela, sizeof(TRegistro), QuantidadeRegistros, arq))
    {
      // Leitura dos itens
      attTransferencias0(d, 1);
      for (int i = 0; i < QuantidadeRegistros; i++)
      {
        // Percorre o arquivo inserindo os itens
        attComparacoes0(d, 1);
        insereBEstrela(&registroBEstrela[i], &arvoreBEstrela, d);
      }
    }
    break;
  case 2: // Caso 2 : Arquivo em ordem decrescente
    while (fread(registroBEstrela, sizeof(TRegistro), QuantidadeRegistros, arq))
    {
      // Leitura dos itens
      attTransferencias0(d, 1);
      for (int i = 0; i < QuantidadeRegistros; i++)
      {
        // Percorre o arquivo inserindo os itens
        attComparacoes0(d, 1);
        insereBEstrela(&registroBEstrela[i], &arvoreBEstrela, d);
      }
    }
    break;
  case 3: // Caso 3 : Arquivo aleatorio
    while (fread(registroBEstrela, sizeof(TRegistro), QuantidadeRegistros, arq))
    {
      // Leitura dos itens
      attTransferencias0(d, 1);
      for (int i = 0; i < QuantidadeRegistros; i++)
      {
        // Percorre o arquivo inserindo os itens
        attComparacoes0(d, 1);
        insereBEstrela(&registroBEstrela[i], &arvoreBEstrela, d);
      }
    }
    break;
  default:
    printf("Valor da situação é inválido.");
    break;
    return -1;
  }

  //fecha o arquivo e libera a memoria alocada anteriormente
  fclose(arq);
  free(registroBEstrela);

  paraTimer(d);
  attTempo0(d);

  //chama a funcao de pesquisa
  return PesquisaBEstrela(Reg, arvoreBEstrela, d);
}

void insereBEstrela(TRegistro* Reg, TipoApontadorEstrela* Ap, Desempenho *d)
{
  short cresceu = 0;
  short cresceuNo = 0;

  TRegistro regRetorno;
  TipoPaginaEstrela *apRetorno = NULL;
  TipoPaginaEstrela *ApTemp = NULL;
  bool nova = false;

  if (*Ap == NULL) 
  {
    // Alocando a primeira página dinamicamente.
    ApTemp = (TipoPaginaEstrela*)malloc(sizeof(TipoPaginaEstrela));
    ApTemp->Pt = Externa;
    ApTemp->UU.U1.ne = 0;

    insereNaFolha(Reg, ApTemp, d);
    *Ap = ApTemp;

    return;
  }
  else 
  {
    attComparacoes1(d, 1);
    if ((*Ap)->Pt == Externa) 
    {
      nova = true;
    }

    InsBEstrela(Reg, *Ap, &cresceu, &regRetorno, &apRetorno, &cresceuNo, d);
  }

  attComparacoes1(d, 1);
  if ((cresceuNo && nova) || cresceu)  // Verificação se é o primeiro nó que está sendo criado.
  {
    ApTemp = (TipoPaginaEstrela*) malloc(sizeof(TipoPaginaEstrela));
    ApTemp->Pt = Interna;
    ApTemp->UU.U0.ni = 1;
    ApTemp->UU.U0.ri[0] = regRetorno.chave;
    ApTemp->UU.U0.pi[0] = *Ap;
    ApTemp->UU.U0.pi[1] = apRetorno;

    *Ap = ApTemp;

    return;
  }
}

bool insereNaFolha (TRegistro* Reg, TipoApontadorEstrela NovaPagina, Desempenho *d)
{
  int quantItens = NovaPagina->UU.U1.ne;
  int k = 0;
  int i = 0;

  while (Reg->chave > NovaPagina->UU.U1.re[i].chave && i < quantItens) 
  {
    attComparacoes0(d, 1);
    i++;
  }

  attComparacoes0(d, 1);
  if(Reg->chave == NovaPagina->UU.U1.re[i].chave && quantItens != 0) 
  {
    return false;
  }

  attComparacoes0(d, 1);
  if (i < quantItens) 
  {
    k = quantItens;
    while (k >= 0 && k > i) 
    {
      attComparacoes0(d, 1);
      NovaPagina->UU.U1.re[k] = NovaPagina->UU.U1.re[k - 1];
      k--;
    }
    // Está sendo inserida na PRIMEIRA OPÇÃO
    NovaPagina->UU.U1.re[i] = *Reg;
  }
  else 
  {
    // Está sendo inserido no FINAL
    NovaPagina->UU.U1.re[i] = *Reg;
  }

  NovaPagina->UU.U1.ne++;

  return true;
}

void InsBEstrela(TRegistro* Reg, TipoApontadorEstrela Ap, short *cresceu, TRegistro *regRetorno, TipoApontadorEstrela *apRetorno, short *cresceuNo, Desempenho *d)
{
  long i = 1;
  long j;
  TipoApontadorEstrela novo = NULL;

  TRegistro aux;

  attComparacoes0(d, 1);
  if (Ap->Pt == Externa) // Verificação se chegou ao último nível
  {
    // Verificação se tem espaço na página, caso sim, é inserido na página externa.
    attComparacoes0(d, 1);
    if (Ap->UU.U1.ne < (3*ORDEM)) 
    {
      insereNaFolha (Reg, Ap, d);
      *cresceu = false; // Não precisa crescer nivel
      *cresceuNo = false; // Não precisa fazer a divisão
    }
    else 
    {
      novo = (TipoPaginaEstrela*)malloc(sizeof(TipoPaginaEstrela));

      novo->Pt = Externa;
      // Caso não, um nó será divido em dois
      novo->UU.U1.ne = 0;
      // A copia da chave sobe para o pai e será dividida
      aux = Ap->UU.U1.re[(3*ORDEM)-1];

      insereNaFolha(&aux, novo, d); // É inserido o ultimo elemento na pagina a direita

      Ap->UU.U1.ne--; // Decrementação do número de itens nessa pagina

      bool inseriu = insereNaFolha(Reg, Ap, d); // Insere o novo

      attComparacoes0(d, 1);
      if (!inseriu) 
      {
        Ap->UU.U1.ne++;
        free(novo);
        *cresceu = false;
        *cresceuNo = false;
        return;
      }

      // Passa a metade da divisão para a nova folha
      for (int i = (3*ORDEM)/2; i < (3*ORDEM); i++) 
      {
        insereNaFolha(&(Ap->UU.U1.re[i]), novo, d);
        Ap->UU.U1.ne--;
      }

      regRetorno->chave = novo->UU.U1.re[0].chave; // Vai salvar a chave do pai
      *apRetorno = novo; // vai salvar o novo nó a direita

      // Depois de inserir na árvore o novo registro obtido,
      // a chave que tem que subir para o nó pai
      // precisa ser inserida na arvore
      Reg->chave = novo->UU.U1.re[0].chave;
 
      *cresceuNo = true; // Dividindo o no folha

      return;
    }
  }
  else // Verificação se a página é interna
  {
    attComparacoes0(d, 1);
    while (i < Ap->UU.U0.ni && Reg->chave > Ap->UU.U0.ri[i-1]) 
    {
      i++;
    }

    attComparacoes0(d, 1);
    if (Reg->chave == Ap->UU.U0.ri[i - 1])
    {
      // Verifica dentro do nó folha se ele ainda existe 
      *cresceu = false;
      *cresceuNo =false;
      return;
    }

    attComparacoes0(d, 1);
    if (Reg->chave < Ap->UU.U0.ri[i - 1]) 
    {
      i--;
    }

    attComparacoes0(d, 1);
    // Proura onde a chave deverá entrar, considerando se a proxima pagina for interna.
    if(!*cresceuNo) 
    {
      InsBEstrela(Reg, Ap->UU.U0.pi[i], cresceu, regRetorno, apRetorno, cresceuNo, d);

      attComparacoes0(d, 1);

      if (!*cresceu && !*cresceuNo) 
      {
        return; // Verifica se a pagina tem espaço
      }

      attComparacoes0(d, 1);
      if (Ap->UU.U0.ni < 2*ORDEM) 
      {
        InsereNaPaginaBEstrela(Ap, regRetorno->chave, *apRetorno, d);
        *cresceu = false;
        *cresceuNo =false;
        return;
      }

      TipoApontadorEstrela Temporaria;

      // Alocando dinamicante uma nova pagina
      Temporaria = (TipoApontadorEstrela) malloc (sizeof(TipoPaginaEstrela));

      // A página esta cheia e deverá ser dividida
      Temporaria->Pt = Interna;
      Temporaria->UU.U0.ni = 0;
      Temporaria->UU.U0.pi[0] = NULL;

      attComparacoes0(d, 1);
      if (i < ((2*ORDEM)/2) + 1) 
      {
        InsereNaPaginaBEstrela(Temporaria, Ap->UU.U0.ri[(2*ORDEM) - 1], Ap->UU.U0.pi[2*ORDEM], d);
        Ap->UU.U0.ni--;
        InsereNaPaginaBEstrela(Ap, regRetorno->chave, *apRetorno, d);
      }
      else 
      {
        InsereNaPaginaBEstrela(Temporaria,regRetorno->chave, *apRetorno, d);
      }

      for (j = ((2*ORDEM)/2) + 2; j <= 2*ORDEM; j++) 
      {
        attComparacoes0(d, 1);
        InsereNaPaginaBEstrela(Temporaria, Ap->UU.U0.ri[j-1], Ap->UU.U0.pi[j], d);
      }

      Ap->UU.U0.ni = (2*ORDEM)/2;
      Temporaria->UU.U0.pi[0] = Ap->UU.U0.pi[((2*ORDEM)/2) + 1];
      regRetorno->chave= Ap->UU.U0.ri[(2*ORDEM)/2];

      *apRetorno = Temporaria;
      *cresceu = true;
      *cresceuNo = false;
      return;
    }
  }
}

// Xará e Mayan 02/11 --------------------------------------------------------------------------------------