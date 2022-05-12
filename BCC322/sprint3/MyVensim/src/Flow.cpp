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
    origin = n;
    target = t;
}

Flow::Flow(const Flow &flow)
{
    value = flow.value;
    origin = flow.origin;
    target = flow.target;
}

Flow::~Flow(){}

System * Flow::getOrigin(void) const
{
    return origin;
}

void Flow::setOrigin(System *n)
{
    origin = n;
}


System * Flow::getTarget(void) const
{
    return target;
}

void Flow::setTarget(System *t)
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

Flow* Flow::operator=(const Flow *f)
{
    if (f == this)
    {
        return this;
    }

    origin = f->origin;
    target = f->target;
    value = f->value;

    return this;
}