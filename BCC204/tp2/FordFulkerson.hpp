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
        bool foiRotulado = false;
        
        int rotuloVerticeAnterior;
        int rotuloTipoDeArco = 1;
        int rotuloCsi;

        int csi;


        Vertice(int id, bool foiRotulado);
        ~Vertice();
        int calcularCsi(int csiPai, int folga);
        void rotular(int verticeAnterior, int tipoDeArco, int aumentoDeFluxo);
};

class InfoArcos
{
    public:
        bool existeArco = false;
        int tipoArco = 1;
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

        int vDestino;
        int vAtual;

        int csiT = INT_MAX;

        vector<Vertice> listaVertices;
        vector<vector<InfoArcos>> listaVizinhanca;
        deque<int> listaCaminho;

        Grafo(int qtdVertices, int qtdArcos);
        ~Grafo();

        void preencheListas();
        void iniciaListaVizinhanca();
        bool existeVerticeRotuladoComArcoUtilizavel();
        void FordFulkerson();
        bool existeArco(int v1, int v2);
        void constuirCaminho();
        void aumentarFluxo();
        void cancelarRotulos();
        void imprimirResultado();
};


#endif