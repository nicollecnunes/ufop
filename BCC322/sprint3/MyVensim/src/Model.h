
/**
* @file System.h
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo header da entidade que define o Modelo
**/

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
class Model {
    private:
     /*!
            Esse é o construtor copia da classe Model.
            \param model model para ser copiado
        */
        Model(const Model &model);
    protected:
        double time = 0; /*!< Tempo atual da simulação */
        list<Flow *> listFlow; /*!< Lista de fluxos do modelo */
        list<System *> listSystem; /*!< Lista de sistemas do modelo */

         /*!
            Operador de atribuição (=) sobrecarregado para a classe Model.
        */
        Model* operator=(const Model* m);
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
        void run(double s = 0, double e = 0, double i = 0);

         /*!
            Adiciona um fluxo ao Model
            \param flow ponteiro para o fluxo a ser adicionado ao modelo.
        */
        void add(Flow *f = NULL);

        /*!
            Adiciona um sistema ao Model
            \param system ponteiro para o sistema a ser adicionado ao modelo.
        */
        void add(System *s = NULL);

        Model* operator=(const Model* s);
};

#endif