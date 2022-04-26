#include <iostream>
#include <vector>
#include <list>

#include "DFS.hpp"

int main () 
{
    Grafo g = Grafo();
    g.criaGrafo();

    vector<int> ordemDeVisitacao;
    g.buscaEmProfundidade(g.verticeInicial, &ordemDeVisitacao);

    int tamanhoLista = ordemDeVisitacao.size();
    for (int i = 0; i < tamanhoLista; i++)
    {
        cout << ordemDeVisitacao[i] + 1 << "\n";
    }

    return 0;
}