#ifndef DFS_HPP
#define DFS_HPP

#include <iostream>
#include <vector>

using namespace std;

class Aresta
{
    public:
        int id;
        int origem;
        int destino;
        double peso;
        int foiVisitada;

        Aresta(int id, int origem, int destino, double peso, int foiVisitada);
        ~Aresta();
};

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
        int verticeInicial;
        int qtdVertices;
        int qtdArestas;
        int indice;
        int ehDirecionado;

        vector<Aresta> listaArestas;
        vector<Vertice> listaVertices;
        vector<vector<InfoArestas>> listaVizinhanca;

        Grafo();
        ~Grafo();

        void criaGrafo();
        void buscaEmProfundidade(int verticeInicial, vector<int> *ordemDeVisitacao);
        void iniciaListaVizinhanca();
        bool existeVizinhoNaoVisitado(int vOrigem, int vDestino);
};

#endif