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

struct node
{
    int vDestino;
    int peso;
    bool foiVisitada;
    struct node* pProx;
};

class Grafo
{
    public:
        int qtdVertices;
        int qtdArestas;
        int ehDirecionado;
        int verticeInicial;

        struct node** adjLists;

        vector<Vertice> listaVertices;

        Grafo(int qtdVertices, int qtdArestas, int ehDirecionado, int verticeInicial);
        ~Grafo();

        void criaGrafo();
        bool existeAresta(int vOrigem, int vDestino);
        bool arestaFoiVisitada(int vOrigem, int vDestino);
        void visitacaoAresta(int vOrigem, int vDestino, bool resultVisitacao);
        void buscaEmProfundidade(int verticeInicial, vector<int> *ordemFinal);
};

#endif