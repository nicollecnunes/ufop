{string} Pilhas =...;
{string} Parametros =...;

int QtdRequeridaMistura = ...;

float Porcentagem[Pilhas][Parametros] = ...;

float MaxDoParametro[Parametros] = ...;
float MinDoParametro[Parametros] = ...;
float RecomendavelDoParametro[Parametros] = ...;
float wpm[Parametros] = ...;
float wnm[Parametros] = ...;
float wpe[Parametros] = ...;
float wne[Parametros] = ...;

float MaxMinerioNaPilha[Pilhas] = ...;
float CustoPorToneladaNaPilha[Pilhas] = ...;



dvar float+ x[Pilhas];
dvar float+ dnm[Parametros];
dvar float+ dpm[Parametros];
dvar float+ dne[Parametros];
dvar float+ dpe[Parametros];

minimize
  sum(p in Parametros) (wpe[p]*dpe[p] + wne[p]*dne[p]) + sum(p in Parametros) (wpm[p]*dpm[p] + wnm[p]*dnm[p]);


subject to
{
  	Qualidade:
     	forall(pa in Parametros)
       		sum(pi in Pilhas) x[pi]* (Porcentagem[pi][pa] - RecomendavelDoParametro[pa]) + dnm[pa] - dpm[pa] <= 0;
       		
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
