/**
* @file System.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo que define os métodos da entidade Sistema
**/

#include "System.h"

System::System()
{
    value = 0;
}

System::System(const System &system)
{  
    value = system.value;
}

System::System(double v)
{
    setValue(v);
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

System* System::operator=(const System* s)
{
    if (s == this)
    {
        return this;
    }

    value = s->value;

    return this;
}