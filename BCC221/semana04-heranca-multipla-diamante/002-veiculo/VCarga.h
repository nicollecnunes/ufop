#ifndef VCARGA_H
#define VCARGA_H

#include "Veiculo.h"

class VCarga : virtual public Veiculo {
    int carga;
public:
    VCarga(const string="", const double = 0.0,
    const int = 0, const int = 0);

    void setCarga(const int carga);
    int getCarga() const;

    double pesoPotencia() const;
    void print();
};

#endif