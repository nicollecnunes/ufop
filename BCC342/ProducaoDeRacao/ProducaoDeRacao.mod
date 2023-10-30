{string} Racao =...;
{string} Materiais =...;

float PrecoRacao[Racao] = ...;
float PrecoMaterial[Materiais] = ...;

int Disponibilidade[Materiais] = ...;
float Qtd[Racao][Materiais] = ...;

dvar float+ x[Racao];

maximize
  sum(r in Racao) (PrecoRacao[r] - sum(m in Materiais) (PrecoMaterial[m] * Qtd[r][m])) * x[r];


subject to
{
   forall(m in Materiais)
     Disponibilidade_Materiais:
     	sum(r in Racao) Qtd[r][m]* x[r] <= Disponibilidade[m];
     	
    forall(r in Racao)
    	Nao_Negatividade:
    		x[r] >= 0;
}

