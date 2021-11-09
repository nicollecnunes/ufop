#ifndef TP1POO_IMOVEL_H
#define TP1POO_IMOVEL_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Imovel{
private:
    int id;
    float valor;
    string proprietario;
    string rua;
    string bairro;
    string cidade;
    int numero;
    int quartos;
    int banheiros;
public:
     Imovel(const int = 0, const float = 0.0, const string = "",
            const string  = "", const string  = "", const string = "",
            const int = 0, const int = 0, const int = 0);

     virtual ~Imovel();

    int getId() const;
    void setId(int);

    float getValor() const;
    void setValor(float);

    string getProprietario() const;
    void setProprietario(string);

    string getRua() const;
    void setRua(string);

    string getBairro() const;
    void setBairro(string);

    string getCidade() const;
    void setCidade(string);

    int getNumero() const;
    void setNumero(int);

    int getQuartos() const;
    void setQuartos(int);

    int getBanheiros() const;
    void setBanheiros(int);

    bool operator< (const Imovel &other);
    void imprimirTudo();
    virtual void saida(ostream&);

    friend ostream& operator <<(ostream&, Imovel&);
};

#endif
