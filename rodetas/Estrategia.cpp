// Autor: Nicolle Canuto Nunes - 2021

#include "Estrategia.h"
#include <string>
#include <cstdlib>
#include <ctime>

Estrategia :: Estrategia(int _pwm1, int _pwm2):
    pwm1(_pwm1), pwm2(_pwm2) {}

Estrategia :: ~Estrategia(){}

int Estrategia :: getPwm1() const { return pwm1; }
int Estrategia :: getPwm2() const { return pwm2; }

void Estrategia :: setRandomPwms() {
    unsigned seed = time(0);
    srand(seed);

    pwm1 = rand()%256;
    pwm2 = rand()%256;
}

