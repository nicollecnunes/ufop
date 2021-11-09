#ifndef TP1POO_CHACARA_H
#define TP1POO_CHACARA_H

#include "Imovel.h"
#include <iostream>


class Chacara : public Imovel {
private:
    bool salao_festa;
    bool salao_jogos;
    bool campo_futebol;
    bool churrasqueira;
    bool piscina;
public:
    Chacara(const int = 0, const float = 0.0, const string = "",
            const string  = "", const string  = "", const string = "",
            const int = 0, const int = 0, const int = 0, const bool = false,
            const bool = false, const bool = false, const bool = false, const bool = false);

    virtual ~Chacara();

    bool getSalaoFesta() const;
    void setSalaoFesta(bool);

    bool getSalaoJogos() const;
    void setSalaoJogos(bool);

    bool getCampoFutebol() const;
    void setCampoFutebol(bool);

    bool getChurrasqueira() const;
    void setChurrasqueira(bool);

    bool getPiscina() const;
    void setPiscina(bool);

    void imprimirTudo();

    virtual void saida(ostream&);

    friend ostream& operator <<(ostream&, Chacara&);
};


#endif
