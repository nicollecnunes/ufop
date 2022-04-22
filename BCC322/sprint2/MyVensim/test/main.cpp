#include "TestF.h"
#include "TestU.h"

#include <iostream>

using namespace std;

int main(){

    cout << "INICIANDO TESTES FUNCIONAIS\n";
    cout << "==============================================\n\n";

    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();

    cout << "FINALIZANDO TESTES FUNCIONAIS\n";
    cout << "==============================================\n\n";

    cout << "\n\nINICIANDO TESTES UNITARIOS\n";
    cout << "==============================================\n\n";

    exponentialUnitTest();
    logisticalUnitTest();
    complexUnitTest();

    cout << "\nFINALIZANDO TESTES UNITARIOS\n";
    cout << "==============================================\n\n";

    return true;
}