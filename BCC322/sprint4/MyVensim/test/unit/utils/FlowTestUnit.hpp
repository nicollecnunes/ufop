#ifndef FLOWTESTUNIT_HPP
#define FLOWTESTUNIT_HPP

#include "../../../src/Flow.hpp"

//! Class FlowTestUnit
/**
* Está classe herda o Flow e implementa a execucao
*/
class FlowTestUnit : public Flow
{
public:
    /*!
        Esse é o destrutor padrão da classe FlowTestUnit
    */
    FlowTestUnit();

    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowTestUnit(string name);

    /*!
        Esse é o construtor copia da classe Flow.
        \param flow fluxo para ser copiado
    */
    FlowTestUnit(const Flow *flow);

    /*!
        Esse é o destrutor padrão da classe Flow
    */
    virtual ~FlowTestUnit();

    /*!
        Método que possui a implementacao da quacao
        \return double - valor calculado pela execucao da equacao do flow
    */
    double execute() const;
};

#endif
