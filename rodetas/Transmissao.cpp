// Autor: Nicolle Canuto Nunes - 2021

#include "Transmissao.h"
#include "Embedded.h"
#include "Estrategia.h"

#include <string>
#include <iomanip>
#include <iostream>

Transmissao :: Transmissao(string _mensagem): mensagem(_mensagem){}
Transmissao :: ~Transmissao(){}

string Transmissao :: tratarPwm(int _pwm){
    string pwm = to_string(_pwm);

    if (pwm.length() == 1)
        pwm = "00" + pwm;
    
    if (pwm.length() == 2)
        pwm = "0" + pwm;
    
    return pwm;
}

string Transmissao :: getMensagem() { return mensagem; }

void Transmissao :: setMensagem(int _pwm1, int _pwm2){
    string pwm1 = tratarPwm(_pwm1);
    string pwm2 = tratarPwm(_pwm2);

    mensagem = "[" + pwm1 + pwm2 + "]";
}

string Transmissao :: transmiteMensagem(int pwm1, int pwm2){
    setMensagem(pwm1, pwm2);
    return mensagem;
}