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