/**
* @file System.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo que define os Metodos da entidade Sistema
**/

#include "System.h"

System::System()
{
    value = 0;
}

System::System(double v)
{
    value = v;
}

System::~System(){}

void System::setValue(double v)
{
    value = v;
}

double System::getValue() const
{
    return value;
}

System* System::operator=(const System* system)
{
    if (system == this)
    {
        return this;
    }

    value = system->value;

    return this;
}