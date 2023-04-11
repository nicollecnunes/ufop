// Autor: Nicolle Canuto Nunes - 2021

#include "Embedded.h"

#include <string>
#include <cstring>
#include <iostream>

Embedded :: Embedded(int _pwm1, int _pwm2):
    pwm1(_pwm1), pwm2(_pwm2) {}

Embedded :: ~Embedded(){}

int Embedded :: getPwm1() const { return pwm1; }
int Embedded :: getPwm2() const { return pwm2; }


void Embedded :: setPwm1(int _pwm1) {
    pwm1 = _pwm1;
}
void Embedded :: setPwm2(int _pwm2) {
    pwm2 = _pwm2;
}

string Embedded :: executaPwm(string mensagem){
    string pwm1, pwm2;

    pwm1 = mensagem.substr(1,3);
    pwm2 = mensagem.substr(4,3);

    return "\nPWM1: " + pwm1 + " | PWM2: " + pwm2;
}