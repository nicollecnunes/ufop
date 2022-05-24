#ifndef IMODEL_HPP
#define IMODEL_HPP

#include <list>

using namespace std;

class IFlow;
class ISystem;

//! Class Model
/**
* Está classe representa a interface do modelo geral da simulação, é nela que contém as estruturas necessárias para a simulação e sua execução.
*/
class IModel {
public:
    typedef list<IFlow *>::iterator iteratorFlow;  /*!< Iterador da lista de fluxo do modelo */
    typedef list<ISystem *>::iterator iteratorSystem;  /*!< Iterador da lista de sistemas do modelo */

    /*!
        Esse é o destrutor padrão da classe Model
    */
    virtual ~IModel(){};

    /*!
        Adiciona um fluxo ao Model
        \param flow ponteiro para o fluxo a ser adicionado ao modelo.
    */
    virtual void add(IFlow * flow = NULL) = 0;


    /*!
        Adiciona um sistema ao Model
        \param system ponteiro para o sistema a ser adicionado ao modelo.
    */
    virtual void add(ISystem * system = NULL) = 0;
    
    /*!
        Retorna um iterador apontando para o primeiro elemento no container de fluxos.
        \return list<Flow *>::iterator - iterator apontando para o inicio do container de fluxos.
    */
    virtual iteratorFlow beginFlows() = 0;

    /*!
        Retorna um iterador apontando para o ultimo elemento no container de fluxos.
        \return list<Flow *>::iterator - iterator apontando para o fim do container de fluxos.
    */
    virtual iteratorFlow endFlows() = 0;

    /*!
        Retorna um iterador apontando para o primeiro elemento no container de sistemas.
        \return list<Flow *>::iterator - iterator apontando para o inicio do container de sistemas.
    */
    virtual iteratorSystem beginSystems() = 0;

    /*!
        Retorna um iterador apontando para o ultimo elemento no container de sistemas.
        \return list<Flow *>::iterator - iterator apontando para o fim do container de sistemas.
    */
    virtual iteratorSystem endSystems() = 0;

    /*!
        Seta o valor do tempo inicial do range do modelo.
        \param initialTime - valor do tempo inicial.
    */
    virtual void setTime(double time) = 0;
    
    /*!
        Retorna o valor do tempo atual da simulação no modelo.
        \return double - valor do tempo atual do modelo.
    */
    virtual double getTime() const = 0;

    /*!
        Seta o valor do tempo atual da simulação no modelo.
        \param increment valor a ser incrementado no tempo atual do modelo.
    */
    virtual void incrementTime(double increment = 1) = 0;

    /*!
        Método que executa os sistemas dentro do modelo.
        \param start tempo inicial.
        \param end tempo final.
        \param increment unidade em que o tempo será incrementado.
    */
    virtual void run(double start = 0, double end = 0, double increment = 0) = 0;
};

#endif
