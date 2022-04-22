#include "Flow.h"
#include "System.h"

Flow::Flow()
{
    nock = NULL;
    target = NULL;
}

Flow::Flow(System *n, System *t)
{
    this->nock = n;
    this->target = t;
}

Flow::~Flow(){}

System * Flow::getNock(void) const
{
    return nock;
}

void Flow::setNock(System *n)
{
    this->nock = n;
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

    this->nock = f->nock;
    this->target = f->target;
    this->flowValue = f->flowValue;

    return this;
}