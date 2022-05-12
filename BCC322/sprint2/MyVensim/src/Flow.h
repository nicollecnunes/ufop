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
{   private:
        Flow(const Flow &flow);
    protected:
        System *origin;
        System *target;
        double value;
    public:
        Flow();
        Flow(System *origin, System *target);
        virtual ~Flow();

        virtual double run() = 0;

        System *getOrigin(void) const;
        void setOrigin(System *n);

        System *getTarget(void) const;
        void setTarget(System *t);

        double getValue() const;
        void setValue(double v);

        Flow* operator=(const Flow* f);
};

#endif