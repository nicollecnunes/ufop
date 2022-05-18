/**
* @file functional_tests.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Testes Funcionais
**/
#include "functional_tests.h"

#include <iostream>
#include <assert.h> 
#include <cmath>

#include "../functional/FlowClasses.h"
#include "../../src/Model.h"
#include "../../src/System.h"
#include "../../src/Flow.h"



void run_exponentialFuncionalTest()
{
    cout << "========= FLUXO EXPONENCIAL =========" << endl;
    
    IModel *mExponencial = new Model();

    ISystem *sPop1 = new System(100);
    ISystem *sPop2 = new System();

    IFlow *fExponencial = new FlowExponential();

    fExponencial->setOrigin(sPop1);
    fExponencial->setTarget(sPop2);

    mExponencial->add(sPop1);
    mExponencial->add(sPop2);
    mExponencial->add(fExponencial);

    mExponencial->run(0, 100, 1);
    cout << "linha 41" << endl;
    cout << sPop1->getValue() << endl;
    cout << " -> "<< "[sPop1] = " << sPop1->getValue() << endl;
    cout << " -> "<< "[sPop2] = " << sPop2->getValue() << endl;

    assert(abs((sPop1->getValue() - 36.6032)) < 0.0001);
    assert(abs((sPop2->getValue() - 63.3968)) < 0.0001);

    cout << "Resultado final OK\n" << endl;

}

void run_logisticalFuncionalTest()
{
    cout << "========= FLUXO LOGISTICO =========" << endl;

    IModel *mLogistica = new Model();

    ISystem *sPop1 = new System(100);
    ISystem *sPop2 = new System(10);

    IFlow *fLogistica = new FlowLogistic();
    fLogistica->setOrigin(sPop1);
    fLogistica->setTarget(sPop2);

    mLogistica->add(sPop1);
    mLogistica->add(sPop2);
    mLogistica->add(fLogistica);

    mLogistica->run(0, 100, 1);

    cout << " -> "<< "[sPop1] = " << sPop1->getValue() << endl;
    cout << " -> "<< "[sPop2] = " << sPop2->getValue() << endl;
    
    assert(abs((sPop1->getValue() - 88.2167)) < 0.0001);
    assert(abs((sPop2->getValue() - 21.7833)) < 0.0001);

    cout << "Resultado final OK\n" << endl;
}

void run_complexFuncionalTest(){
   cout << "========= FLUXO COMPLEXO =========" << endl;

    IModel *mComplexo = new Model();

    ISystem *sQ1 = new System(100);
    mComplexo->add(sQ1);

    ISystem *sQ2 = new System();
    mComplexo->add(sQ2);

    ISystem *sQ3 = new System(100);
    mComplexo->add(sQ3);

    ISystem *sQ4 = new System();
    mComplexo->add(sQ4);

    ISystem *sQ5 = new System();
    mComplexo->add(sQ5);

    IFlow *fF = new FlowComplex();
    fF->setOrigin(sQ1);
    fF->setTarget(sQ2);
    mComplexo->add(fF);

    IFlow *fG = new FlowComplex();
    fG->setOrigin(sQ1);
    fG->setTarget(sQ3);
    mComplexo->add(fG);

    IFlow *fT = new FlowComplex();
    fT->setOrigin(sQ2);
    fT->setTarget(sQ3);
    mComplexo->add(fT);

    IFlow *fR = new FlowComplex();
    fR->setOrigin(sQ2);
    fR->setTarget(sQ5);
    mComplexo->add(fR);

    IFlow *fU = new FlowComplex();
    fU->setOrigin(sQ3);
    fU->setTarget(sQ4);
    mComplexo->add(fU);

    IFlow *fV = new FlowComplex();
    fV->setOrigin(sQ4);
    fV->setTarget(sQ1);
    mComplexo->add(fV);

    mComplexo->run(0, 100, 1);

    cout << " -> "<< "[sQ1] = " << sQ1->getValue() << endl;
    cout << " -> "<< "[sQ1] = " << sQ2->getValue() << endl;
    cout << " -> "<< "[sQ3] = " << sQ3->getValue() << endl;
    cout << " -> "<< "[sQ4] = " << sQ4->getValue() << endl;
    cout << " -> "<< "[sQ5] = " << sQ5->getValue() << endl;

    assert(abs((sQ1->getValue() - 31.8513)) < 0.0001);
    assert(abs((sQ2->getValue() - 18.4003)) < 0.0001);
    assert(abs((sQ3->getValue() - 77.1143)) < 0.0001);
    assert(abs((sQ4->getValue() - 56.1728)) < 0.0001);
    assert(abs((sQ5->getValue() - 16.4612)) < 0.0001);

    cout << "Resultado final OK\n" << endl;
}
