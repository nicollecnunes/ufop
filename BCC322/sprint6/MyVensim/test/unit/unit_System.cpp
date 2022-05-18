#include "unit_System.h"
#include "../../src/ISystem.h"

#include <iostream>
#include <assert.h>

#include "../../src/System.h"

void unit_System_constructor(void)
{
    cout << " -> Construtor Padrao";

    ISystem *s1 = new System();

    assert(s1->getValue() == 0);
    cout << ":  OK" << endl;

    cout << " -> Construtor Com Parametro de valor";

    ISystem *s2 = new System(42);
    assert(s2->getValue() == 42);
    cout << ":  OK" << endl;

    delete s1;
    delete s2;
}

void unit_System_setValue_getValue(void)
{
    cout << " -> Metodos GET e SET de System";

    ISystem *s1 = new System();
    s1->setValue(9999);
    assert(s1->getValue() == 9999);
    cout << ":  OK" << endl;

    delete s1;
}

void run_unit_tests_System(void)
{
    cout << "========= TESTES UNITARIOS   : SYSTEM =========" << endl;
    unit_System_constructor();
    unit_System_setValue_getValue();
    cout << endl;

    delete s1;
}
