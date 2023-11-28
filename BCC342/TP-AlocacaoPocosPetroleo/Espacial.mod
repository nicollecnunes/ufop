{string} ANMs =...;
{string} Pocos =...;
{string} Portos =...;

int DataDisponibilidadeANMS[ANMs] = ...;
int DataNecessidadePocos[Pocos] = ...;
int BIN_PodeAlocar[ANMs][Pocos] = ...;
int DistanciaDosPortos[Pocos][Portos] = ...;
string Origem[ANMs] = ...;

int rf[ANMs][Pocos] = ...;

dvar int custos[ANMs][Pocos];
dvar boolean x[ANMs][Pocos];

minimize
  sum(i in ANMs) sum(j in Pocos) (DistanciaDosPortos[j][Origem[i]] * (DataNecessidadePocos[j] - DataDisponibilidadeANMS[i]) * x[i][j]);


subject to
{
  /*AtribuindoRF:
  	forall(i in ANMs, j in Pocos)
    		if (DataNecessidadePocos[j] - DataDisponibilidadeANMS[i] < 0 || BIN_PodeAlocar[i][j] == 0) {
      			rf[i][j] == 0;
    		}
		    else {
      			rf[i][j] == 1;
    		}*/
   
  	UmaArvorePorPoco:
  		forall(j in Pocos)
  			sum(i in ANMs) x[i][j] == 1;
  			
  	UmPocoPorArvore:
  		forall(i in ANMs)
  			sum(j in Pocos) x[i][j] == 1;
  			
  	PodeAlocar:
  		forall(i in ANMs)
  		  forall(j in Pocos)
  		    x[i][j] <= rf[i][j];
  		    
  	MatrizDeCustos:
  	forall(i in ANMs, j in Pocos)
    	custos[i][j] == (DistanciaDosPortos[j][Origem[i]] * (DataNecessidadePocos[j] - DataDisponibilidadeANMS[i]));
}
