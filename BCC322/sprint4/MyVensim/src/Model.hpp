#ifndef MODEL_HPP
#define MODEL_HPP

#include "IModel.hpp"

//! Class Model
/**
* Está classe(concreta) representa o modelo geral da simulação, é nela que contém as estruturas necessárias para a simulação e sua execução.
*/
class Model : public IModel {
protected:
    double time; /*!< Esse atributo possui o tempo atual da simulação */
    list<IFlow *> flows; /*!< Esse atributo possui os fluxos(flows) da simulação */
    list<ISystem *> systems; /*!< Esse atributo possui os sistemas(system) da simulação */
private:
    /*!
        Operador de atribuição (=) sobrecarregado para a classe Model.
        Declarada como privada a fim de não permitir essa operação.
    */
    Model* operator=(const Model* model);

    /*!
        Esse é o construtor copia da classe Flow.
        Declarada como privada a fim de não permitir essa operação.
        \param model model para ser copiado
    */
    Model(const Model* model);
public:
    /*!
        Esse é o construtor padrão da classe Model
    */
    Model();

    /*!
        Esse é o destrutor padrão da classe Model
    */
    virtual ~Model();

    /*!
        Adiciona um fluxo ao Model
        \param flow ponteiro para o fluxo a ser adicionado ao modelo.
    */
    void add(IFlow * flow = NULL);

    /*!
        Adiciona um sistema ao Model
        \param system ponteiro para o sistema a ser adicionado ao modelo.
    */
    void add(ISystem * system = NULL);
    
    /*!
        Retorna um iterador apontando para o primeiro elemento no container de fluxos.
        \return list<Flow *>::iterator - iterator apontando para o inicio do container de fluxos.
    */
    iteratorFlow beginFlows();

    /*!
        Retorna um iterador apontando para o ultimo elemento no container de fluxos.
        \return list<Flow *>::iterator - iterator apontando para o fim do container de fluxos.
    */
    iteratorFlow endFlows();

    /*!
        Retorna um iterador apontando para o primeiro elemento no container de sistemas.
        \return list<Flow *>::iterator - iterator apontando para o inicio do container de sistemas.
    */
    iteratorSystem beginSystems();

    /*!
        Retorna um iterador apontando para o ultimo elemento no container de sistemas.
        \return list<Flow *>::iterator - iterator apontando para o fim do container de sistemas.
    */
    iteratorSystem endSystems();

    /*!
        Seta o valor do tempo inicial do range do modelo.
        \param initialTime - valor do tempo inicial.
    */
    void setTime(double time);
    
    /*!
        Retorna o valor do tempo atual da simulação no modelo.
        \return double - valor do tempo atual do modelo.
    */
    double getTime() const;

    /*!
        Seta o valor do tempo atual da simulação no modelo.
        \param increment valor a ser incrementado no tempo atual do modelo.
    */
    void incrementTime(double increment = 1);

    /*!
        Método que executa os sistemas dentro do modelo.
        \param start tempo inicial.
        \param end tempo final.
        \param increment unidade em que o tempo será incrementado.
    */
    void run(double start = 0, double end = 0, double increment = 0);
};

#endif
