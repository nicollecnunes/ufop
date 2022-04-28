/**
* @file TestU.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Testes Unitários
**/


#include <iostream>
#include <cstdlib>
#include <assert.h>

#include "TestU.h" 

#include "FlowClasses.h"
#include "../src/System.h"
#include "../src/Flow.h"
#include "../src/Model.h"

void exponentialUnitTest()
{
    cout << "========= FLUXO EXPONENCIAL =========" << endl;

    Model *mExponencial = new Model;

    System *sPop1 = new System(100);
    System *sPop2 = new System(0);

    FlowExponential *fExponencial = new FlowExponential();
    fExponencial->setNock(sPop1);
    fExponencial->setTarget(sPop2);
    mExponencial->add(fExponencial);

    assert(abs(sPop1->getSystemValue() - 100.0) < 0.0001);
    assert(abs(sPop2->getSystemValue() - 0.0) < 0.0001);

    cout << "Valores iniciais de sistema OK" << endl;

    mExponencial->run(0, 100, 1);

    assert(abs((sPop1->getSystemValue() - 36.6032)) < 0.0001);
    assert(abs((sPop2->getSystemValue() - 63.3968)) < 0.0001);

    cout << "Valores finais de sistema OK" << endl;
}

void logisticalUnitTest()
{

    cout << "========= FLUXO LOGISTICO =========" << endl;

    Model *mLogistica = new Model;

    System *sPop1 = new System(100);
    System *sPop2 = new System(10);

    FlowLogistic *fLogistica = new FlowLogistic();
    fLogistica->setNock(sPop1);
    fLogistica->setTarget(sPop2);
    mLogistica->add(fLogistica);

    assert(abs(sPop1->getSystemValue() - 100.0) < 0.0001);
    assert(abs(sPop2->getSystemValue() - 10.0) < 0.0001);

    cout << "Valores iniciais de sistema OK" << endl;

    mLogistica->run(0, 100, 1);
    
    assert(abs((sPop1->getSystemValue() - 88.2167)) < 0.0001);
    assert(abs((sPop2->getSystemValue() - 21.7833)) < 0.0001);

    cout << "Valores finais de sistema OK" << endl;
}

void complexUnitTest()
{
    cout << "========= FLUXO COMPLEXO =========" << endl;

    Model *mComplexo = new Model;

    System *sQ1 = new System(100);
    System *sQ2 = new System(0);
    System *sQ3 = new System(100);
    System *sQ4 = new System(0);
    System *sQ5 = new System(0);

    FlowComplex *fF = new FlowComplex();
    fF->setNock(sQ1);
    fF->setTarget(sQ2);
    mComplexo->add(fF);

    FlowComplex *fG = new FlowComplex();
    fG->setNock(sQ1);
    fG->setTarget(sQ3);
    mComplexo->add(fG);

    FlowComplex *fT = new FlowComplex();
    fT->setNock(sQ2);
    fT->setTarget(sQ3);
    mComplexo->add(fT);

    FlowComplex *fR = new FlowComplex();
    fR->setNock(sQ2);
    fR->setTarget(sQ5);
    mComplexo->add(fR);

    FlowComplex *fU = new FlowComplex();
    fU->setNock(sQ3);
    fU->setTarget(sQ4);
    mComplexo->add(fU);

    FlowComplex *fV = new FlowComplex();
    fV->setNock(sQ4);
    fV->setTarget(sQ1);
    mComplexo->add(fV);

    assert(abs(sQ1->getSystemValue() - 100.0) < 0.0001);
    assert(abs(sQ2->getSystemValue() - 0.0) < 0.0001);
    assert(abs(sQ3->getSystemValue() - 100.0) < 0.0001);
    assert(abs(sQ4->getSystemValue() - 0.0) < 0.0001);
    assert(abs(sQ5->getSystemValue() - 0.0) < 0.0001);

    cout << "Valores iniciais de sistema OK" << endl;

    mComplexo->run(0, 100, 1);

    assert(abs((sQ1->getSystemValue() - 31.8513)) < 0.0001);
    assert(abs((sQ2->getSystemValue() - 18.4003)) < 0.0001);
    assert(abs((sQ3->getSystemValue() - 77.1143)) < 0.0001);
    assert(abs((sQ4->getSystemValue() - 56.1728)) < 0.0001);
    assert(abs((sQ5->getSystemValue() - 16.4612)) < 0.0001);

    cout << "Valores finais de sistema OK" << endl;
    
}