#ifndef JOGADORATACANTE_H
#define JOGADORATACANTE_H

using namespace std;

#include "Jogador.h"

class JogadorAtacante : public Jogador{
    int velocidade;
    int tecnica;
public:
    JogadorAtacante(int, int);

    virtual int getHabilidade();

    virtual void saida(ostream&) const;
    friend ostream& operator<<(ostream&, const JogadorAtacante&);
};

#endif