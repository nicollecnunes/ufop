#include "FordFulkerson.hpp"

#define DIRETO 1
#define REVERSO -1

#define SIM 1
#define NAO 0

Vertice:: Vertice(int i, int fR):id(i), foiRotulado(fR){}
Vertice:: ~Vertice(){}

InfoArcos::InfoArcos(){}
InfoArcos:: ~InfoArcos(){}

Grafo:: Grafo(int qV, int qA):qtdVertices(qV), qtdArcos(qA){}
Grafo:: ~Grafo(){}

int InfoArcos::folgaSuperior()
{
    return limiteSuperior - fluxo;
}

int InfoArcos::folgaInferior()
{
    return fluxo;
}


void Vertice:: rotular(int verticeAnterior, int tipoDeArco, int aumentoDeFluxo)
{
    
    cout << "Vertice "<< this->id << " rotulado com "<< verticeAnterior << ", " << tipoDeArco << ", " << aumentoDeFluxo << endl;
    this->rotuloVerticeAnterior = verticeAnterior;
    this->rotuloTipoDeArco = tipoDeArco;
    this->rotuloAumentoDeFluxo = aumentoDeFluxo;

    this->foiRotulado = SIM;
}

int Vertice:: calcularCsi(int csiPai, int folga)
{
    return min(csiPai, folga);
}

void Grafo:: iniciaListaVizinhanca()
{
    for (int i = 0; i < qtdVertices; i++)
    {
        vector<InfoArcos> listaAux;
        listaVizinhanca.push_back(listaAux);

        for (int j = 0; j < qtdVertices; j++)
        {
            listaVizinhanca[i].push_back(InfoArcos());
        }
    }
}

void Grafo:: preencheListas()
{
    int vOrigem, vDestino, limiteSuperior;
    iniciaListaVizinhanca();

    //cout << "Iniciando a leitura de " << qtdArcos << " arcos" << endl;
    for (int i = 0; i < qtdArcos; i++)
    {
        //cout << "Digite a origem, destino e limite superior da arco numero " << i << endl;
        cin >> vOrigem >> vDestino >> limiteSuperior;

        //cout << "Existe um arco entre " << vOrigem - 1 << " e " << vDestino - 1 << " de limite " << limiteSuperior << endl;
        listaVizinhanca[vOrigem - 1][vDestino - 1].existeArco = SIM;
        listaVizinhanca[vOrigem - 1][vDestino - 1].limiteSuperior = limiteSuperior;
    }

    //cout << "Inicializando lista de " << qtdVertices << " vertices." << endl;
    for (int i = 0; i < qtdVertices; i++)
    {
        Vertice verticeAux = Vertice(i, NAO);
        listaVertices.push_back(verticeAux);
    }
}

bool Grafo:: existeVerticeRotuladoComArcoUtilizavel()
{
    for (int i = 0; i < qtdVertices; i++)
    {
        if(listaVertices[i].foiRotulado == SIM)
        {
            for (int j = 0; j < qtdVertices; j++)
            {
                if (i != j && (listaVertices[j].foiRotulado == NAO))
                {
                    if (listaVizinhanca[i][j].existeArco == SIM ||
                        listaVizinhanca[j][i].existeArco == SIM);
                    {
                        vIncidente = j;
                        vAtual = i;
                        cout << "arco utilizavel: V" << i << " para V" << j << endl;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Grafo:: FordFulkerson()
{
    int csiPai, folga, csiVIncidente;
    listaVertices[0].rotular(INT_MIN, 0, INT_MAX); 

    while(existeVerticeRotuladoComArcoUtilizavel()){
        cout << "fluxo VA VI: " << listaVizinhanca[vAtual][vIncidente].fluxo << endl;
        cout << "fluxo VI VA: " << listaVizinhanca[vIncidente][vAtual].fluxo << endl;
        if(listaVizinhanca[vAtual][vIncidente].existeArco == SIM
            && listaVizinhanca[vAtual][vIncidente].fluxo < listaVizinhanca[vAtual][vIncidente].limiteSuperior)
        {
            cout << "existe um arco direto de" << vAtual << " para " << vIncidente << endl;
            csiPai = listaVertices[vAtual].csi;
            folga = listaVizinhanca[vAtual][vIncidente].limiteSuperior - listaVizinhanca[vAtual][vIncidente].fluxo;

            csiVIncidente = listaVertices[vIncidente].calcularCsi(csiPai, folga);

            listaVertices[vIncidente].rotular(vAtual, DIRETO, csiVIncidente);
        }
        else
        {
            if (listaVizinhanca[vIncidente][vAtual].existeArco == SIM
                && listaVizinhanca[vIncidente][vAtual].fluxo > 0)
            {
                cout << "existe um arco de" << vIncidente << " para " << vAtual << endl;
                csiPai = listaVertices[vAtual].csi;
                folga = listaVizinhanca[vAtual][vIncidente].fluxo;

                csiVIncidente = listaVertices[vIncidente].calcularCsi(csiPai, folga);

                listaVertices[vIncidente].rotular(vAtual, REVERSO, csiVIncidente);
            }
        }
        cout << "continuar com se T rotulado" << endl;
    }

}