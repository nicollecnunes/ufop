// Autor: Nicolle Canuto Nunes - 2021

#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <string>
#include <iostream>

using namespace std;

class Estrategia
{
    int pwm1, pwm2;

    public:
    Estrategia(int = 0, int = 0);
    virtual ~Estrategia();  

    int getPwm1() const;
    int getPwm2() const;

    void setRandomPwms();
};

#endif