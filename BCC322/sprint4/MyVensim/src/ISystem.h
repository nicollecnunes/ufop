
/**
* @file ISystem.h
* @author Nicolle Nunes
* @date 28 April 2022
* @brief Interface do sistema
**/

#ifndef ISYSTEM_H
#define ISYSTEM_H

#include <vector>
#include "string"

using namespace std;

class ISystem
{
    public:
        virtual ~ISystem();

        virtual void setSystemValue(double v) = 0;
        virtual double getSystemValue() const = 0;
};

#endif