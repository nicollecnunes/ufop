#ifndef MODEL_HPP
#define MODEL_HPP

#include <list>
using namespace std;

class Flow;
class System;

//! Class Model
/**
* Representa o modelo geral da simulação, contém as estruturas necessárias para a simulação e sua execução.
*/
class Model
{
    protected:
        double time = 0; /*!< Tempo atual da simulação */
        list<Flow *> listFlow; /*!< Lista de fluxos do modelo */
        list<System *> listSystem; /*!< Lista de sistemas do modelo */

    private:
        /*!
            Operador de atribuição (=) sobrecarregado para a classe Model.
        */
        Model* operator=(const Model* m);

        /*!
            Esse é o construtor copia da classe Flow.
            \param model model para ser copiado
        */
    Model(const Model* model);

    public:
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
        void add(Flow *flow = NULL);

        /*!
            Adiciona um sistema ao Model
            \param system ponteiro para o sistema a ser adicionado ao modelo.
        */
        void add(System *system = NULL);
};

#endif