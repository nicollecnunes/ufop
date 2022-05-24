#ifndef FLOWIMPL_HPP
#define FLOWIMPL_HPP

#include "Flow.hpp"
#include "Bridge.hpp"

class FlowBody : public Body {
protected:
    string name; /*!< Esse atributo possui o nome do fluxo */
    double currentValue; /*!< Esse atributo possui o valor atual do fluxo em determinado tempo */
    System *source; /*!< Esse atributo possui um ponteiro para o sistema de entrada do fluxo */
    System *target; /*!< Esse atributo possui um ponteiro para o sistema de saída do fluxo */
private:
    /*!
        Operador de atribuição (=) sobrecarregado para a classe Flow.
    */
    FlowBody* operator=(const FlowBody* flow);

    /*!
        Esse é o construtor copia da classe Flow.
        \param flow fluxo para ser copiado
    */
    FlowBody(const FlowBody* flow);
public:
    /*!
        Esse é o construtor padrão da classe FlowImpl
    */
    FlowBody();
    
    /*!
        
    */
    FlowBody(string name, System *s = NULL, System *t = NULL);

    /*!
        Esse é o destrutor padrão da classe Flow
    */
    virtual ~FlowBody();

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

    virtual double execute() const = 0;
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
