#ifndef IMODEL_H
#define IMODEL_H

#include <vector>
using namespace std;

class Flow;
class System;

//! Class Model
/**
* Representa o modelo geral da simulação, contém as estruturas necessárias para a simulação e sua execução.
*/
class Model
{
    public:
        vector<Flow *> listFlow; /*!< Lista de fluxos do modelo */
        vector<System *> listSystem; /*!< Lista de sistemas do modelo */

        typedef vector<System*>::iterator systemIterator;
        typedef vector<Flow*>::iterator flowIterator;
        
        virtual systemIterator beginSystems() = 0;
        virtual systemIterator endSystems() = 0; 
        virtual flowIterator beginFlows() = 0; 
        virtual flowIterator endFlows() = 0;

        /*!
        Destrutor padrão da classe Model
        */
        virtual ~Model(){};


        /*!
            Executa as simulações dentro do modelo.
            \param start tempo inicial.
            \param end tempo final.
            \param increment unidade em que o tempo será incrementado.
        */
        virtual void run(double start = 0, double end = 0, double increment = 0) = 0;

         /*!
            Adiciona um fluxo ao Model
            \param flow ponteiro para o fluxo a ser adicionado ao modelo.
        */
        virtual void add(Flow *flow = NULL) = 0;

        /*!
            Adiciona um sistema ao Model
            \param system ponteiro para o sistema a ser adicionado ao modelo.
        */
        virtual void add(System *system = NULL) = 0;

        virtual double getTime() = 0;
};

#endif