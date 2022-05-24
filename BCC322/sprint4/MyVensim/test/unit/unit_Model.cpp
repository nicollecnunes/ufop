#include "unit_Model.hpp"
#include <iostream>
#include <assert.h>
#include "../../src/Model.hpp"
#include "../../src/Flow.hpp"
#include "../../src/System.hpp"
#include "./utils/FlowTestUnit.hpp"

void unit_Model_constructor( void)
{
    cout << "Construtor padrao sem parametro: ";
    IModel *m1 = new Model();
    assert(m1->getTime() == 0);
    cout << "Ok!" << endl;
}

void unit_Model_setTime( void)
{
    cout << "setTime() e getTime(): ";
    IModel *m1 = new Model();
    m1->setTime(10);
    assert(m1->getTime() == 10);
    cout << "Ok!" << endl;
}

void unit_Model_incrementTime( void)
{
    cout << "incrementTime() e getTime(): ";
    IModel *m1 = new Model();
    m1->incrementTime(10);
    m1->incrementTime(10);
    assert(m1->getTime() == 20);
    cout << "Ok!" << endl;
}

void unit_Model_add(void)
{
    cout << "add() [flow]: ";
    IModel *m1 = new Model();
    IFlow *f1 = new FlowTestUnit("F1");
    m1->add(f1);
    auto itFlow = m1->beginFlows();
    assert((*itFlow) == f1);
    cout << "Ok!" << endl;

    cout << "add() [system]: ";
    IModel *m2 = new Model();
    ISystem *s1 = new System("S1");
    m1->add(s1);
    auto itSystem = m1->beginSystems();
    assert((*itSystem) == s1);
    cout << "Ok!" << endl;
}

void unit_Model_iteratorFlows(void)
{
    IModel *m1 = new Model();

    cout << "beginFlows() [flow]: ";
    IFlow *f1 = new FlowTestUnit("F1");
    m1->add(f1);
    auto itFlowBegin = m1->beginFlows();
    assert((*itFlowBegin) == f1);
    cout << "Ok!" << endl;

    cout << "endFlows() [flow]: ";
    auto itFlowEnd = m1->endFlows();
    assert((*itFlowEnd) != (*itFlowBegin));
    cout << "Ok!" << endl;
}

void unit_Model_iteratorSystems(void)
{
    IModel *m1 = new Model();

    cout << "beginSystems() [flow]: ";
    ISystem *s1 = new System("F1");
    m1->add(s1);
    auto itSystemBegin = m1->beginSystems();
    assert((*itSystemBegin) == s1);
    cout << "Ok!" << endl;

    cout << "endSystems() [system]: ";
    auto itSystemEnd = m1->endSystems();
    assert((*itSystemEnd) != (*itSystemBegin));
    cout << "Ok!" << endl;
}

void unit_Model_run( void )
{
    cout << "run(): ";
    IModel *m1 = new Model();
    IFlow *f1 = new FlowTestUnit("F1");
    ISystem *s1 = new System("F1", 100);
    f1->setSource(s1);
    m1->add(f1);
    m1->add(s1);
    m1->run(0, 1, 4);
    assert(m1->getTime() == 4);
    assert(f1->getCurrentValue() == 10);
    assert(s1->getValue() == 90);
    cout << "Ok!" << endl;
}

void run_unit_tests_Model( void )
{
    unit_Model_constructor();
    unit_Model_setTime();
    unit_Model_incrementTime();
    unit_Model_add();
    unit_Model_iteratorFlows();
    unit_Model_iteratorSystems();
    unit_Model_run();
}
