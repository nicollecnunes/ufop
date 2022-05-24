#ifndef SYSTEMIMPL_HPP
#define SYSTEMIMPL_HPP

#include "System.hpp"
#include "Bridge.hpp"

using namespace std;

//! Class System
/**
* Está classe(concreta) representa o sistema/estoque da simulação.
*/
class SystemBody : public Body {
protected:
    string name; /*!< Esse atributo possui o nome do sistema */
    double value; /*!< Esse atributo possui o valor armazenado no sistema */
private:
    /*!
        Esse é o construtor copia da classe System.
        \param system sistema para ser copiado
    */
    SystemBody(const SystemBody *system);

    /*!
        Operador de atribuição (=) sobrecarregado para a classe System.
    */
    SystemBody* operator=(const SystemBody* system);
public:
    /*!
        Esse é o construtor padrão da classe System.
    */
    SystemBody();

    /*!
        Esse é um construtor que possui um atributo inicial para o sistema.
        \param name nome do sistema.
    */
    SystemBody(string name);

    /*!
        Esse é um construtor que possui dois atributos iniciais para o sistema.
        \param name nome do sistema.
        \param value valor inicial do sistema.
    */
    SystemBody(string name, double value);

    /*!
        Esse é o destrutor padrão da classe System.
    */
    virtual ~SystemBody();

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
};


//! Class SystemHandle
/**
* 
*/
class SystemHandle : public Handle<SystemBody>, public System
{
public:
    /*!
        Esse é um construtor que possui dois atributos iniciais para o sistema.
        \param name nome do sistema.
        \param value valor inicial do sistema.
    */
    SystemHandle(string name = "", double value = 0){
        pImpl_->setName(name);
        pImpl_->setValue(value);
    }

    /*!
        Esse é o destrutor padrão da classe System.
    */
    virtual ~SystemHandle(){};

    /*!
        Seta o valor armazenado pelo sistema
        \param value - valor a ser armazenado pelo sistema.
    */
    void setValue(double value) {
        pImpl_->setValue(value);
    }

    /*!
        Retornao valor armazenado pelo sistema
        \return double - valor armazenado pelo sistema.
    */
    double getValue() const {
        return pImpl_->getValue();
    }

    /*!
        Retorna o nome do sistema.
        \return string - nome do sistema.
    */
    string getName() const{
        return pImpl_->getName();
    }

    /*!
        Seta o nome do sistema
        \param name - nome do sistema.
    */
    void setName(string name){
        pImpl_->setName(name);
    }
    
};

#endif
