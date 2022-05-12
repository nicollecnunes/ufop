#ifndef FLOW_H
#define FLOW_H

/**
* @file Flow.h
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo header da entidade que representa o fluxo.
**/


#include "IFlow.h"
using namespace std;
class ISystem;
//! Class Flow
/**
* Representa o fluxo da simulação. [CONCRETA]
*/
class Flow    : public IFlow
{
    private:
    /*!
        Construtor copia da classe Flow
    */
        Flow(const Flow &flow);
    protected:
        ISystem *origin; /*!< Ponteiro para o sistema de entrada do fluxo */
        ISystem *target; /*!< Ponteiro para o sistema de saída do fluxo */
        double value; /*!< Valor atual do fluxo em determinado tempo */
    public:
    /*!
        Construtor padrão da classe Flow
    */
        Flow();
    /*!
        Construtor com atributos
        \param *origin sistema de entrada do fluxo
        \param *target sistema de saída do fluxo
    */
        Flow(ISystem *origin, ISystem *target);

        
    /*!
        Destrutor padrão da classe Flow
    */
        virtual ~Flow();

        
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

        

        Flow* operator=(const Flow* f);
};

#endif