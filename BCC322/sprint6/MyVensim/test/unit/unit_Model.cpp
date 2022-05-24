#include "unit_Model.hpp"
#include <iostream>
#include <assert.h>
#include "./utils/mem_usage.hpp"
#include "./utils/FlowTestUnit.hpp"

#include "../../src/include/Model.hpp"
#include "../../src/include/System.hpp"

void unit_Model_constructor( void)
{
    cout << "[M] - Construtor padrao sem parametro: ";
    Model *m1 = Model::createModel("Model M1");
    assert(m1->getTime() == 0);
    assert(m1->getName() == "Model M1");
    cout << "passed" << endl;

    delete m1;
}

void unit_Model_destructor( void)
{
    cout << "[M] - Destrutor padrao: ";
    double memoryBefore, memoryAfter, rss;

    mem_usage(memoryBefore, rss);

    Model* m1 = Model::createModel("Model M1");
    delete m1;

    mem_usage(memoryAfter, rss);

    assert(memoryBefore == memoryAfter);
    cout << "passed" << endl;
}

void unit_Model_setTime( void)
{
    cout << "[M] - Method setTime() e getTime(): ";
    Model *m1 = Model::createModel("Model M1");
    m1->setTime(10);
    assert(m1->getTime() == 10);
    cout << "passed" << endl;

    delete m1;
}

void unit_Model_incrementTime( void)
{
    cout << "[M] - Method incrementTime() e getTime(): ";
    Model *m1 = Model::createModel("Model M1");
    m1->incrementTime(10);
    m1->incrementTime(10);
    assert(m1->getTime() == 20);
    cout << "passed" << endl;

    delete m1;
}

void unit_Model_add(void)
{
    cout << "[M] - Method add() [F]: ";
    Model *m1 = Model::createModel("Model M1");
    Flow *f1 = m1->createFlow<FlowTestUnit>("F1");
    auto itFlow = m1->beginFlows();
    assert((*itFlow) == f1);
    cout << "passed" << endl;

    cout << "[M] - Method add() [S]: ";
    Model *m2 = Model::createModel("Model M1");
    System *s1 = m1->createSystem("S1");
    auto itSystem = m1->beginSystems();
    assert((*itSystem) == s1);
    cout << "passed" << endl;

    delete m1;
    delete f1;
    delete m2;
    delete s1;
}

void unit_Model_iteratorFlows(void)
{
    Model *m1 = Model::createModel("Model M1");

    cout << "[M] - Method beginFlows() [F]: ";
    Flow *f1 = m1->createFlow<FlowTestUnit>("F1");
    auto itFlowBegin = m1->beginFlows();
    assert((*itFlowBegin) == f1);
    cout << "passed" << endl;

    cout << "[M] - Method endFlows() [F]: ";
    auto itFlowEnd = m1->endFlows();
    assert((*itFlowEnd) != (*itFlowBegin));
    cout << "passed" << endl;

    delete m1;
    delete f1;
}

void unit_Model_iteratorSystems(void)
{
    Model *m1 = Model::createModel("Model M1");

    cout << "[M] - Method beginSystems() [F]: ";
    System *s1 = m1->createSystem("S1");
    auto itSystemBegin = m1->beginSystems();
    assert((*itSystemBegin) == s1);
    cout << "passed" << endl;

    cout << "[M] - Method endSystems() [S]: ";
    auto itSystemEnd = m1->endSystems();
    assert((*itSystemEnd) != (*itSystemBegin));
    cout << "passed" << endl;

    delete m1;
    delete s1;
}

void unit_Model_run( void )
{
    cout << "[M] - Method run(): ";
    Model *m1 = Model::createModel("Model M1");
    System *s1 = m1->createSystem("S1", 100);
    Flow *f1 = m1->createFlow<FlowTestUnit>("F1", s1);
    m1->run(0, 1, 4);
    assert(m1->getTime() == 4);
    assert(f1->getCurrentValue() == 10);
    assert(s1->getValue() == 90);
    cout << "passed" << endl;

    delete m1;
    delete s1;
    delete f1;
}

void run_unit_tests_Model( void )
{
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_setTime();
    unit_Model_incrementTime();
    unit_Model_add();
    unit_Model_iteratorFlows();
    unit_Model_iteratorSystems();
    unit_Model_run();
}
