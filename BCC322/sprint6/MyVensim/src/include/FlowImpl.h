#ifndef FLOW_H
#define FLOW_H

/**
* @file Flow.h
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo header da entidade que representa o fluxo.
**/

#include "Bridge.h"
#include "Flow.h"

using namespace std;
class ISystem;
//! Class Flow
/**
* Representa o fluxo da simulação. [CONCRETA]
*/
class FlowBody    : public Body
{
    private:
    /*!
        Construtor copia da classe FlowBody
    */
        FlowBody(const FlowBody &flow);
    protected:
        ISystem *origin; /*!< Ponteiro para o sistema de entrada do fluxo */
        ISystem *target; /*!< Ponteiro para o sistema de saída do fluxo */
        double value; /*!< Valor atual do fluxo em determinado tempo */
    public:
    /*!
        Construtor padrão da classe FlowBody
    */
        FlowBody();
    /*!
        Construtor com atributos
        \param *origin sistema de entrada do fluxo
        \param *target sistema de saída do fluxo
    */
        FlowBody(ISystem *origin, ISystem *target);

        
    /*!
        Destrutor padrão da classe FlowBody
    */
        virtual ~FlowBody();

        
    /*!
        Metodo virtual para implementação em classes especializadas.
    */
        virtual double run() = 0;

        
    /*!
        Retorna o ponteiro do sistema de saída.
        \return ISystem* - ponteiro para um sistema de saída.
    */
        ISystem *getOrigin(void) const;

        
    /*!
        Define o ponteiro para o sistema de saída do fluxo.
        \param origin - ponteiro para um sistema de saída.
    */
        void setOrigin(ISystem *origin);

        
    /*!
        Retorna o ponteiro do sistema de entrada.
        \return ISystem* - ponteiro para um sistema de entrada.
    */
        ISystem *getTarget(void) const;

        
    /*!
        Seta o ponteiro para o sistema de saída do fluxo.
        \param target - ponteiro para um sistema de saída.
    */
        void setTarget(ISystem *target);

        
    /*!
        Retorna o valor atual do fluxo.
        \return double - valor atual do fluxo.
    */
        double getValue() const;

        
    /*!
        Define o valor atual do fluxo
        \param value - novo valor atual do fluxo.
    */
        void setValue(double value);

        

        FlowBody* operator=(const FlowBody* f);
};

template <typename F_IMPL>
class FlowHandle : public Handle<F_IMPL>, public Flow {
public:
    /*!
        
    */
    FlowHandle<F_IMPL>(string name = "", System *s = NULL, System *t = NULL){
        this->pImpl_->setName(name);
        this->pImpl_->setSource(s);
        this->pImpl_->setTarget(t);
    }

    virtual ~FlowHandle(){};

    /*!
        Retorna o nome do fluxo.
        \return string - nome do fluxo.
    */
    string getName() const {
        return this->pImpl_->getName();
    }

    /*!
        Seta o nome do fluxo
        \param name - nome do fluxo.
    */
    void setName(string name) {
        this->pImpl_->setName(name);
    }

    /*!
        Retorna o valor atual do fluxo.
        \return double - valor atual do fluxo.
    */
    double getCurrentValue() const {
        return this->pImpl_->getCurrentValue();
    }

    /*!
        Seta o valor atual do fluxo
        \param value - novo valor atual do fluxo.
    */
    void setCurrentValue(double value) {
        this->pImpl_->setCurrentValue(value);
    }

    /*!
        Retorna o ponteiro do sistema de entrada do fluxo.
        \return System * - ponteiro para um sistema de entrada.
    */
    System * getSource(void) const {
        return this->pImpl_->getSource();
    }

    /*!
        Retorna o ponteiro do sistema de saída do fluxo.
        \return System * - ponteiro para um sistema de saída.
    */
    System * getTarget(void) const {
        return this->pImpl_->getTarget();
    }

    /*!
        Seta o ponteiro para o sistema de entrada do fluxo.
        \param source - ponteiro para um sistema de entrada.
    */
    void setSource(System * source) {
       this->pImpl_->setSource(source);
    }

    /*!
        Seta o ponteiro para o sistema de saída do fluxo.
        \param target - ponteiro para um sistema de saída.
    */
    void setTarget(System * target) {
        this->pImpl_->setTarget(target);
    }

    /*!
        Connecta dois fluxo ao sistema (entrada e saída).
        \param source - ponteiro para um sistema de entrada.
        \param target - ponteiro para um sistema de saída.
    */
    void connect(System *source = NULL, System* target = NULL) {
        this->pImpl_->connect(source, target);
    }

    double execute() const  {
        return this->pImpl_->execute();
    }

};


#endif