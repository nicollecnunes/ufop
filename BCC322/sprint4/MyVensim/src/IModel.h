#ifndef IMODEL_H
#define IMODEL_H

#include <list>
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
        list<IFlow *> listFlow; /*!< Lista de fluxos do modelo */
        list<ISystem *> listSystem; /*!< Lista de sistemas do modelo */

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
        virtual void addToModel(IFlow *flow = NULL) = 0;

        /*!
            Adiciona um sistema ao IModel
            \param system ponteiro para o sistema a ser adicionado ao modelo.
        */
        virtual void addToModel(ISystem *system = NULL) = 0;

        virtual double getTime() = 0;
};

#endif