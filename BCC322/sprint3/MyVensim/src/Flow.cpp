/**
* @file Flow.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo que define os métodos da entidade Fluxo
**/

#include "Flow.h"
#include "System.h"

Flow::Flow()
{
    origin = NULL;
    target = NULL;
}

Flow::Flow(System *origin, System *target)
{
    this->origin = origin;
    this->target = target;
}

Flow::~Flow(){}

System * Flow::getOrigin(void) const
{
    return origin;
}

void Flow::setOrigin(System *origin)
{
    this->origin = origin;
}


System * Flow::getTarget(void) const
{
    return target;
}

void Flow::setTarget(System *target)
{
    this->target = target;
}

double Flow::getFlowValue() const
{
    return flowValue;
}

void Flow::setFlowValue(double value)
{
    this->flowValue = value;
}

Flow* Flow::operator=(const Flow *flow)
{
    if (flow == this)
    {
        return this;
    }

    this->origin = flow->origin;
    this->target = flow->target;
    this->flowValue = flow->flowValue;

    return this;
}