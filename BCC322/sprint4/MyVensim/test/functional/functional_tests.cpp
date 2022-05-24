#include "functional_tests.hpp"
#include <iostream>
#include <assert.h> 
#include <cmath>

#include "../../src/Model.hpp"
#include "../../src/System.hpp"
#include "../../src/Flow.hpp"

//Equações dos flows
//! Class FlowExponential
/**
* Está classe herda o Flow e implementa a execucao
*/
class FlowExponential : public Flow
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowExponential(string name): Flow(name){}

    /*!
        Esse método possui a equecao a ser executada pelo fluxo
    */
    double execute() const {
        return 0.01 * getSource()->getValue();
    }
};

//! Class FlowLogistic
/**
* Está classe herda o Flow e implementa a execucao
*/
class FlowLogistic : public Flow
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowLogistic(string name): Flow(name){}

    /*!
        Esse método possui a equecao a ser executada pelo fluxo
    */
    double execute() const {
        return 0.01 * getTarget()->getValue() * (1 - getTarget()->getValue() / 70);
    }
};

//! Class FlowComplexF
/**
* Está classe herda o Flow e implementa a execucao
*/
class FlowComplexF: public Flow
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowComplexF(string name): Flow(name){}

    /*!
        Esse método possui a equecao a ser executada pelo fluxo
    */
    double execute() const {
        return 0.01 * getSource()->getValue();
    }
};

//! Class FlowComplexG
/**
* Está classe herda o Flow e implementa a execucao
*/
class FlowComplexG: public Flow
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowComplexG(string name): Flow(name){}

    /*!
        Esse método possui a equecao a ser executada pelo fluxo
    */
    double execute() const {
        return 0.01 * getSource()->getValue();
    }
};

//! Class FlowComplexT
/**
* Está classe herda o Flow e implementa a execucao
*/
class FlowComplexT: public Flow
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowComplexT(string name): Flow(name){}

    /*!
        Esse método possui a equecao a ser executada pelo fluxo
    */
    double execute() const {
        return 0.01 * getSource()->getValue();
    }
};

//! Class FlowComplexR
/**
* Está classe herda o Flow e implementa a execucao
*/
class FlowComplexR: public Flow
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowComplexR(string name): Flow(name){}

    /*!
        Esse método possui a equecao a ser executada pelo fluxo
    */
    double execute() const {
        return 0.01 * getSource()->getValue();
    }
};

//! Class FlowComplexU
/**
* Está classe herda o Flow e implementa a execucao
*/
class FlowComplexU: public Flow
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowComplexU(string name): Flow(name){}

    /*!
        Esse método possui a equecao a ser executada pelo fluxo
    */
    double execute() const {
        return 0.01 * getSource()->getValue();
    }
};

//! Class FlowComplexV
/**
* Está classe herda o Flow e implementa a execucao
*/
class FlowComplexV: public Flow
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowComplexV(string name): Flow(name){}

    /*!
        Esse método possui a equecao a ser executada pelo fluxo
    */
    double execute() const {
        return 0.01 * getSource()->getValue();
    }
};

void exponentialFuncionalTest()
{
    IModel *m1 = new Model;
    ISystem *pop1 = new System("pop1", 100);
    ISystem *pop2 = new System("pop2", 0);
    IFlow *exponencial = new FlowExponential("exponencial");

    exponencial->connect(pop1, pop2);
    m1->add(pop1);
    m1->add(pop2);
    m1->add(exponencial);
    m1->run(0, 100, 1);

    cout << ">> ("<< pop1->getName() << ") "  << pop1->getValue() << endl;
    cout << ">> ("<< pop2->getName() << ") "  << pop2->getValue() << endl;

    assert(abs((pop1->getValue() - 36.6032)) < 0.0001);
    assert(abs((pop2->getValue() - 63.3968)) < 0.0001);

    cout << "Teste Exponencial [FINALIZADO]: Ok!" << endl;
}

void logisticalFuncionalTest()
{
    IModel *m1 = new Model;
    ISystem *p1 = new System("p1", 100);
    ISystem *p2 = new System("p2", 10);
    IFlow *logistic = new FlowLogistic("logistic");

    logistic->connect(p1, p2);
    m1->add(p1);
    m1->add(p2);
    m1->add(logistic);
    m1->run(0, 100, 1);

    cout << ">> ("<< p1->getName() << ") " << p1->getValue() << endl;
    cout << ">> ("<< p2->getName() << ") "  << p2->getValue() << endl;
    
    assert(abs((p1->getValue() - 88.2167)) < 0.0001);
    assert(abs((p2->getValue() - 21.7833)) < 0.0001);

    cout << "Teste Logistico [FINALIZADO]: Ok!" << endl;
}

void complexFuncionalTest()
{
    IModel *m1 = new Model;
    ISystem *q1 = new System("q1", 100);
    ISystem *q2 = new System("q2", 0);
    ISystem *q3 = new System("q3", 100);
    ISystem *q4 = new System("q4", 0);
    ISystem *q5 = new System("q5", 0);
    IFlow *f = new FlowComplexF("f");
    IFlow *g = new FlowComplexG("g");
    IFlow *t = new FlowComplexT("t");
    IFlow *r = new FlowComplexR("r");
    IFlow *u = new FlowComplexU("u");
    IFlow *v = new FlowComplexV("v");

    f->connect(q1, q2);
    g->connect(q1, q3);
    t->connect(q2, q3);
    r->connect(q2, q5);
    u->connect(q3, q4);
    v->connect(q4, q1);

    m1->add(q1);
    m1->add(q2);
    m1->add(q3);
    m1->add(q4);
    m1->add(q5);
    
    m1->add(f);
    m1->add(g);
    m1->add(t);
    m1->add(r);
    m1->add(u);
    m1->add(v);

    m1->run(0, 100, 1);

    cout << ">> ("<< q1->getName() << ") "  << q1->getValue() << endl;
    cout << ">> ("<< q1->getName() << ") "  << q2->getValue() << endl;
    cout << ">> ("<< q3->getName() << ") "  << q3->getValue() << endl;
    cout << ">> ("<< q3->getName() << ") "  << q4->getValue() << endl;
    cout << ">> ("<< q5->getName() << ") "  << q5->getValue() << endl;

    assert(abs((q1->getValue() - 31.8513)) < 0.0001);
    assert(abs((q2->getValue() - 18.4003)) < 0.0001);
    assert(abs((q3->getValue() - 77.1143)) < 0.0001);
    assert(abs((q4->getValue() - 56.1728)) < 0.0001);
    assert(abs((q5->getValue() - 16.4612)) < 0.0001);

    cout << "Teste Complexo [FINALIZADO]: Ok!" << endl;
}
