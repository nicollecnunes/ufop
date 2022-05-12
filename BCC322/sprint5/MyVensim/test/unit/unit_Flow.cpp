#include "unit_Flow.h"
#include "../../src/Flow.h"
#include "../../src/System.h"

#include <iostream>
#include <assert.h>
#include <cassert>

void unit_Flow_constructor(void)
{
    cout << " -> Construtor Padrao";

    IFlow *f1 = new FlowTest();

    assert(f1->getOrigin() == NULL);
    assert(f1->getTarget() == NULL);
    cout << ":  OK" << endl;
}

void unit_Flow_setOrigin_getOrigin(void)
{
    cout << " -> Metodos GET e SET de Origin";

    IFlow *f1 = new FlowTest();
    ISystem *s1 = new System(100);
    f1->setOrigin(s1);

    assert(f1->getOrigin() == s1);
    cout << ":  OK" << endl;
}

void unit_Flow_setTarget_getTarget(void)
{
    cout << " -> Metodos GET e SET de Target";

    IFlow *f1 = new FlowTest();
    ISystem *s1 = new System(100);
    f1->setTarget(s1);

    assert(f1->getTarget() == s1);
    cout << ":  OK" << endl;
}

void unit_Flow_setValue_getValue(void)
{
    cout << " -> Metodos GET e SET de Value";

    IFlow *f1 = new FlowTest();
    f1->setValue(55);

    assert(f1->getValue() == 55);
    cout << ":  OK" << endl;
}

void unit_Flow_run(void)
{
    cout << " -> Metodo run";

    IFlow *f1 = new FlowTest();
    ISystem *s1 = new System(100);
    f1->setOrigin(s1);
    f1->run();

    assert(f1->run() == 1);
    cout << ":  OK" << endl;
}


void unit_Flow_assignmentOperator(void)
{
    cout << " -> Sobrecarga do Operador (=)";

    IFlow *f1 = new FlowTest();
    ISystem *s1 = new System(100);
    f1->setOrigin(s1);

    IFlow *f2 = new FlowTest();
    f2 = f1;

    assert(f1->getOrigin() == f2->getOrigin());
    cout << ":  OK" << endl;   
}

void run_unit_tests_Flow(void)
{
    cout << "========= TESTES UNITARIOS   : FLOW =========" << endl;
    unit_Flow_constructor();

    unit_Flow_setOrigin_getOrigin();
    unit_Flow_setTarget_getTarget();
    unit_Flow_setValue_getValue();

    unit_Flow_run();
    
    unit_Flow_assignmentOperator();

    cout << endl;
}
