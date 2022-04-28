#include "TestF.h"
#include "TestU.h"

#include <iostream>

using namespace std;

int main(){
    int sair;

    cout << "INICIANDO TESTES FUNCIONAIS\n";
    cout << "==============================================\n\n";

    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();

    cout << "\nINICIANDO TESTES UNITARIOS\n";
    cout << "==============================================\n\n";

    exponentialUnitTest();
    logisticalUnitTest();
    complexUnitTest();

    cout << "\nFINALIZANDO TESTES UNITARIOS\n";
    cout << "==============================================\n\n";

    cout << "Pressione 0 para sair" << endl;
    cin >> sair;

    return true;
}