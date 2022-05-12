
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
    private:
        System(const System &system);
    protected:
        double value;
    public:
        System();
        System(double value);
        virtual ~System();

        void setValue(double v);
        double getValue() const;

        System* operator=(const System* s);
};

#endif