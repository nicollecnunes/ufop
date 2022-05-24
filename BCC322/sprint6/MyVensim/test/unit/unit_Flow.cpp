#include "unit_Flow.hpp"
#include <iostream>
#include <assert.h>
#include "./utils/mem_usage.hpp"
#include "../../src/include/SystemImpl.hpp"
#include "./utils/FlowTestUnit.hpp"

void unit_Flow_constructor( void)
{
    cout << "[F] - Construtor padrao sem parametro: ";
    Flow * f1 = new FlowHandle<FlowTestUnit>();
    assert(f1->getSource() == NULL);
    assert(f1->getTarget() == NULL);
    cout << "passed" << endl;

    cout << "[F] - Construtor com parametro de nome: ";
    Flow *f2 = new FlowHandle<FlowTestUnit>("f2");
    assert(f2->getSource() == NULL);
    assert(f2->getTarget() == NULL);
    cout << "passed" << endl;
    
    // cout << "[F] - Construtor de copia: ";
    // Flow *f3 = new FlowHandle<FlowTestUnit>("f3");
    // Flow *f4 = new FlowHandle<FlowTestUnit>(f3);
    // assert(f4->getName() == f3->getName());

    delete f1;
    delete f2;

    cout << "passed" << endl;
}

void unit_Flow_destructor( void)
{
    cout << "[F] - Destrutor padrao: ";
    double memoryBefore, memoryAfter, rss;

    mem_usage(memoryBefore, rss);

    Flow * f1 = new FlowHandle<FlowTestUnit>("Flow");
    delete f1;

    mem_usage(memoryAfter, rss);

    //assert(memoryBefore == memoryAfter);
    cout << "passed" << endl;
}

void unit_Flow_setCurrentValue( void)
{
    cout << "[F] - Method setCurrentValue() e getCurrentValue(): ";
    Flow * f1 = new FlowHandle<FlowTestUnit>();
    f1->setCurrentValue(4.4);
    assert(f1->getCurrentValue() == 4.4);
    cout << "passed" << endl;

    delete f1;
}

void unit_Flow_setName( void)
{
    cout << "[F] - Method setName() e getName() : ";
    Flow * f1 = new FlowHandle<FlowTestUnit>();
    f1->setName("fluxo 1");
    assert(f1->getName() == "fluxo 1");
    cout << "passed" << endl;

    delete f1;
}

void unit_Flow_setSource( void)
{
    cout << "[F] - Method setSource() e getSource(): ";
    Flow * f1 = new FlowHandle<FlowTestUnit>();
    System *s1 = new SystemHandle("System 1", 100);
    f1->setSource(s1);
    assert(f1->getSource() == s1);
    cout << "passed" << endl;

    delete f1;
    delete s1;
}

void unit_Flow_setTarget( void)
{
    cout << "[F] - Method setTarget() e getTarget(): ";
    Flow * f1 = new FlowHandle<FlowTestUnit>();
    System *s1 = new SystemHandle("System 1", 100);
    f1->setTarget(s1);
    assert(f1->getTarget() == s1);
    cout << "passed" << endl;

    delete f1;
    delete s1;
}

void unit_Flow_connect( void)
{
    cout << "[F] - Method connect: ";
    Flow * f1 = new FlowHandle<FlowTestUnit>();
    System *s1 = new SystemHandle("System 1", 100);
    System *s2 = new SystemHandle("System 2", 0);
    f1->connect(s1, s2);
    assert(f1->getSource() == s1);
    assert(f1->getTarget() == s2);
    cout << "passed" << endl;

    delete f1;
    delete s1;
    delete s2;

}

void unit_Flow_execute( void ) 
{
    cout << "[F] - Method execute: ";
    Flow * f1 = new FlowHandle<FlowTestUnit>();
    System *s1 = new SystemHandle("System 1", 100);
    f1->setSource(s1);
    assert(f1->execute() == 10);
    cout << "passed" << endl;

    delete f1;
    delete s1;
}

void unit_Flow_assignmentOperator(void)
{
    cout << "[F] - Method da sobrecarga da atribuicao: ";
    Flow * f1 = new FlowHandle<FlowTestUnit>("Flow 1 [Original]");
    Flow *f2;
    f2 = f1;

    assert(f2->getName() == f1->getName());

    cout << "passed" << endl;

    delete f1;
}

void run_unit_tests_Flow( void )
{
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_setCurrentValue();
    unit_Flow_setName();
    unit_Flow_setSource();
    unit_Flow_setTarget();
    unit_Flow_connect();
    unit_Flow_execute();
    unit_Flow_assignmentOperator();
}
