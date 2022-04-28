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

Flow::Flow(System *n, System *t)
{
    this->origin = n;
    this->target = t;
}

Flow::~Flow(){}

System * Flow::getOrigin(void) const
{
    return origin;
}

void Flow::setOrigin(System *n)
{
    this->origin = n;
}


System * Flow::getTarget(void) const
{
    return target;
}

void Flow::setTarget(System *t)
{
    this->target = t;
}

double Flow::getFlowValue() const
{
    return flowValue;
}

void Flow::setFlowValue(double v)
{
    this->flowValue = v;
}

Flow* Flow::operator=(const Flow *f)
{
    if (f == this)
    {
        return this;
    }

    this->origin = f->origin;
    this->target = f->target;
    this->flowValue = f->flowValue;

    return this;
}