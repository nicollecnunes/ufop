#include <iostream>
#include "VUtilitario.h"
#include <string>

using namespace std;

int main(){
    VPasseio v1("Corolla", 300, 130, 3);
    v1.print();

    cout << "\nPeso-Potencia: " << v1.pesoPotencia() << endl;


    VUtilitario v2("PickUp", 400, 180, 400, 400);
    v2.print();

    cout << "\nPeso-Potencia: " << v2.pesoPotencia() << endl;
    return 0;
}