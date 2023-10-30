{string} Cultura =...;

int MaxArmazenamento = ...;
int MaxArea = ...;

float MinPorCultura[Cultura] = ...;
float ProdutividadePorCultura[Cultura] = ...;
float LucroPorCultura[Cultura] = ...;

dvar float+ x[Cultura];

maximize
  sum(c in Cultura) LucroPorCultura[c] * ProdutividadePorCultura[c];


subject to
{
     Disponibilidade_Armazenamento:
     	sum(c in Cultura) x[c] * ProdutividadePorCultura[c] <= MaxArmazenamento;
     	
     Disponibilidade_Area:
     	sum(c in Cultura) x[c] <= MaxArea;
     	
    forall(c in Cultura)
    	Nao_Negatividade:
    		x[c] >= 0;
    		
    forall(c in Cultura)
    	Demanda_Sitio:
    		x[c] >= MinPorCultura[c];
}

