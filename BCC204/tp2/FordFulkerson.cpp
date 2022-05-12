#include "FordFulkerson.hpp"

#define DIRETO 1
#define REVERSO 0

#define SIM 1
#define NAO 0

void Vertice:: rotular(int verticeAnterior, int tipoDeArco, int aumentoDeFluxo)
{
    this->rotuloVerticeAnterior = verticeAnterior;
    this->rotuloTipoDeArco = tipoDeArco;
    this->rotuloAumentoDeFluxo = aumentoDeFluxo;

    this->foiRotulado = SIM;
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

void Grafo:: criaGrafo()
{
    iniciaListaVizinhanca();

    //cout << "Iniciando a leitura de " << qtdArcos << " arcos" << endl;
    for (int i = 0; i < qtdArcos; i++)
    {
        //cout << "Digite a origem, destino e peso da arco numero " << i << endl;
        cin >> vOrigem >> vDestino >> pesoArco;

        vOrigem = vOrigem - 1;
        vDestino = vDestino - 1;

        if (ehDirecionado)
        {
            //cout << "GD: existe uma arco entre " << vOrigem << " e " << vDestino << " de peso " << pesoArco << endl;
            listaVizinhanca[vOrigem][vDestino].existeArco = SIM;
            listaVizinhanca[vOrigem][vDestino].peso = pesoArco;
        }
        else
        {
            //cout << "GND: existe uma arco entre " << vOrigem << " e " << vDestino << " de peso " << pesoArco << endl;
            listaVizinhanca[vOrigem][vDestino].existeArco = SIM;
            listaVizinhanca[vOrigem][vDestino].peso = pesoArco;

            //cout << "e vice- versa" << endl;
            listaVizinhanca[vDestino][vOrigem].existeArco = SIM;
            listaVizinhanca[vDestino][vOrigem].peso = pesoArco;
        }
    }

    //cout << "Inicializando lista de " << qtdVertices << " vertices." << endl;
    for (int i = 0; i < qtdVertices; i++)
    {
        Vertice verticeAux = Vertice(i, NAO);
        listaVertices.push_back(verticeAux);
    }
}