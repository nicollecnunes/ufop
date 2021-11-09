#ifndef TP1POO_CASA_H
#define TP1POO_CASA_H

#include "Imovel.h"
#include <iostream>

class Casa : public Imovel{
private:
    int andares;
    bool sala_jantar;
public:
    Casa(const int = 0, const float = 0.0, const string = "",
            const string  = "", const string  = "", const string = "",
            const int = 0, const int = 0, const int = 0, const int = 0,
            const bool = false);

    virtual ~Casa();

    int getAndares() const;
    void setAndares(int);

    bool getSalaJantar() const;
    void setSalaJantar(bool);

    virtual void saida(ostream&);
    void imprimirTudo();
    friend ostream& operator <<(ostream&, Casa&);
};

#endif
