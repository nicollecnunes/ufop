{string} Petroleos =...;
{string} Gasolinas =...;

float BarrisPorDia[Petroleos] = ...;
float CustoDoBarril[Petroleos] = ...;

float MinimosDePetroleoPorGasolina[Gasolinas][Petroleos] = ...;
float MaximosDePetroleoPorGasolina[Gasolinas][Petroleos] = ...;
float PrecoPorBarril[Gasolinas] = ...;

dvar float+ x[Gasolinas][Petroleos];

maximize
  sum(g in Gasolinas) PrecoPorBarril[g] * sum(p in Petroleos) x[g][p] - sum(p2 in Petroleos) CustoDoBarril[p2] * sum(g2 in Gasolinas) x[g2][p2];


subject to
{
  
  	forall(p in Petroleos)
    	QtdPetroleo:
     		sum(g in Gasolinas) x[g][p]  <= BarrisPorDia[p];
     		
     forall(g in Gasolinas)
       forall(p in Petroleos)
    	MaximosMisturas:
     		x[g][p]  <= MaximosDePetroleoPorGasolina[g][p];
     		
     forall(g in Gasolinas)
       forall(p in Petroleos)
         MinimosMisturas:
     		x[g][p]  <= MinimosDePetroleoPorGasolina[g][p];
   
     	
    forall(g in Gasolinas)
      forall(p in Petroleos)
    	Nao_Negatividade:
    		x[g][p] >= 0;
}
