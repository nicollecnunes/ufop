{string} Fazendas =...;
{string} Culturas =...;

float AreaPorFazenda[Fazendas] = ...;
float AguaPorFazenda[Fazendas] = ...;

float AreaMaxPorCultura[Culturas] = ...;
float AguaPorCultura[Culturas] = ...;
float LucroPorCultura[Culturas] = ...;

dvar float+ x[Fazendas][Culturas];

maximize
  sum(c in Culturas) LucroPorCultura[c] * sum(f in Fazendas) x[f][c];


subject to
{
  
  	forall(f in Fazendas)
    	AreaCultivoPorFazenda:
     		sum(c in Culturas) x[f][c] <= AreaPorFazenda[f];
     	
     forall(f in Fazendas)
     	AguaMaxPorFazenda:
     		sum(c in Culturas) x[f][c] * AguaPorCultura[c] <= AguaPorFazenda[f];
     		
     forall(f in Fazendas)
     	Proporcoes:
     		sum(c in Culturas) x[f][c] == sum(c2 in Culturas) x[f][c2];
     	
    forall(f in Fazendas)
      forall(c in Culturas)
    	Nao_Negatividade:
    		x[f][c] >= 0;
}

