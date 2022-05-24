#include "unit/unit_System.hpp"
#include "unit/unit_Flow.hpp"
#include "unit/unit_Model.hpp"
#include "functional/functional_tests.hpp"

#include <iostream>

using namespace std;

int main(){
    cout << "===== SYSTEM =====" << endl;
    run_unit_tests_System();
    cout << endl;

    cout << endl << "===== FLOW =====" << endl;
    run_unit_tests_Flow();
    cout << endl;

    cout << endl << "===== MODEL =====" << endl;
    run_unit_tests_Model();
    cout << endl;

    cout << endl << "===== EXPONENTIAL =====" << endl;
    exponentialFuncionalTest();
    cout << endl;

    cout << endl << "===== LOGISTICAL =====" << endl;
    logisticalFuncionalTest();
    cout << endl;

    cout << endl << "===== COMPLEX =====" << endl;
    complexFuncionalTest();
    cout << endl;
    
    return true;
}