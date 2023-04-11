// Autor: Nicolle Canuto Nunes - 2021

#include "Estrategia.h"
#include "Transmissao.h"
#include "Embedded.h"

using namespace std;

int main(){
    Estrategia e;
    Transmissao t;
    Embedded v;

    // a main fica responsável por enviar a informação entre as duas
    e.setRandomPwms();
    cout << t.transmiteMensagem(e.getPwm1(), e.getPwm2());

    cout << v.executaPwm(t.getMensagem());
    

    return 0;
}