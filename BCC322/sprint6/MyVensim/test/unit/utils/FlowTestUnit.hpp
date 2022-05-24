#ifndef FLOWTESTUNIT_HPP
#define FLOWTESTUNIT_HPP

#include "../../../src/include/FlowImpl.hpp"

//! Class FlowTestUnit
/**
* Está classe herda o Flow e implementa a execucao
*/
class FlowTestUnit : public FlowBody
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
    FlowTestUnit(string name, System *s, System *t );

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
