
/**
* @file System.h
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo header da entidade que define o sistema
**/

#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "string"
#include "ISystem.h"

using namespace std;

class System : public ISystem
{
    protected:
        double value;
    public:
        System();
        System(double value);
        virtual ~System();

        void setSystemValue(double v);
        double getSystemValue() const;

        System* operator=(const System* s);
};

#endif