#ifndef JOGADORDEFESA_H
#define JOGADORDEFESA_H

using namespace std;

#include "Jogador.h"

class JogadorDefesa : public Jogador{
    int desarme;
    int cobertura;
public:
    JogadorDefesa(int, int);

    virtual int getHabilidade();

    virtual void saida(ostream&) const;
    friend ostream& operator<<(ostream&, const JogadorDefesa&);
};

#endif