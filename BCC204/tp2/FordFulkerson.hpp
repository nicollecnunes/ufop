#ifndef DFS_HPP
#define DFS_HPP

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Vertice
{
    public:
        int id;
        int foiRotulado = 0;
        
        int rotuloVerticeAnterior;
        int rotuloTipoDeArco = 1;
        int rotuloAumentoDeFluxo;

        int csi;


        Vertice(int id, int foiRotulado);
        ~Vertice();
        int calcularCsi(int csiPai, int folga);
        void rotular(int verticeAnterior, int tipoDeArco, int aumentoDeFluxo);
};

class InfoArcos
{
    public:
        int existeArco = 0;
        int utilizavel = 1;
        int fluxo = 0;
        int limiteSuperior;

        InfoArcos();
        ~InfoArcos();

        int folgaSuperior();
        int folgaInferior();
};

class Grafo
{
    public:
        int qtdVertices;
        int qtdArcos;

        int vIncidente;
        int vAtual;

        vector<Vertice> listaVertices;
        vector<vector<InfoArcos>> listaVizinhanca;

        Grafo(int qtdVertices, int qtdArcos);
        ~Grafo();

        void preencheListas();
        void iniciaListaVizinhanca();
        bool existeVerticeRotuladoComArcoUtilizavel();
        bool existeArcoUtilizavel(int vI, int vJ);
        void FordFulkerson();
};


#endif