#ifndef IFLOW_H
#define IFLOW_H

/**
* @file Flow.h
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo header da entidade que representa o fluxo.
**/

#include "string"
using namespace std;

class ISystem;

//! Class IFlow
/**
* Representa a interface do fluxo da simulação.
*/
class IFlow 
{
   public:
    /*!
        Destrutor padrão da classe IFlow
    */
        virtual ~IFlow(){};

        
    /*!
        Metodo virtual para implementação em classes especializadas.
    */
        virtual double run() = 0;

        
    /*!
        Retorna o ponteiro do sistema de saída.
        \return System* - ponteiro para um sistema de saída.
    */
        virtual ISystem *getOrigin(void) const = 0;

        
    /*!
        Define o ponteiro para o sistema de saída do fluxo.
        \param origin - ponteiro para um sistema de saída.
    */
        virtual void setOrigin(ISystem *origin) = 0;

        
    /*!
        Retorna o ponteiro do sistema de entrada.
        \return ISystem* - ponteiro para um sistema de entrada.
    */
        virtual ISystem *getTarget(void) const = 0;

        
    /*!
        Seta o ponteiro para o sistema de saída do fluxo.
        \param target - ponteiro para um sistema de saída.
    */
        virtual void setTarget(ISystem *target) = 0;

        
    /*!
        Retorna o valor atual do fluxo.
        \return double - valor atual do fluxo.
    */
        virtual double getFlowValue() const = 0;

        
    /*!
        Define o valor atual do fluxo
        \param value - novo valor atual do fluxo.
    */
        virtual void setFlowValue(double value) = 0;

};

#endif