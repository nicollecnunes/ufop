#include "unit_System.hpp"
#include<iostream>
#include<assert.h>
#include "../../src/include/SystemImpl.hpp"

void unit_System_constructor( void)
{
    cout << "[System] - Construtor padrao sem parametro: ";
    System *s1 = new SystemImpl();
    assert(s1->getValue() == 0);
    cout << "Ok!" << endl;

    cout << "[System] - Construtor com parametros iniciais: ";
    System *s2 = new SystemImpl("S2", 44);
    assert(s2->getName() == "S2");
    assert(s2->getValue() == 44);
    cout << "Ok!" << endl;

    cout << "[System] - Construtor de copia: ";
    System *s4 = new SystemImpl("S2", 44);
    System *s5 = new SystemImpl((SystemImpl *) s4);
    assert(s5->getValue() == s4->getValue());
    assert(s5->getName() == s4->getName());
    cout << "Ok!" << endl;
}

void unit_System_setName( void)
{
    cout << "[System] - Metodo setName() e getName(): ";
    System * s1 = new SystemImpl();
    s1->setName("S1");
    assert(s1->getName() == "S1");
    cout << "Ok!" << endl;
}

void unit_System_setValue(void)
{
    cout << "[System] - Metodo setValue() e getValue(): ";
    System *s1 = new SystemImpl();
    s1->setValue(44);
    assert(s1->getValue() == 44);
    cout << "Ok!" << endl;
}

void unit_System_assignmentOperator( void)
{
    cout << "[System] - Metodo da sobrecarga da atribuicao: ";
    System *s1 = new SystemImpl("Sistema original [S1]");
    s1->setValue(44);
    System *s2;
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

