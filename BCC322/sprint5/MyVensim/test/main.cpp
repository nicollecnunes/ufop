#include "functional/functional_tests.h"

#include "unit/unit_System.H"
#include "unit/unit_Flow.H"
#include "unit/unit_Model.H"

int main(){
    run_exponentialFuncionalTest();
    run_logisticalFuncionalTest();
    run_complexFuncionalTest();

    run_unit_tests_System();
    run_unit_tests_Flow();
    run_unit_tests_Model();

    return true;
}
