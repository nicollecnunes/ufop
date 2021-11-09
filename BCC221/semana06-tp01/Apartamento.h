#ifndef TP1POO_APARTAMENTO_H
#define TP1POO_APARTAMENTO_H

#include <iostream>
#include "Imovel.h"

class Apartamento : public Imovel {
private:
    int andar;
    float taxa_condominio;
    bool elevador;
    bool sacada;
public:
    Apartamento(const int = 0, const float = 0.0, const string = "",
                const string  = "", const string  = "", const string = "",
                const int = 0, const int = 0, const int = 0, const int = 0,
                const float = 0.0, const bool = false, const bool = false);

    virtual ~Apartamento();

    int getAndar() const;
    void setAndar(int);

    float getTaxaCondominio() const;
    void setTaxaCondominio(float);

    bool getElevador() const;
    void setElevador(bool);

    bool getSacada() const;
    void setSacada(bool);

    virtual void saida(ostream&);
    void imprimirTudo();
    friend ostream& operator <<(ostream&, Apartamento&);
};

#endif
