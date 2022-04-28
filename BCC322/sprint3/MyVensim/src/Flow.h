/**
* @file Flow.h
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo header da entidade que representa o fluxo.
**/

#ifndef FLOW_HPP
#define FLOW_HPP

#include "string"
using namespace std;

class System;

//! Class Flow
/**
* Representa o fluxo da simulação.
*/
class Flow 
{
    protected:
        System *origin; /*!< Ponteiro para o sistema de entrada do fluxo */
        System *target; /*!< Ponteiro para o sistema de saída do fluxo */
        double flowValue; /*!< Valor atual do fluxo em determinado tempo */
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
        Flow(System *origin, System *target);

        
    /*!
        Destrutor padrão da classe Flow
    */
        virtual ~Flow();

        
    /*!
        Método virtual para implementação em classes especializadas.
    */
        virtual double run() = 0;

        
    /*!
        Retorna o ponteiro do sistema de saída.
        \return System* - ponteiro para um sistema de saída.
    */
        System *getOrigin(void) const;

        
    /*!
        Define o ponteiro para o sistema de saída do fluxo.
        \param origin - ponteiro para um sistema de saída.
    */
        void setOrigin(System *origin);

        
    /*!
        Retorna o ponteiro do sistema de entrada.
        \return System* - ponteiro para um sistema de entrada.
    */
        System *getTarget(void) const;

        
    /*!
        Seta o ponteiro para o sistema de saída do fluxo.
        \param target - ponteiro para um sistema de saída.
    */
        void setTarget(System *target);

        
    /*!
        Retorna o valor atual do fluxo.
        \return double - valor atual do fluxo.
    */
        double getFlowValue() const;

        
    /*!
        Define o valor atual do fluxo
        \param value - novo valor atual do fluxo.
    */
        void setFlowValue(double value);

        

        Flow* operator=(const Flow* f);
};

#endif