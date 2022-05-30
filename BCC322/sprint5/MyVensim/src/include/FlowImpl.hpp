#ifndef FLOWIMPL_HPP
#define FLOWIMPL_HPP

#include "Flow.hpp"

//! Class FlowImpl
/**
* Está classe (concreta) representa o fluxo da simulação.
*/
class FlowImpl : public Flow {
protected:
    string name; /*!< Esse atributo possui o nome do fluxo */
    double currentValue; /*!< Esse atributo possui o valor atual do fluxo em determinado tempo */
    System *source; /*!< Esse atributo possui um ponteiro para o sistema de entrada do fluxo */
    System *target; /*!< Esse atributo possui um ponteiro para o sistema de saída do fluxo */
public:
/*!
        Esse é o construtor padrão da classe FlowImpl
    */
    FlowImpl();

    /*!
        Esse é o construtor copia da classe Flow.
        \param flow fluxo para ser copiado
    */
    FlowImpl(const FlowImpl* flow);
    
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowImpl(string name);

    /*!
        
    */
    FlowImpl(string name, System *s = NULL, System *t = NULL);

    /*!
        Esse é o destrutor padrão da classe Flow
    */
    virtual ~FlowImpl();

    /*!
        Retorna o nome do fluxo.
        \return string - nome do fluxo.
    */
    string getName() const;

    /*!
        Seta o nome do fluxo
        \param name - nome do fluxo.
    */
    void setName(string name);

    /*!
        Retorna o valor atual do fluxo.
        \return double - valor atual do fluxo.
    */
    double getCurrentValue() const;

    /*!
        Seta o valor atual do fluxo
        \param value - novo valor atual do fluxo.
    */
    void setCurrentValue(double value);

    /*!
        Retorna o ponteiro do sistema de entrada do fluxo.
        \return System * - ponteiro para um sistema de entrada.
    */
    System * getSource(void) const;

    /*!
        Retorna o ponteiro do sistema de saída do fluxo.
        \return System * - ponteiro para um sistema de saída.
    */
    System * getTarget(void) const;

    /*!
        Seta o ponteiro para o sistema de entrada do fluxo.
        \param source - ponteiro para um sistema de entrada.
    */
    void setSource(System * source);

    /*!
        Seta o ponteiro para o sistema de saída do fluxo.
        \param target - ponteiro para um sistema de saída.
    */
    void setTarget(System * target);

    /*!
        Connecta dois fluxo ao sistema (entrada e saída).
        \param source - ponteiro para um sistema de entrada.
        \param target - ponteiro para um sistema de saída.
    */
    void connect(System *source = NULL, System* target = NULL);

    /*!
        Operador de atribuição (=) sobrecarregado para a classe Flow.
    */
    FlowImpl* operator=(const FlowImpl* flow);
};

#endif
