#include "Test.h"
#include <iostream>
#include <assert.h> 
#include <cmath>

#include "../src/Model.h"
#include "../src/System.h"
#include "../src/Flow.h"

class FlowExponential : public Flow{
public:
    FlowExponential(): Flow(){}

    double run(){
        return 0.01 * getNock()->getSystemValue();
    }
};

class FlowLogistic : public Flow{
public:
    FlowLogistic(): Flow(){}

    double run(){
        return 0.01 * getTarget()->getSystemValue() * (1 - getTarget()->getSystemValue() / 70);
    }
};

void exponentialFuncionalTest()
{
    cout << "Teste Exponencial [INICIADO]" << endl;
    
    Model *mExponencial = new Model;

    System *sPop1 = new System(100);
    System *sPop2 = new System(0);

    FlowExponential *fExponencial = new FlowExponential();
    fExponencial->setNock(sPop1);
    fExponencial->setTarget(sPop2);

    mExponencial->add(fExponencial);
    mExponencial->run(0, 100, 1);

    cout << "$ ("<< "sPop1" << ") "  << sPop1->getSystemValue() << endl;
    cout << "$ ("<< "sPop2" << ") "  << sPop2->getSystemValue() << endl;

    assert(abs((sPop1->getSystemValue() - 36.6032)) < 0.0001);
    assert(abs((sPop2->getSystemValue() - 63.3968)) < 0.0001); //epsilon
}

void logisticalFuncionalTest()
{
    cout << "Teste Logistico [INICIADO]" << endl;

    Model *mLogistica = new Model;

    System *sPop1 = new System(100);
    System *sPop2 = new System(10);

    FlowLogistic *fLogistica = new FlowLogistic();
    fLogistica->setNock(sPop1);
    fLogistica->setTarget(sPop2);

    mLogistica->add(fLogistica);
    mLogistica->run(0, 100, 1);

    cout << "$ ("<< "sPop1" << ") "  << sPop1->getSystemValue() << endl;
    cout << "$ ("<< "sPop2" << ") "  << sPop2->getSystemValue() << endl;
    
    assert(abs((sPop1->getSystemValue() - 88.2167)) < 0.0001);
    assert(abs((sPop2->getSystemValue() - 21.7833)) < 0.0001); //epsilon

}
