/**
* @file TestF.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Testes Funcionais
**/

#include <iostream>
#include <assert.h> 
#include <cmath>

#include "FlowClasses.h"
#include "TestF.h"
#include "../src/Model.h"
#include "../src/System.h"
#include "../src/Flow.h"

void exponentialFuncionalTest()
{
    cout << "========= FLUXO EXPONENCIAL =========" << endl;
    
    Model *mExponencial = new Model;

    System *sPop1 = new System(100);
    System *sPop2 = new System(0);

    FlowExponential *fExponencial = new FlowExponential();
    fExponencial->setNock(sPop1);
    fExponencial->setTarget(sPop2);
    mExponencial->add(fExponencial);

    mExponencial->run(0, 100, 1);

    cout << ">> "<< "[sPop1] = " << sPop1->getSystemValue() << endl;
    cout << ">> "<< "[sPop2] = " << sPop2->getSystemValue() << endl;

    assert(abs((sPop1->getSystemValue() - 36.6032)) < 0.0001);
    assert(abs((sPop2->getSystemValue() - 63.3968)) < 0.0001);

    cout << "Resultado final OK\n" << endl;

}

void logisticalFuncionalTest()
{
    cout << "========= FLUXO LOGISTICO =========" << endl;

    Model *mLogistica = new Model;

    System *sPop1 = new System(100);
    System *sPop2 = new System(10);

    FlowLogistic *fLogistica = new FlowLogistic();
    fLogistica->setNock(sPop1);
    fLogistica->setTarget(sPop2);
    mLogistica->add(fLogistica);

    mLogistica->run(0, 100, 1);

    cout << ">> "<< "[sPop1] = " << sPop1->getSystemValue() << endl;
    cout << ">> "<< "[sPop2] = " << sPop2->getSystemValue() << endl;
    
    assert(abs((sPop1->getSystemValue() - 88.2167)) < 0.0001);
    assert(abs((sPop2->getSystemValue() - 21.7833)) < 0.0001);

    cout << "Resultado final OK\n" << endl;
}

void complexFuncionalTest(){
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

    mComplexo->run(0, 100, 1);

    cout << ">> "<< "[sQ1] = " << sQ1->getSystemValue() << endl;
    cout << ">> "<< "[sQ1] = " << sQ2->getSystemValue() << endl;
    cout << ">> "<< "[sQ3] = " << sQ3->getSystemValue() << endl;
    cout << ">> "<< "[sQ3] = " << sQ4->getSystemValue() << endl;
    cout << ">> "<< "[sQ5] = " << sQ5->getSystemValue() << endl;

    assert(abs((sQ1->getSystemValue() - 31.8513)) < 0.0001);
    assert(abs((sQ2->getSystemValue() - 18.4003)) < 0.0001);
    assert(abs((sQ3->getSystemValue() - 77.1143)) < 0.0001);
    assert(abs((sQ4->getSystemValue() - 56.1728)) < 0.0001);
    assert(abs((sQ5->getSystemValue() - 16.4612)) < 0.0001);

    cout << "Resultado final OK\n" << endl;
}
