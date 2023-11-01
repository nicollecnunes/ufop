{string} Material =...;
{string} Ligas =...;

float DisponibilidadeMateriaPrima[Material] = ...;
float PrecoDeMaterialParaLiga[Material][Ligas] = ...;

float PrecoPorTonelada[Ligas] = ...;


dvar float+ x[Ligas];

maximize
  sum(l in Ligas) PrecoPorTonelada[l] * x[l];


subject to
{
  
  	forall(m in Material)
    	DisponibilidadeMaterial:
     		sum(l in Ligas) x[l] * PrecoDeMaterialParaLiga[m][l]  <= DisponibilidadeMateriaPrima[m];
   
     	
    forall(l in Ligas)
    	Nao_Negatividade:
    		x[l] >= 0;
}
