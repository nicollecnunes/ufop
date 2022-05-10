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

class Flow 
{
    protected:
        System *origin;
        System *target;
        double flowValue;
    public:
        Flow();
        Flow(System *origin, System *target);
        virtual ~Flow();

        virtual double run() = 0;

        System *getOrigin(void) const;
        void setOrigin(System *n);

        System *getTarget(void) const;
        void setTarget(System *t);

        double getFlowValue() const;
        void setFlowValue(double v);

        Flow* operator=(const Flow* f);
};

#endif