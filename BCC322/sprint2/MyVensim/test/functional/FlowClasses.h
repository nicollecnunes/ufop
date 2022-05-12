/**
* @file FlowClasses.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo que define as classes herdeiras de Fluxo (especializadas)
**/

#include "../../src/Flow.h"
#include "../../src/Model.h"
#include "../../src/System.h"

class FlowExponential : public Flow
{
    public:
        FlowExponential(): Flow(){}

        double run(){
            return 0.01 * getOrigin()->getValue();
        }
};

class FlowLogistic : public Flow
{
    public:
        FlowLogistic(): Flow(){}

        double run(){
            return 0.01 * getTarget()->getValue() * (1 - getTarget()->getValue() / 70);
        }
};

class FlowComplex: public Flow
{
    public:
        FlowComplex(): Flow(){}

        double run(){
            return 0.01 * getOrigin()->getValue();
        }
};

