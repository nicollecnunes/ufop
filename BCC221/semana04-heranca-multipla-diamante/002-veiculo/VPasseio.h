#ifndef VPASSEIO_H
#define VPASSEIO_H

#include "veiculo.h"
using std :: string;

class VPasseio : virtual public Veiculo{
    int volumeInterno;
public:
    VPasseio(const string="", const double=0.0, const int=0, const int=0);
    
    void setVolume(const int);
    int getVolume() const;

    double pesoPotencia() const;

    void print();
};

#endif