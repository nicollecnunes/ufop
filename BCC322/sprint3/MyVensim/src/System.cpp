/**
* @file System.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo que define os métodos da entidade Sistema
**/

#include "System.h"

System::System(){}

System::System(double value)
{
    setSystemValue(value);
}

System::~System(){}

void System::setSystemValue(double value)
{
    this->value = value;
}

double System::getSystemValue() const
{
    return value;
}

System* System::operator=(const System* system)
{
    if (system == this)
    {
        return this;
    }

    this->value = system->value;

    return this;
}