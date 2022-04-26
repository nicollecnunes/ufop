#ifndef DFS_HPP
#define DFS_HPP

#include <iostream>
#include <vector>

using namespace std;

class Vertice
{
    public:
        int id;
        int foiVisitado;

        Vertice(int id, int foiVisitado);
        ~Vertice();
};

class InfoArestas
{
    public:
        int existeAresta = 0;
        int peso;
        int foiVisitada = 0;

        InfoArestas(int existeAresta = 0, int peso = 0, int foiVisitada = 0);
        ~InfoArestas();
};

class Grafo
{
    public:
        int qtdVertices;
        int qtdArestas;
        int ehDirecionado;
        int verticeInicial;

        vector<Vertice> listaVertices;
        vector<vector<InfoArestas>> listaVizinhanca;

        Grafo(int qtdVertices, int qtdArestas, int ehDirecionado, int verticeInicial);
        ~Grafo();

        void criaGrafo();
        void buscaEmProfundidade(int verticeInicial, vector<int> *ordemFinal);
        void iniciaListaVizinhanca();
};

#endif