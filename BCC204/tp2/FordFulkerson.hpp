#ifndef FF_HPP
#define FF_HPP

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

class Vertice
{
    public:
        int id;
        bool foiRotulado;
        bool foiVisitado;

        int rVerticeAnterior;
        int rTipoDeArco = 1;
        int rCsi;

        Vertice(int id, int foiVisitado);
        ~Vertice();

        void rotular(int verticeAnterior, int tipoDeArco, int aumentoDeFluxo, int verticeT);
};

struct node
{
    int vDestino;
    int limiteSuperior;
    int fluxoAtual;
    int tipoDeArco;
    int foiVisitada;

    struct node* pProx;
};

class Grafo
{
    public:
        int qtdVertices;
        int qtdArcos;
        int csiT;

        int tamanhoCaminho;

        struct node** adjLists;
        vector<Vertice> listaVertices;

        Grafo(int qtdVertices, int qtdArcos);
        ~Grafo();

        void criaGrafo();
        void FordFulkerson();

        bool arestaDiretaUtilizavel(int verticeInicial, int w);
        bool arestaReversaUtilizavel(int verticeInicial, int w);
        bool existeAresta(int vOrigem, int vDestino);
        int qualTipoDeArco(int vOrigem, int vDestino);

        bool fluxoMenorQueLimSup(Vertice vOrigem, Vertice vDestino);
        bool fluxoMaiorQueLimInf(Vertice vOrigem, Vertice vDestino);

        void aumentarFluxo(vector<int> caminhoAteT);
        void rotularEAumentar(Vertice *vOrigem, Vertice *vDestino);
        int calcularCsi(int verticeAnterior, int verticeAtual, int tipoDeArco, int csiPai);
        void handleArestaPorTipo(int vOrigem, int vDestino);
        void handleFluxo(int vOrigem, int vDestino, int valor, int operacao);

        void buscaEmProfundidadeAdaptada(int verticeInicial, vector<int> *ordemFinal, bool *done);
        void limparVisitacoes();

        void TMPimprimir(int vi, int vo);
};

#endif