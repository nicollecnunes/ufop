/**
* @file FlowClasses.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo que define as classes herdeiras de Fluxo (especializadas)
**/

#include "../src/Flow.h"
#include "../src/Model.h"
#include "../src/System.h"

//! Class FlowExponential
/**
* Herda a classe Flow e implementa a execucao de forma especializada
*/
class FlowExponential : public Flow
{
    public:
        /*!
            Construtor padrão
        */
        FlowExponential(): Flow(){}

        /*!
            Método run especializado com a equação do fluxo exponencial
        */
        double run(){
            return 0.01 * getOrigin()->getSystemValue();
        }
};


//! Class FlowLogistic
/**
* Herda a classe Flow e implementa a execucao de forma especializada
*/
class FlowLogistic : public Flow
{
    public:
        /*!
            Construtor padrão
        */
        FlowLogistic(): Flow(){}


        /*!
            Método run especializado com a equação do fluxo logístico
        */
        double run(){
            return 0.01 * getTarget()->getSystemValue() * (1 - getTarget()->getSystemValue() / 70);
        }
};


//! Class FlowComplex
/**
* Herda a classe Flow e implementa a execucao de forma especializada
*/
class FlowComplex: public Flow
{
    public:
        /*!
            Construtor padrão
        */
        FlowComplex(): Flow(){}


        /*!
            Método run especializado com a equação do fluxo complexo
        */
        double run(){
            return 0.01 * getOrigin()->getSystemValue();
        }
};

