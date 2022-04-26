#include "DFS.hpp"

#define SIM 1
#define NAO 0

using namespace std;

Vertice:: Vertice(int i, int fV):id(i), foiVisitado(fV){}
Vertice:: ~Vertice(){}

InfoArestas::InfoArestas(int eA, int p, int fV):existeAresta(eA), peso(p), foiVisitada(fV){}
InfoArestas:: ~InfoArestas(){}

Grafo:: Grafo(int qV, int qA, int eD, int iV):qtdVertices(qV), qtdArestas(qA), ehDirecionado(eD), verticeInicial(iV - 1){}
Grafo:: ~Grafo(){}

void Grafo:: iniciaListaVizinhanca()
{
    for (int i = 0; i < qtdVertices; i++)
    {
        vector<InfoArestas> listaAux;
        listaVizinhanca.push_back(listaAux);

        for (int j = 0; j < qtdVertices; j++)
        {
            listaVizinhanca[i].push_back(InfoArestas());
        }
    }
}

void Grafo:: criaGrafo()
{
    int vOrigem, vDestino;
    double pesoAresta;

    iniciaListaVizinhanca();

    //cout << "Iniciando a leitura de " << qtdArestas << " arestas" << endl;
    for (int i = 0; i < qtdArestas; i++)
    {
        //cout << "Digite a origem, destino e peso da aresta numero " << i << endl;
        cin >> vOrigem >> vDestino >> pesoAresta;

        vOrigem = vOrigem - 1;
        vDestino = vDestino - 1;

        if (ehDirecionado)
        {
            //cout << "GD: existe uma aresta entre " << vOrigem << " e " << vDestino << " de peso " << pesoAresta << endl;
            listaVizinhanca[vOrigem][vDestino].existeAresta = SIM;
            listaVizinhanca[vOrigem][vDestino].peso = pesoAresta;
        }
        else
        {
            //cout << "GND: existe uma aresta entre " << vOrigem << " e " << vDestino << " de peso " << pesoAresta << endl;
            listaVizinhanca[vOrigem][vDestino].existeAresta = SIM;
            listaVizinhanca[vOrigem][vDestino].peso = pesoAresta;

            //cout << "e vice- versa" << endl;
            listaVizinhanca[vDestino][vOrigem].existeAresta = SIM;
            listaVizinhanca[vDestino][vOrigem].peso = pesoAresta;
        }
    }

    //cout << "Inicializando lista de " << qtdVertices << " vertices." << endl;
    for (int i = 0; i < qtdVertices; i++)
    {
        Vertice verticeAux = Vertice(i, NAO);
        listaVertices.push_back(verticeAux);
    }
}

void Grafo:: buscaEmProfundidade(int verticeInicial, vector<int> *ordemFinal)
{  
    //cout << "Visitando o vertice de id " << verticeInicial << endl;
    listaVertices[verticeInicial].foiVisitado = SIM;
    ordemFinal->push_back(listaVertices[verticeInicial].id);

    for (int i = 0; i < qtdVertices; i++)
    {
        if (listaVizinhanca[verticeInicial][i].existeAresta)
        {
            if (!listaVertices[i].foiVisitado)
            {
                //cout << "O vertice " << i << " nao foi visitado ainda. visitando a aresta " << verticeInicial << "-" << i << endl;
                listaVizinhanca[verticeInicial][i].foiVisitada = SIM;
                // cout << "Chamada recusriva" << endl;
                buscaEmProfundidade(i, ordemFinal);
            }
            else
            {
                if (!listaVizinhanca[verticeInicial][i].foiVisitada)
                {
                    listaVizinhanca[verticeInicial][i].foiVisitada = SIM;
                }
            }
        }
    }
}
