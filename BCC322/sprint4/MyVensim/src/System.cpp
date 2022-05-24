#include "System.hpp"

System::System(){
    setValue(0);
}

System::System(const System *system)
{
    if (system == this)
        return;
        
    name = system->name;
    value = system->value;
}

System::System(string name){
    setValue(0);
    setName(name);
}

System::System(string name, double value){
    setName(name);
    setValue(value);
}

System::~System(){}

void System::setValue(double value)
{
    this->value = value;
}

double System::getValue() const
{
    return value;
}

string System::getName() const
{
    return name;
}

void System::setName(string name)
{
    this->name = name;
}

System* System::operator=(const System* system)
{
    if (system == this)
        return this;

    name = system->name;
    value = system->value;

    return this;
}
