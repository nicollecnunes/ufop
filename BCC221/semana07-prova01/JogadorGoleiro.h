#ifndef JOGADORGOLEIRO_H
#define JOGADORGOLEIRO_H

using namespace std;

#include "Jogador.h"

class JogadorGoleiro : public Jogador{
    int reflexos;
    float altura;
public:
    JogadorGoleiro(int, float);

    virtual int getHabilidade();

    virtual void saida(ostream&) const;
    friend ostream& operator<<(ostream&, const JogadorGoleiro&);
};

#endif