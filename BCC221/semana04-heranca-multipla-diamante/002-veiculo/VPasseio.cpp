#include "VPasseio.h"
#include <iostream>
using std :: cout;

VPasseio :: VPasseio (const string _nome,
        const double _peso, const int _potencia,
        const int _volume) : Veiculo(_nome, _peso, _potencia),
        volumeInterno(_volume){}

void VPasseio :: setVolume(const int _volume){
    volumeInterno = _volume;
}

int VPasseio :: getVolume() const {
    return volumeInterno;
}

double VPasseio :: pesoPotencia() const {
    return getPeso() / getPotencia();
}

void VPasseio :: print(){
    Veiculo :: print();
    cout << "\nVolume Interno: " << getVolume();
}