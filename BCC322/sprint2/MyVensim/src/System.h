
/**
* @file System.h
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo header da entidade que define o sistema
**/

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include "string"

using namespace std;

class System
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