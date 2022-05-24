#include "functional_tests.hpp"
#include <iostream>
#include <assert.h> 
#include <cmath>

#include "../../src/include/Model.hpp"
#include "../../src/include/System.hpp"

//Equações dos flows
//! Class FlowExponential
/**
* Está classe herda o Flow e implementa a execucao
*/
class FlowExponential : public FlowBody
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowExponential(string name = "", System *s = NULL, System *t = NULL): FlowBody(name, s, t){};

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
class FlowLogistic : public FlowBody
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowLogistic(string name = "", System *s = NULL, System *t = NULL): FlowBody(name, s, t){};
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
class FlowComplexF: public FlowBody
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowComplexF(string name = "", System *s = NULL, System *t = NULL): FlowBody(name, s, t){};

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
class FlowComplexG: public FlowBody
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowComplexG(string name = "", System *s = NULL, System *t = NULL): FlowBody(name, s, t){};

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
class FlowComplexT: public FlowBody
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowComplexT(string name = "", System *s = NULL, System *t = NULL): FlowBody(name, s, t){};

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
class FlowComplexR: public FlowBody
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowComplexR(string name = "", System *s = NULL, System *t = NULL): FlowBody(name, s, t){};

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
class FlowComplexU: public FlowBody
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowComplexU(string name = "", System *s = NULL, System *t = NULL): FlowBody(name, s, t){};

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
class FlowComplexV: public FlowBody
{
public:
    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name nome do fluxo.
    */
    FlowComplexV(string name = "", System *s = NULL, System *t = NULL): FlowBody(name, s, t){};

    /*!
        Esse método possui a equecao a ser executada pelo fluxo
    */
    double execute() const {
        return 0.01 * getSource()->getValue();
    }
};

void exponentialFuncionalTest()
{
    cout << "Teste Exponencial [INICIADO]" << endl;

    Model *exponentialModel = Model::createModel("Exponential Model");
    System *pop1 = exponentialModel->createSystem("pop1", 100);
    System *pop2 = exponentialModel->createSystem("pop2", 0);
    Flow *exponencial = exponentialModel->createFlow<FlowExponential>("exponencial", pop1, pop2);

    assert(pop1->getName() == "pop1");
    assert(pop2->getName() == "pop2");
    assert(exponencial->getName() == "exponencial");
    assert(exponentialModel->getName() == "Exponential Model");

    exponentialModel->run(0, 100, 1);

    cout << "$ ("<< pop1->getName() << ") "  << pop1->getValue() << endl;
    cout << "$ ("<< pop2->getName() << ") "  << pop2->getValue() << endl;

    assert(abs((pop1->getValue() - 36.6032)) < 0.0001);
    assert(abs((pop2->getValue() - 63.3968)) < 0.0001);
    assert(abs((exponentialModel->getTime() - 100.0)) < 0.0001);

    cout << "Teste Exponencial [FINALIZADO]: passed" << endl;
}

void logisticalFuncionalTest()
{
    cout << "Teste Logistico [INICIADO]" << endl;

    Model *logisticalModel = Model::createModel("Logistic Model");
    System *p1 = logisticalModel->createSystem("p1", 100);
    System *p2 = logisticalModel->createSystem("p2", 10);
    Flow *logistic = logisticalModel->createFlow<FlowLogistic>("logistic", p1, p2);

    assert(p1->getName() == "p1");
    assert(p2->getName() == "p2");
    assert(logistic->getName() == "logistic");
    assert(logisticalModel->getName() == "Logistic Model");

    logisticalModel->run(0, 100, 1);

    cout << "$ ("<< p1->getName() << ") " << p1->getValue() << endl;
    cout << "$ ("<< p2->getName() << ") "  << p2->getValue() << endl;
    
    assert(abs((p1->getValue() - 88.2167)) < 0.0001);
    assert(abs((p2->getValue() - 21.7833)) < 0.0001);
    assert(abs((logisticalModel->getTime() - 100.0)) < 0.0001);

    cout << "Teste Logistico [FINALIZADO]: passed" << endl;
}

void complexFuncionalTest()
{
    cout << "Teste Complexo [INICIADO]" << endl;

    Model *complexModel = Model::createModel("Complex Model");
    System *q1 = complexModel->createSystem("q1", 100);
    System *q2 = complexModel->createSystem("q2", 0);
    System *q3 = complexModel->createSystem("q3", 100);
    System *q4 = complexModel->createSystem("q4", 0);
    System *q5 = complexModel->createSystem("q5", 0);

    Flow *f = complexModel->createFlow<FlowComplexF>("f", q1, q2);
    Flow *g = complexModel->createFlow<FlowComplexG>("g", q1, q3);
    Flow *t = complexModel->createFlow<FlowComplexT>("t", q2, q3);
    Flow *r = complexModel->createFlow<FlowComplexR>("r", q2, q5);
    Flow *u = complexModel->createFlow<FlowComplexU>("u", q3, q4);
    Flow *v = complexModel->createFlow<FlowComplexV>("v", q4, q1);

    assert(q1->getName() == "q1");
    assert(q2->getName() == "q2");
    assert(q3->getName() == "q3");
    assert(q4->getName() == "q4");
    assert(q5->getName() == "q5");
    assert(f->getName() == "f");
    assert(g->getName() == "g");
    assert(t->getName() == "t");
    assert(r->getName() == "r");
    assert(u->getName() == "u");
    assert(v->getName() == "v");
    assert(complexModel->getName() == "Complex Model");

    complexModel->run(0, 100, 1);

    cout << "$ ("<< q1->getName() << ") "  << q1->getValue() << endl;
    cout << "$ ("<< q1->getName() << ") "  << q2->getValue() << endl;
    cout << "$ ("<< q3->getName() << ") "  << q3->getValue() << endl;
    cout << "$ ("<< q3->getName() << ") "  << q4->getValue() << endl;
    cout << "$ ("<< q5->getName() << ") "  << q5->getValue() << endl;

    assert(abs((q1->getValue() - 31.8513)) < 0.0001);
    assert(abs((q2->getValue() - 18.4003)) < 0.0001);
    assert(abs((q3->getValue() - 77.1143)) < 0.0001);
    assert(abs((q4->getValue() - 56.1728)) < 0.0001);
    assert(abs((q5->getValue() - 16.4612)) < 0.0001);
    assert(abs((complexModel->getTime() - 100.0)) < 0.0001);

    cout << "Teste Complexo [FINALIZADO]: passed" << endl;
}
