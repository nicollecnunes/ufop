#include "TestF.h"

#include <iostream>

using namespace std;

int main(){
    int sair;

    cout << "FUNCTIONAL TESTS\n";
    cout << "==============================================\n\n";

    run_exponentialFuncionalTest();
    run_logisticalFuncionalTest();
    run_complexFuncionalTest();

    cout << "Pressione 0 para sair" << endl;
    cin >> sair;

    return true;
}