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
        int foiRotulado = 0;
        
        int rotuloVerticeAnterior;
        int rotuloTipoDeArco = 1;
        int rotuloAumentoDeFluxo;


        Vertice(int id, int foiVisitado);
        ~Vertice();
        void rotular(int verticeAnterior, int tipoDeArco, int aumentoDeFluxo);
};

class InfoArcos
{
    public:
        int existeArco = 0;
        int foiVisitado = 0;
        int limiteInferior = 0;
        int limiteSuperior;
        int tipoDeArco;

        InfoArcos(int existeArco = 0, int peso = 0, int foiVisitada = 0, int tipoDeArco = 0);
        ~InfoArcos();
};

class Grafo
{
    public:
        int qtdVertices;
        int qtdArcos;
        int verticeInicial;

        vector<Vertice> listaVertices;
        vector<vector<InfoArcos>> listaVizinhanca;

        Grafo(int qtdVertices, int qtdArcos, int verticeInicial);
        ~Grafo();

        void criaGrafo();
        void buscaEmProfundidade(int verticeInicial, vector<int> *ordemFinal);
        void iniciaListaVizinhanca();
};


#endif