#ifndef MODEL_H
#define MODEL_H

#include "IModel.h"

#include <vector>
#include <cstddef>
using namespace std;


//! Class Model
/**
* Representa o modelo geral da simulação, contém as estruturas necessárias para a simulação e sua execução.
*/
class Model    : public IModel
{
    protected:
        double time = 0; /*!< Tempo atual da simulação */

    private:
        /*!
            Operador de atribuição (=) sobrecarregado para a classe Model.
        */
        Model* operator=(const Model* m);

        /*!
            Esse é o construtor copia da classe Model.
            \param model model para ser copiado
        */
    Model(const Model* model);

    public:
        typedef vector<ISystem *>::iterator systemIterator;
        typedef vector<IFlow *>::iterator flowIterator;

        systemIterator beginSystems();
        systemIterator endSystems(); 
        flowIterator beginFlows(); 
        flowIterator endFlows();

        vector<IFlow *> listFlow; /*!< Lista de fluxos do modelo */
        vector<ISystem *> listSystem; /*!< Lista de sistemas do modelo */
        /*!
            Construtor padrão da classe Model
        */
        Model();

        /*!
        Destrutor padrão da classe Model
        */
        virtual ~Model();


        /*!
            Executa as simulações dentro do modelo.
            \param start tempo inicial.
            \param end tempo final.
            \param increment unidade em que o tempo será incrementado.
        */
        void run(double start = 0, double end = 0, double increment = 0);

         /*!
            Adiciona um fluxo ao Model
            \param flow ponteiro para o fluxo a ser adicionado ao modelo.
        */
        void add(IFlow *flow = NULL);

        /*!
            Adiciona um sistema ao Model
            \param system ponteiro para o sistema a ser adicionado ao modelo.
        */
        void add(ISystem *system = NULL);

        double getTime();
};

#endif