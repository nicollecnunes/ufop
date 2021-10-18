#include "VUtilitario.h"
#include <iostream>
using std :: cout;

VUtilitario :: VUtilitario (const string _nome,
        const double _peso, const int _potencia,
        const int _carga, const int _volume) :
        VPasseio(_nome, _peso, _potencia, _volume),
        VCarga(_nome, _peso, _potencia, _carga),
        // chama Veiculo explicitamente pois e virtual
        Veiculo(_nome, _peso, _potencia){}

double VUtilitario :: pesoPotencia() const {
    return VCarga:: pesoPotencia();
}

void VUtilitario :: print(){
    Veiculo :: print();
    cout << "\nVolume Interno: " << VPasseio :: getVolume();
    cout << "\nCarga: " << VCarga :: getCarga();
}