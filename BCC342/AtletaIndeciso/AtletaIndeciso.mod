{string} Esportes =...;

int OrcamentoMensal = ...;
int TempoMensal = ...;
int CaloriasMensal = ...;

float PrecoEsportes2h[Esportes] = ...;
float GastoCaloricoEsportes[Esportes] = ...;

dvar float+ x[Esportes];

maximize
  sum(e in Esportes) x[e];


subject to
{
     Dinheiro:
     	sum(e in Esportes) x[e] * PrecoEsportes2h[e] <= OrcamentoMensal;
     	
     Calorias:
     	sum(e in Esportes) x[e] * GastoCaloricoEsportes[e] <= CaloriasMensal;
      
    Tempo:
     	sum(e in Esportes) x[e] * 2 <= TempoMensal;
     	
    forall(e in Esportes)
    	Nao_Negatividade:
    		x[e] >= 0;
}

