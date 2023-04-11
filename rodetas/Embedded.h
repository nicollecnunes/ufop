// Autor: Nicolle Canuto Nunes - 2021

#ifndef EMBEDDED_H
#define EMBEDDED_H

#include <string>
#include <cstring>

using namespace std;

class Embedded
{
    int pwm1, pwm2;

    public:
    Embedded(int = 0, int = 0);
    virtual ~Embedded();  

    int getPwm1() const;
    int getPwm2() const;

    void setPwm1(int);
    void setPwm2(int);

    string executaPwm(string);
};

#endif