#include "Veiculo.h"
#include <iostream>

using std :: cout;

Veiculo :: Veiculo(const string _nome, const double _peso, const int _potencia) :
    nome(_nome), peso(_peso), potencia(_potencia) {}

void Veiculo :: setNome(const string _nome){
    this->nome = _nome;
}

string Veiculo :: getNome() const {
    return nome;
}

void Veiculo :: setPotencia(const int _potencia){
    this->potencia = _potencia;
}

int Veiculo :: getPotencia() const {
    return potencia;
}

void Veiculo :: setPeso(const double _peso){
    this->peso = _peso;
}

double Veiculo :: getPeso() const {
    return peso;
}

void Veiculo :: print(){
    cout << "\nNome: " << getNome()
        << "\nPeso: " << getPeso()
        << "\nPotencia: " << getPotencia();
}