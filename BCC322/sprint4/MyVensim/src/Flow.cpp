/**
* @file Flow.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo que define os métodos da entidade Fluxo
**/

#include "Flow.h"
#include "ISystem.h"

Flow::Flow()
{
    nock = NULL;
    target = NULL;
}

Flow::Flow(ISystem *n, ISystem *t)
{
    this->nock = n;
    this->target = t;
}

Flow::~Flow(){}

ISystem * Flow::getNock(void) const
{
    return nock;
}

void Flow::setNock(ISystem *n)
{
    this->nock = n;
}


ISystem * Flow::getTarget(void) const
{
    return target;
}

void Flow::setTarget(ISystem *t)
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

    this->nock = f->nock;
    this->target = f->target;
    this->flowValue = f->flowValue;

    return this;
}