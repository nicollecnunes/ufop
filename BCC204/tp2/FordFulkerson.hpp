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

        void TEMPimprimirCaminho(vector<int> caminhoAteT);

        void criaGrafo();
        void FordFulkerson();

        bool DFSArestaFoiVisitada(int vOrigem, int vDestino);
        void DFSVisitacaoAresta(int vOrigem, int vDestino, bool resultVisitacao);
        bool DFSExisteAresta(int vOrigem, int vDestino);
        void DFSLimparVisitacoes();

        void FFRotularVerticesEAtualizarAumento(Vertice *vOrigem, Vertice *vDestino);
        bool FFFluxoMenorQueLimSup(Vertice vOrigem, Vertice vDestino);
        bool FFFluxoMaiorQueLimInf(Vertice vOrigem, Vertice vDestino);
        void FFCaminharEAumentarFluxo(vector<int> caminhoAteT);
        int FFCalcularCsi(int verticeAnterior, int verticeAtual, int tipoDeArco, int csiPai);
        void FFHandleFluxoAresta(int vOrigem, int vDestino);
        int FFQualTipoDeArco(int vOrigem, int vDestino);
        void FFOperacaoNoFluxo(int vOrigem, int vDestino, int valor, int operacao);

        void buscaEmProfundidadeAdaptada(int verticeInicial, vector<int> *ordemFinal, bool *done);
};

#endif