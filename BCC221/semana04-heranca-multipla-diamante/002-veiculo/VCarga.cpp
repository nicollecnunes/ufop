#include "VCarga.h"
#include <iostream>
using std :: cout;

VCarga :: VCarga (const string _nome,
        const double _peso, const int _potencia,
        const int _carga) : Veiculo(_nome, _peso, _potencia),
        carga(_carga){}

void VCarga :: setCarga(const int _carga){
    this->carga = _carga;
}

int VCarga :: getCarga() const {
    return carga;
}

double VCarga :: pesoPotencia() const {
    return (getPeso() + getCarga()) / getPotencia();
}

void VCarga :: print(){
    Veiculo :: print();
    cout << "\nCarga: " << getCarga();
}