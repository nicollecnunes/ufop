#ifndef ISYSTEM_HPP
#define ISYSTEM_HPP

#include"string"

using namespace std;

//! Class System
/**
* Está classe representa a interface d sistema/estoque da simulação.
*/
class ISystem {
public:
    /*!
        Esse é o destrutor padrão da classe System.
    */
    virtual ~ISystem(){};

    /*!
        Seta o valor armazenado pelo sistema
        \param value - valor a ser armazenado pelo sistema.
    */
    virtual void setValue(double value) = 0;

    /*!
        Retornao valor armazenado pelo sistema
        \return double - valor armazenado pelo sistema.
    */
    virtual double getValue() const = 0;

    /*!
        Retorna o nome do sistema.
        \return string - nome do sistema.
    */
    virtual string getName() const = 0;

    /*!
        Seta o nome do sistema
        \param name - nome do sistema.
    */
    virtual void setName(string name) = 0;
};

#endif
