/**
* @file Flow.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo que define os Metodos da entidade Fluxo
**/

#include "Flow.h"
#include "ISystem.h"

#define DEBUGING
#ifdef DEBUGING
    extern int numHandleCreated;
	extern int numHandleDeleted;
	extern int numBodyCreated;
	extern int  numBodyDeleted;
#endif

Flow::Flow()
{
    origin = NULL;
    target = NULL;
    value = 0;

    #ifdef DEBUGING		
		numBodyCreated++;
    #endif
}

Flow::Flow(ISystem *origin, ISystem *target)
{
    origin = origin;
    target = target;

    #ifdef DEBUGING		
		numBodyCreated++;
    #endif
}

Flow::Flow(const Flow &flow)
{
    value = flow.value;
    origin = flow.origin;
    target = flow.target;
}

Flow::~Flow(){}

ISystem * Flow::getOrigin(void) const
{
    return origin;
}

void Flow::setOrigin(ISystem *o)
{
    origin = o;
}


ISystem * Flow::getTarget(void) const
{
    return target;
}

void Flow::setTarget(ISystem *t)
{
    target = t;
}

double Flow::getValue() const
{
    return value;
}

void Flow::setValue(double v)
{
    value = v;
}

Flow* Flow::operator=(const Flow *flow)
{
    if (flow == this)
    {
        return this;
    }

    origin = flow->origin;
    target = flow->target;
    value = flow->value;

    return this;
}