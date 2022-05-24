#ifndef IFLOW_HPP
#define IFLOW_HPP

#include "string"

using namespace std;

class ISystem;

//! Class Flow
/**
* Está classe representa a inteface do fluxo da simulação.
*/
class IFlow {
public:
    /*!
        Esse é o destrutor padrão da classe Flow
    */
    virtual ~IFlow(){};

    /*!
        Retorna o nome do fluxo.
        \return string - nome do fluxo.
    */
    virtual string getName() const = 0;

    /*!
        Seta o nome do fluxo
        \param name - nome do fluxo.
    */
    virtual void setName(string name) = 0;

    /*!
        Retorna o valor atual do fluxo.
        \return double - valor atual do fluxo.
    */
    virtual double getCurrentValue() const = 0;

    /*!
        Seta o valor atual do fluxo
        \param value - novo valor atual do fluxo.
    */
    virtual void setCurrentValue(double value) = 0;

    /*!
        Retorna o ponteiro do sistema de entrada do fluxo.
        \return System * - ponteiro para um sistema de entrada.
    */
    virtual ISystem * getSource(void) const = 0;

    /*!
        Retorna o ponteiro do sistema de saída do fluxo.
        \return System * - ponteiro para um sistema de saída.
    */
    virtual ISystem * getTarget(void) const = 0;

    /*!
        Seta o ponteiro para o sistema de entrada do fluxo.
        \param source - ponteiro para um sistema de entrada.
    */
    virtual void setSource(ISystem * source) = 0;

    /*!
        Seta o ponteiro para o sistema de saída do fluxo.
        \param target - ponteiro para um sistema de saída.
    */
    virtual void setTarget(ISystem * target) = 0;

    /*!
        Connecta dois fluxo ao sistema (entrada e saída).
        \param source - ponteiro para um sistema de entrada.
        \param target - ponteiro para um sistema de saída.
    */
    virtual void connect(ISystem *source = NULL, ISystem* target = NULL) = 0;

    /*!
        Método virtual puro que será herdado por subclasses criadas pelo usuário, essa conterá
        a equação que será executada pelo fluxo.
    */
    virtual double execute() const = 0 ;
};

#endif
