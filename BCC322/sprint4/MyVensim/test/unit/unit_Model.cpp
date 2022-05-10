#include "../../src/Model.h"
#include "../../src/Flow.h"
#include "../../src/System.h"
#include "unit_Flow.h"

#include <iostream>
#include <cstddef>
#include <assert.h>
#include <vector>


using namespace std;

typedef vector<ISystem *>::iterator systemIterator;
typedef vector<IFlow *>::iterator flowIterator;

void unit_Model_constructor(void)
{
    cout << " -> Construtor Padrao";

    IModel *m1 = new Model();
    assert(m1->getTime() == 0);

    cout << ":  OK" << endl;  
}

void unit_Model_addFlow(void)
{
    cout << " -> Metodo add(*Flow)";

    IModel *m1 = new Model();
    IFlow *f1 = new FlowTest();
    ISystem *s1 = new System(20);

    f1->setOrigin(s1);
    m1->add(f1);

    assert((*(m1->beginFlows()))->getOrigin()->getValue() == f1->getOrigin()->getValue());

    cout << ":  OK" << endl;
}

void unit_Model_addSystem(void)
{
    cout << " -> Metodo add(*System)";

    IModel *m1 = new Model();
    ISystem *s1 = new System(20);
    m1->add(s1);

    assert((*(m1->beginSystems()))->getValue() == s1->getValue());

    cout << ":  OK" << endl;
}

void unit_Model_run(void)
{
    cout << " -> Metodo run";

    IModel *m1 = new Model();
    ISystem *s1 = new System(100);
    IFlow *f1 = new FlowTest();

    f1->setOrigin(s1);
    m1->add(f1);
    m1->add(s1);
    m1->run(0,1,4);

    assert(f1->getValue() == 1);
    assert(s1->getValue() == 99);

    cout << ":  OK" << endl;
}

void run_unit_tests_Model(void)
{
    cout << "========= TESTES UNITARIOS   : MODEL =========" << endl;
    unit_Model_constructor();
    unit_Model_addFlow();
    unit_Model_addSystem();
    unit_Model_run();

    cout << endl;
}
