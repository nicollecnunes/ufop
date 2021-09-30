#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;

class Cliente
{
    string nome;
    string endereco;
    string cpf;

    public:
    // construtor que seta tudo como vazio
    Cliente(string="", string="", string="");
    // destrutor
    virtual ~Cliente();  

    string getNome() const;
    void setNome(string);

    string getEndereco() const;
    void setEndereco(string);

    string getCpf() const;
    void setCpf(string);
};

#endif