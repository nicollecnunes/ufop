#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "ISystem.hpp"

using namespace std;

//! Class System
/**
* Está classe(concreta) representa o sistema/estoque da simulação.
*/
class System : public ISystem {
protected:
    string name; /*!< Esse atributo possui o nome do sistema */
    double value; /*!< Esse atributo possui o valor armazenado no sistema */
public:
    /*!
        Esse é o construtor padrão da classe System.
    */
    System();

    /*!
        Esse é o construtor copia da classe System.
        \param system sistema para ser copiado
    */
    System(const System *system);

    /*!
        Esse é um construtor que possui um atributo inicial para o sistema.
        \param name nome do sistema.
    */
    System(string name);

    /*!
        Esse é um construtor que possui dois atributos iniciais para o sistema.
        \param name nome do sistema.
        \param value valor inicial do sistema.
    */
    System(string name, double value);

    /*!
        Esse é o destrutor padrão da classe System.
    */
    virtual ~System();

    /*!
        Seta o valor armazenado pelo sistema
        \param value - valor a ser armazenado pelo sistema.
    */
    void setValue(double value);

    /*!
        Retornao valor armazenado pelo sistema
        \return double - valor armazenado pelo sistema.
    */
    double getValue() const;

    /*!
        Retorna o nome do sistema.
        \return string - nome do sistema.
    */
    string getName() const;

    /*!
        Seta o nome do sistema
        \param name - nome do sistema.
    */
    void setName(string name);

    /*!
        Operador de atribuição (=) sobrecarregado para a classe System.
    */
    System* operator=(const System* system);
};

#endif
