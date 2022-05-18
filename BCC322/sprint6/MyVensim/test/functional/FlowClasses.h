#ifndef FLOWCLASSES_H
#define FLOWCLASSES_H

/**
* @file FlowClasses.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo que define as classes herdeiras de Fluxo (especializadas)
**/

#include "../../src/Flow.h"
#include "../../src/Model.h"
#include "../../src/System.h"

//! Class FlowExponential
/**
* Herda a classe Flow e implementa a execucao de forma especializada
*/
class FlowExponential    : public Flow
{
    public:
        /*!
            Construtor padrão
        */
        FlowExponential()   : Flow(){}

        /*!
            Metodo run especializado com a equação do fluxo exponencial
        */
        double run(){
            return 0.01 * getOrigin()->getValue();
        }
};


//! Class FlowLogistic
/**
* Herda a classe Flow e implementa a execucao de forma especializada
*/
class FlowLogistic    : public Flow
{
    public:
        /*!
            Construtor padrão
        */
        FlowLogistic()   : Flow(){}


        /*!
            Metodo run especializado com a equação do fluxo logístico
        */
        double run(){
            return 0.01 * getTarget()->getValue() * (1 - getTarget()->getValue() / 70);
        }
};


//! Class FlowComplex
/**
* Herda a classe Flow e implementa a execucao de forma especializada
*/
class FlowComplex   : public Flow
{
    public:
        /*!
            Construtor padrão
        */
        FlowComplex()   : Flow(){}


        /*!
            Metodo run especializado com a equação do fluxo complexo
        */
        double run(){
            return 0.01 * getOrigin()->getValue();
        }
};

#endif