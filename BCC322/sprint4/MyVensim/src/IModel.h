#ifndef IMODEL_H
#define IMODEL_H

#include <vector>
using namespace std;

class IFlow;
class ISystem;

//! Class IModel
/**
* Representa o modelo geral da simulação, contém as estruturas necessárias para a simulação e sua execução.
*/
class IModel
{
    public:
        vector<IFlow *> listFlow; /*!< Lista de fluxos do modelo */
        vector<ISystem *> listSystem; /*!< Lista de sistemas do modelo */

        typedef vector<ISystem*>::iterator systemIterator;
        typedef vector<IFlow*>::iterator flowIterator;
        
        virtual systemIterator beginSystems() = 0;
        virtual systemIterator endSystems() = 0; 
        virtual flowIterator beginFlows() = 0; 
        virtual flowIterator endFlows() = 0;

        /*!
        Destrutor padrão da classe IModel
        */
        virtual ~IModel(){};


        /*!
            Executa as simulações dentro do modelo.
            \param start tempo inicial.
            \param end tempo final.
            \param increment unidade em que o tempo será incrementado.
        */
        virtual void run(double start = 0, double end = 0, double increment = 0) = 0;

         /*!
            Adiciona um fluxo ao IModel
            \param flow ponteiro para o fluxo a ser adicionado ao modelo.
        */
        virtual void add(IFlow *flow = NULL) = 0;

        /*!
            Adiciona um sistema ao IModel
            \param system ponteiro para o sistema a ser adicionado ao modelo.
        */
        virtual void add(ISystem *system = NULL) = 0;

        virtual double getTime() = 0;
};

#endif