#include <iostream>
#include <vector>
#include <list>

#include "DFS.hpp"

int main () 
{
    int qtdVertices, qtdArestas, ehDirecionado, verticeInicial;
    cin >> qtdVertices >> qtdArestas >> ehDirecionado >> verticeInicial;
    //cout << "Grafo de " << qtdVertices << " vertices e " << qtdArestas << " arestas" << endl;

    Grafo g = Grafo(qtdVertices, qtdArestas, ehDirecionado, verticeInicial);
    g.criaGrafo();

    vector<int> ordemFinal;
    g.buscaEmProfundidade(g.verticeInicial, &ordemFinal);

    int tamanhoLista = ordemFinal.size();
    for (int i = 0; i < tamanhoLista; i++)
        cout << ordemFinal[i] + 1 << "\n";

    return 0;
}