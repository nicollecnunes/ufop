/**
* @file IFlow.h
* @author Nicolle Nunes
* @date 28 April 2022
* @brief Interface do fluxo
**/

#ifndef IFLOW_H
#define IFLOW_H

#include "string"
using namespace std;

class ISystem;

class Flow 
{
    public:
        virtual ~IFlow(){};

        virtual double run() = 0;

        virtual ISystem *getNock(void) const = 0;
        virtual void setNock(ISystem *n);

        virtual ISystem *getTarget(void) const = 0;
        void setTarget(ISystem *t);

        virtual double getFlowValue() const = 0;
        virtual void setFlowValue(double v) = 0;
};

#endif