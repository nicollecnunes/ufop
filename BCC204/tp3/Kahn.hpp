#ifndef KAHN_HPP
#define KAHN_HPP

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Vertice
{
    public:
        int id;
        int numArcosEntrada = 0;
    
        Vertice(int id, int numArcosEntrada);
        ~Vertice();
};

class InfoArcos
{
    public:
        bool existeArco = false;

        InfoArcos();
        ~InfoArcos();
};

class Grafo
{
    public:
        int qtdVertices;
        int qtdArcos;

        vector<Vertice> listaVertices;
        vector<vector<InfoArcos>> listaVizinhanca;

        vector<int> listaS;
        vector<int> listaL;

        Grafo(int qtdVertices, int qtdArcos);
        ~Grafo();

        void preencheListas();
        void gerarListaVerticesSemEntrada();
        void iniciaListaVizinhanca();
        void kahn();
        void removerAtualizarArcos(int vOrigem);
        void imprimeL();
};

#endif