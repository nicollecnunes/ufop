/**
* @file Flow.h
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo header da entidade que representa o fluxo.
**/

#ifndef FLOW_H
#define FLOW_H

#include "string"
#include "IFlow.h"

using namespace std;

class Flow : public IFlow
{
    protected:
        ISystem *origin;
        ISystem *target;
        double flowValue;
    public:
        Flow();
        Flow(ISystem *origin, ISystem *target);
        virtual ~Flow();

        virtual double run() = 0;

        ISystem *getOrigin(void) const;
        void setOrigin(ISystem *n);

        ISystem *getTarget(void) const;
        void setTarget(ISystem *t);

        double getFlowValue() const;
        void setFlowValue(double v);

        Flow* operator=(const Flow* f);
};

#endif