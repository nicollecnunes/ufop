/**
* @file System.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo que define os métodos da entidade Sistema
**/

#include "System.h"

System::System(){}

System::System(double v)
{
    setSystemValue(v);
}

System::~System(){}

void System::setSystemValue(double v)
{
    this->value = v;
}

double System::getSystemValue() const
{
    return value;
}

System* System::operator=(const System* s)
{
    if (s == this)
    {
        return this;
    }

    this->value = s->value;

    return this;
}