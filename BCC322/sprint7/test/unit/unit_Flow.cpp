#include "unit_Flow.hpp"
#include <iostream>
#include <assert.h>
#include "./utils/mem_usage.hpp"
#include "../../src/include/SystemImpl.hpp"
#include "./utils/FlowTestUnit.hpp"

void unit_Flow_constructor( void)
{
    cout << "[Flow] - Construtor padrao sem parametro: ";
    Flow * f1 = new FlowHandle<FlowTestUnit>();
    assert(f1->getSource() == NULL);
    assert(f1->getTarget() == NULL);
    cout << "Ok!" << endl;

    cout << "[Flow] - Construtor com parametro de nome: ";
    Flow *f2 = new FlowHandle<FlowTestUnit>("f2");
    assert(f2->getSource() == NULL);
    assert(f2->getTarget() == NULL);
    cout << "Ok!" << endl;
    
    // cout << "[Flow] - Construtor de copia: ";
    // Flow *f3 = new FlowHandle<FlowTestUnit>("f3");
    // Flow *f4 = new FlowHandle<FlowTestUnit>(f3);
    // assert(f4->getName() == f3->getName());

    delete f1;
    delete f2;

    cout << "Ok!" << endl;
}

void unit_Flow_destructor( void)
{
    cout << "[Flow] - Destrutor padrao: ";
    double memoryBefore, memoryAfter, rss;

    mem_usage(memoryBefore, rss);

    Flow * f1 = new FlowHandle<FlowTestUnit>("Flow");
    delete f1;

    mem_usage(memoryAfter, rss);

    //assert(memoryBefore == memoryAfter);
    cout << "Ok!" << endl;
}

void unit_Flow_setCurrentValue( void)
{
    cout << "[Flow] - Metodo setCurrentValue() e getCurrentValue(): ";
    Flow * f1 = new FlowHandle<FlowTestUnit>();
    f1->setCurrentValue(4.4);
    assert(f1->getCurrentValue() == 4.4);
    cout << "Ok!" << endl;

    delete f1;
}

void unit_Flow_setName( void)
{
    cout << "[Flow] - Metodo setName() e getName() : ";
    Flow * f1 = new FlowHandle<FlowTestUnit>();
    f1->setName("fluxo 1");
    assert(f1->getName() == "fluxo 1");
    cout << "Ok!" << endl;

    delete f1;
}

void unit_Flow_setSource( void)
{
    cout << "[Flow] - Metodo setSource() e getSource(): ";
    Flow * f1 = new FlowHandle<FlowTestUnit>();
    System *s1 = new SystemHandle("System 1", 100);
    f1->setSource(s1);
    assert(f1->getSource() == s1);
    cout << "Ok!" << endl;

    delete f1;
    delete s1;
}

void unit_Flow_setTarget( void)
{
    cout << "[Flow] - Metodo setTarget() e getTarget(): ";
    Flow * f1 = new FlowHandle<FlowTestUnit>();
    System *s1 = new SystemHandle("System 1", 100);
    f1->setTarget(s1);
    assert(f1->getTarget() == s1);
    cout << "Ok!" << endl;

    delete f1;
    delete s1;
}

void unit_Flow_connect( void)
{
    cout << "[Flow] - Metodo connect: ";
    Flow * f1 = new FlowHandle<FlowTestUnit>();
    System *s1 = new SystemHandle("System 1", 100);
    System *s2 = new SystemHandle("System 2", 0);
    f1->connect(s1, s2);
    assert(f1->getSource() == s1);
    assert(f1->getTarget() == s2);
    cout << "Ok!" << endl;

    delete f1;
    delete s1;
    delete s2;

}

void unit_Flow_execute( void ) 
{
    cout << "[Flow] - Metodo execute: ";
    Flow * f1 = new FlowHandle<FlowTestUnit>();
    System *s1 = new SystemHandle("System 1", 100);
    f1->setSource(s1);
    assert(f1->execute() == 10);
    cout << "Ok!" << endl;

    delete f1;
    delete s1;
}

void unit_Flow_assignmentOperator(void)
{
    cout << "[Flow] - Metodo da sobrecarga da atribuicao: ";
    Flow * f1 = new FlowHandle<FlowTestUnit>("Flow 1 [Original]");
    Flow *f2;
    f2 = f1;

    assert(f2->getName() == f1->getName());

    cout << "Ok!" << endl;

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
