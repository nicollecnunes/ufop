#include <iostream>
#include <vector>
#include <list>

#include "FordFulkerson.hpp"

int main () 
{
    int qtdVertices, qtdArcos;
    cin >> qtdVertices >> qtdArcos;
    cout << "Grafo de " << qtdVertices << " vertices e " << qtdArcos << " arcos" << endl;

    Grafo g = Grafo(qtdVertices, qtdArcos);
    g.preencheListas();
    g.FordFulkerson();

    return 0;
}