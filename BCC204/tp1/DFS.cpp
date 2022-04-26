#include "DFS.hpp"

#define SIM 1
#define NAO 0

using namespace std;

Aresta:: Aresta(int _id, int _origem, int _destino, double _peso, int _foiVisitada)
{
    id = _id;
    origem = _origem;
    destino = _destino;
    peso = _peso;
    foiVisitada = NAO;
}
Aresta:: ~Aresta(){}

Vertice:: Vertice(int _id, int _foiVisitado)
{
    id = _id;
    foiVisitado = _foiVisitado;
}
Vertice:: ~Vertice(){}

InfoArestas::InfoArestas(int existeAresta, int peso, int foiVisitada):existeAresta(existeAresta), peso(peso), foiVisitada(foiVisitada){}
InfoArestas:: ~InfoArestas(){}

Grafo:: Grafo(){}
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
    int _qtdVertices, _qtdArestas, _ehDirecionado, _indiceVertice;
    cin >> _qtdVertices >> _qtdArestas >> _ehDirecionado >> _indiceVertice;

    //cout << "Grafo de " << _qtdVertices << " vertices e " << _qtdArestas << " arestas" << endl;
    
    qtdVertices = _qtdVertices;
    qtdArestas = _qtdArestas;
    ehDirecionado = _ehDirecionado;
    verticeInicial = _indiceVertice - 1;

    int _origem, _destino;
    double _peso;

    iniciaListaVizinhanca();

    // leitura de arestas
    //cout << "Iniciando a leitura de " << qtdArestas << " arestas" << endl;
    for (int i = 0; i < qtdArestas; i++)
    {
        //cout << "Digite a origem, destino e peso da aresta numero " << i << endl;
        cin >> _origem >> _destino >> _peso;

        _origem = _origem - 1;
        _destino = _destino - 1;

        if (ehDirecionado)
        {
            //cout << "GD: existe uma aresta entre " << _origem << " e " << _destino << " de peso " << _peso << endl;
            listaVizinhanca[_origem][_destino].existeAresta = SIM;
            listaVizinhanca[_origem][_destino].peso = _peso;
        }
        else
        {
            //cout << "GND: existe uma aresta entre " << _origem << " e " << _destino << " de peso " << _peso << endl;
            listaVizinhanca[_origem][_destino].existeAresta = SIM;
            listaVizinhanca[_origem][_destino].peso = _peso;

            //cout << "e vice- versa" << endl;
            listaVizinhanca[_destino][_origem].existeAresta = SIM;
            listaVizinhanca[_destino][_origem].peso = _peso;
        }

        //cout << "Adicionando aresta na lista de arestas [id, origem, destino, peso] = " << i << _origem << _destino << _peso << endl;
        Aresta arestaAux = Aresta(i, _origem, _destino, _peso, NAO);
        listaArestas.push_back(arestaAux);

        //cout << "Final, i valendo" << i << endl;
    }

    //cout << "Inicializando lista de " << qtdVertices << " vertices." << endl;
    for (int i = 0; i < qtdVertices; i++)
    {
        Vertice verticeAux = Vertice(i, NAO);
        listaVertices.push_back(verticeAux);
    }
}

void Grafo:: buscaEmProfundidade(int verticeInicial, vector<int> *ordemDeVisitacao)
{  
    //cout << "Visitando o vertice de id " << verticeInicial << endl;
    listaVertices[verticeInicial].foiVisitado = SIM;
    ordemDeVisitacao->push_back(listaVertices[verticeInicial].id);

    for (int i = 0; i < qtdVertices; i++)
    {
        if (existeVizinhoNaoVisitado(verticeInicial, i))
        {
            if (!listaVertices[i].foiVisitado)
            {
                //cout << "O vertice " << listaVertices[i].id << " nao foi visitado" << endl;

                //cout << "Visitando a aresta " << verticeInicial << "-" << i << endl;
                listaVizinhanca[verticeInicial][i].foiVisitada = SIM;

                //cout << "Chamada recursiva" << endl;
                buscaEmProfundidade(i, ordemDeVisitacao);
            }
            else
            {
                if (!listaVizinhanca[verticeInicial][i].foiVisitada)
                {
                    //cout << "Visitando a aresta " << verticeInicial << "-" << i << endl;
                    listaVizinhanca[verticeInicial][i].foiVisitada = SIM;
                }
            }
        }
    }
}

    bool Grafo:: existeVizinhoNaoVisitado(int vOrigem, int vDestino)
    {
        if (ehDirecionado && listaVizinhanca[vOrigem][vDestino].existeAresta && !listaVizinhanca[vOrigem][vDestino].foiVisitada)
        {
            //cout << "GD: Existe uma aresta entre os vértices " << vOrigem << " e " << vDestino << " e ela não foi visitada ainda" << endl;
            return true;        
        }
        else if (!ehDirecionado && (listaVizinhanca[vOrigem][vDestino].existeAresta || listaVizinhanca[vDestino][vOrigem].existeAresta))
        {
            //cout << "GND: Existe uma aresta entre os vértices " << vOrigem << " e " << vDestino << " e vice-versa ela não foi visitada ainda" << endl;
            return true;
        }
        else if (!ehDirecionado && (listaVizinhanca[vDestino][vOrigem].existeAresta || !listaVizinhanca[vDestino][vOrigem].foiVisitada))
        {
            //cout << "GND: Existe uma aresta entre os vértices " << vDestino << " e " << vOrigem << " e vice-versa ela não foi visitada ainda" << endl;
            return true;
        }
        else
        {
            //cout << "Não existe nova aresta" << endl;
            return false;
        }
    }
