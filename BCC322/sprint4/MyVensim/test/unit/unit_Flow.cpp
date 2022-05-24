#include "unit_Flow.hpp"
#include <iostream>
#include <assert.h>
#include "../../src/Flow.hpp"
#include "../../src/System.hpp"
#include "./utils/FlowTestUnit.hpp"

void unit_Flow_constructor( void)
{
    cout << "Construtor padrao sem parametro: ";
    IFlow * f1 = new FlowTestUnit();
    assert(f1->getSource() == NULL);
    assert(f1->getTarget() == NULL);
    cout << "Ok!" << endl;

    cout << "Construtor com parametro de nome: ";
    IFlow *f2 = new FlowTestUnit("f2");
    assert(f2->getSource() == NULL);
    assert(f2->getTarget() == NULL);
    cout << "Ok!" << endl;
    
    cout << "Construtor de copia: ";
    IFlow *f3 = new FlowTestUnit("f3");
    IFlow *f4 = new FlowTestUnit((FlowTestUnit *) f3);
    assert(f4->getName() == f3->getName());
    cout << "Ok!" << endl;
}

void unit_Flow_setCurrentValue( void)
{
    cout << "setCurrentValue() e getCurrentValue(): ";
    IFlow * f1 = new FlowTestUnit();
    f1->setCurrentValue(4.4);
    assert(f1->getCurrentValue() == 4.4);
    cout << "Ok!" << endl;
}

void unit_Flow_setName( void)
{
    cout << "setName() e getName() : ";
    IFlow * f1 = new FlowTestUnit();
    f1->setName("fluxo 1");
    assert(f1->getName() == "fluxo 1");
    cout << "Ok!" << endl;
}

void unit_Flow_setSource( void)
{
    cout << "setSource() e getSource(): ";
    IFlow * f1 = new FlowTestUnit();
    ISystem *s1 = new System("System 1", 100);
    f1->setSource(s1);
    assert(f1->getSource() == s1);
    cout << "Ok!" << endl;
}

void unit_Flow_setTarget( void)
{
    cout << "setTarget() e getTarget(): ";
    IFlow * f1 = new FlowTestUnit();
    ISystem *s1 = new System("System 1", 100);
    f1->setTarget(s1);
    assert(f1->getTarget() == s1);
    cout << "Ok!" << endl;
}

void unit_Flow_connect( void)
{
    cout << "connect: ";
    IFlow * f1 = new FlowTestUnit();
    ISystem *s1 = new System("System 1", 100);
    ISystem *s2 = new System("System 2", 0);
    f1->connect(s1, s2);
    assert(f1->getSource() == s1);
    assert(f1->getTarget() == s2);
    cout << "Ok!" << endl;

}

void unit_Flow_execute( void ) 
{
    cout << "execute: ";
    IFlow * f1 = new FlowTestUnit();
    ISystem *s1 = new System("System 1", 100);
    f1->setSource(s1);
    assert(f1->execute() == 10);
    cout << "Ok!" << endl;
}

void unit_Flow_assignmentOperator(void)
{
    cout << "da sobrecarga da atribuicao: ";
    IFlow * f1 = new FlowTestUnit("Flow 1 [Original]");
    IFlow *f2 = new FlowTestUnit();
    f2 = f1;

    assert(f2->getName() == f1->getName());

    cout << "Ok!" << endl;
}

void run_unit_tests_Flow( void )
{
    unit_Flow_constructor();
    unit_Flow_setCurrentValue();
    unit_Flow_setName();
    unit_Flow_setSource();
    unit_Flow_setTarget();
    unit_Flow_connect();
    unit_Flow_execute();
    unit_Flow_assignmentOperator();
}
