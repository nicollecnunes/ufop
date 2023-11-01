{string} Panelas =...;
{string} Matrizes =...;

float DiametroPanelas[Panelas] = ...;
float MinimoPanelasPorTipo[Panelas] = ...;
float CustoPorMatriz[Matrizes] = ...;
float QtdDePanelaPorMatriz[Matrizes][Panelas] = ...;


dvar float+ x[Matrizes];

minimize
  sum(m in Matrizes) x[m]*CustoPorMatriz[m];


subject to
{
  
  	forall(p in Panelas)
     MinimosDePanelas:
     	sum(m in Matrizes) x[m] * QtdDePanelaPorMatriz[m][p] <= MinimoPanelasPorTipo[p];
     	
    forall(m in Matrizes)
    	Nao_Negatividade:
    		x[m] >= 0;
}

