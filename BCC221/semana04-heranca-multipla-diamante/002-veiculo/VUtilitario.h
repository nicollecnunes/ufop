#ifndef VUTILITARIO_H
#define VUTILITARIO_H

#include "VPasseio.h"
#include "VCarga.h"

class VUtilitario : public VPasseio, public VCarga {
public:
    VUtilitario(const string="", const double = 0.0,
    const int = 0, const int = 0, const int =0);

    double pesoPotencia() const;
    void print();
};

#endif