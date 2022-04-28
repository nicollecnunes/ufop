
/**
* @file unit_System.h
* @author Nicolle Nunes
* @date 28 April 2022
* @brief Arquivo header de testes unitários do sistema
**/

#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

#include <vector>
#include "string"

using namespace std;

class UnitSystem
{
    public:
        UnitSystem();
        UnitSystem(double value);

        void unit_setSystemValue(double v);
        double unit_getSystemValue() const;
};

#endif