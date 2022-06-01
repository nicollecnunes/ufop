#include <iostream>
#include <vector>
#include <list>

#include "FordFulkerson.hpp"

int main () 
{
    int qtdVertices, qtdArcos;
    cin >> qtdVertices >> qtdArcos;

    Grafo g = Grafo(qtdVertices, qtdArcos);
    g.criaGrafo();
    g.FordFulkerson();

    return 0;
}