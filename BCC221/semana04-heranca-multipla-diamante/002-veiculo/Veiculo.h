#ifndef VEICULO_H
#define VEICULO_H

#include <string>
using std :: string;

class Veiculo {
    string nome;
    double peso;
    int potencia;
public:
    Veiculo(const string="", const double=0.0, const int=0);
    
    void setNome(const string);
    string getNome() const;

    void setPotencia(const int);
    int getPotencia() const;

    void setPeso(const double);
    double getPeso() const;

    void print();
};

#endif