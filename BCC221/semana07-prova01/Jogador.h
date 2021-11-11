#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <iostream>

using namespace std;

class Jogador{
    string nome;
    int idade;
    int habilidade;
    int gols = 0;
    int camisa;
public:
    Jogador(string, int, int);

    virtual int getHabilidade();
    void somaGol();

    virtual void saida(ostream&) const;
    friend ostream& operator<<(ostream&, const Jogador&);
};

#endif