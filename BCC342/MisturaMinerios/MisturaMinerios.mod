{string} Pilhas =...;
{string} Parametros =...;

int QtdRequeridaMistura = ...;

float Porcentagem[Pilhas][Parametros] = ...;

float MaxDoParametro[Parametros] = ...;
float MinDoParametro[Parametros] = ...;

float MaxMinerioNaPilha[Pilhas] = ...;
float CustoPorToneladaNaPilha[Pilhas] = ...;



dvar float+ x[Pilhas];

minimize
  sum(p in Pilhas) CustoPorToneladaNaPilha[p]*x[p];


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
