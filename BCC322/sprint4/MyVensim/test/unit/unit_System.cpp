#include "unit_System.hpp"
#include<iostream>
#include<assert.h>
#include "../../src/System.hpp"

void unit_System_constructor( void)
{
    cout << "Construtor padrao sem parametro: ";
    ISystem *s1 = new System();
    assert(s1->getValue() == 0);
    cout << "Ok!" << endl;

    cout << "Construtor com parametro de nome: ";
    ISystem *s2 = new System("S2");
    assert(s2->getValue() == 0);
    assert(s2->getName() == "S2");
    cout << "Ok!" << endl;

    cout << "Construtor com parametro de nome e valor: ";
    ISystem *s3 = new System("S2", 44);
    assert(s3->getValue() == 44);
    assert(s3->getName() == "S2");
    cout << "Ok!" << endl;

    cout << "Construtor de copia: ";
    System *s4 = new System("S2", 44);
    System *s5 = new System(s4);
    assert(s5->getValue() == s4->getValue());
    assert(s5->getName() == s4->getName());
    cout << "Ok!" << endl;
}

void unit_System_setName( void)
{
    cout << "setName() e getName(): ";
    ISystem * s1 = new System();
    s1->setName("S1");
    assert(s1->getName() == "S1");
    cout << "Ok!" << endl;
}

void unit_System_setValue(void)
{
    cout << "setValue() e getValue(): ";
    ISystem *s1 = new System();
    s1->setValue(44);
    assert(s1->getValue() == 44);
    cout << "Ok!" << endl;
}

void unit_System_assignmentOperator( void)
{
    cout << "da sobrecarga da atribuicao: ";
    ISystem *s1 = new System("Sistema original [S1]");
    s1->setValue(44);
    ISystem *s2;
    s2 = s1;

    assert(s2->getName() == s1->getName());
    assert(s2->getValue() == s1->getValue());
    
    cout << "Ok!" << endl;
}

void run_unit_tests_System( void )
{
    unit_System_constructor();
    unit_System_setName();
    unit_System_setValue();
    unit_System_assignmentOperator();
}

