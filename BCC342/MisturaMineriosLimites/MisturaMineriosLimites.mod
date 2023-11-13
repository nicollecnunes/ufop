{string} Pilhas =...;
{string} Parametros =...;

int QtdRequeridaMistura = ...;

float Porcentagem[Pilhas][Parametros] = ...;

float MaxDoParametro[Parametros] = ...;
float MinDoParametro[Parametros] = ...;
float PesoDesvioNegativo[Parametros] = ...;
float PesoDesvioPositivo[Parametros] = ...;

float MaxMinerioNaPilha[Pilhas] = ...;
float CustoPorToneladaNaPilha[Pilhas] = ...;



dvar float+ x[Pilhas];
dvar float+ dne[Parametros];
dvar float+ dpe[Parametros];

minimize
  sum(p in Parametros) PesoDesvioPositivo[p]*dpe[p] + sum(p2 in Parametros) PesoDesvioNegativo[p2]*dne[p2];


subject to
{
     MaximoPermitido:
     	forall(pa in Parametros)
       		sum(pi in Pilhas) x[pi]* (Porcentagem[pi][pa] - MaxDoParametro[pa]) <= 0;
     	
     MinimoPermitido:
     	forall(pa in Parametros)
       		sum(pi in Pilhas) x[pi]* (Porcentagem[pi][pa] - MinDoParametro[pa]) >= 0;
     	
    forall(pi in Pilhas)
    	QuantidadeNaPilha:
    		x[pi] <= MaxMinerioNaPilha[pi];
    		
    Peso_Total:
    	sum(pi in Pilhas) x[pi] == QtdRequeridaMistura;
    	
    Nao_Negatividade:
    	forall(pi in Pilhas)
    		x[pi] >= 0;
}
