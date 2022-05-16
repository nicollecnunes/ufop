#include "Kahn.hpp"

Vertice:: Vertice(int i, int nE):id(i), numArcosEntrada(nE){}
Vertice:: ~Vertice(){}

InfoArcos::InfoArcos(){}
InfoArcos:: ~InfoArcos(){}

Grafo:: Grafo(int qV, int qA):qtdVertices(qV), qtdArcos(qA){}
Grafo:: ~Grafo(){}

void Grafo:: iniciaListaVizinhanca()
{
    for (int i = 0; i < qtdVertices; i++)
    {
        vector<InfoArcos> listaAux;
        listaVizinhanca.push_back(listaAux);

        for (int j = 0; j < qtdVertices; j++)
        {
            listaVizinhanca[i].push_back(InfoArcos());
        }
    }
}

void Grafo:: preencheListas()
{
    int vOrigem, vDestino;
    iniciaListaVizinhanca();

    for (int i = 0; i < qtdVertices; i++)
    {
        Vertice verticeAux = Vertice(i, 0);
        listaVertices.push_back(verticeAux);
    }

    for (int i = 0; i < qtdArcos; i++)
    {
        cin >> vOrigem >> vDestino;

        vOrigem = vOrigem - 1;
        vDestino = vDestino - 1;

        listaVizinhanca[vOrigem][vDestino].existeArco = true;
        listaVertices[vDestino].numArcosEntrada = listaVertices[vDestino].numArcosEntrada + 1;
        //cout << "O vertice " << vDestino+1 << " tem " << listaVertices[vDestino].numArcosEntrada << " arcos de entrada" << endl;
    }   
}

void Grafo:: gerarListaVerticesSemEntrada()
{
    for (int i = 0; i < qtdVertices; i++)
    {
        if (listaVertices[i].numArcosEntrada == 0)
        {
            listaS.push_back(i);
        }
    }
}

void Grafo:: removerAtualizarArcos(int vOrigem)
{
    for (int i = 0; i < qtdVertices; i ++)
    {
        if (listaVizinhanca[vOrigem][i].existeArco)
        {
            listaVertices[i].numArcosEntrada = listaVertices[i].numArcosEntrada - 1;
            
            listaVizinhanca[vOrigem][i].existeArco = false;
            qtdArcos = qtdArcos - 1;

            if (listaVertices[i].numArcosEntrada == 0)
            {
                //cout << i+1 << " tem 0 entradas agora. adicionando a S." << endl;
                listaS.push_back(i);
            }
        }
    }
}

void Grafo:: imprimeL()
{
    int indexFinalL = listaL.size() - 1;
    cout << "L = {";
    for (int i = 0; i < indexFinalL; i ++)
    {
        cout << listaL[i] + 1<< ", ";
    }
    cout << listaL[indexFinalL] + 1;
    cout << "}";
}

void Grafo:: kahn()
{
    gerarListaVerticesSemEntrada();
    while (!listaS.empty())
    {
        listaL.push_back(listaS[0]);
        //cout << "adicionando " << listaS[0]+1 << " a L" << endl;

        removerAtualizarArcos(listaS[0]);
        listaS.erase(listaS.begin());
    }

    if (qtdArcos != 0)
    {
        cout << "Erro: ciclo detectado" << endl;
    }
    else
    {
        imprimeL();
    }
}