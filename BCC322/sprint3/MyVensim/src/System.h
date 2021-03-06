
/**
* @file System.h
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo header da entidade que define o sistema
**/

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include "string"

using namespace std;

//! Class System
/**
* Representa o sistema/estoque da simulação.
*/
class System
{
    private:
    /*!
            Construtor copia da classe System.
            \param system sistema para ser copiado
        */
        System(const System &system);
    protected:
        double value; /*!< Valor atual armazenado no sistema */
    public:
        /*!
            Construtor padrão da classe System.
        */
        System();



        /*!
            Construtor com atributo de valor inicial.
            \param value valor inicial do sistema.
        */
        System(double value);



        /*!
            Destrutor padrão
        */
        virtual ~System();


        v /*!
            Define o valor armazenado pelo sistema
            \param value valor a ser armazenado
        */
        void setValue(double value);


         /*!
            Retorna o valor atual do sistema
            \return double valor armazenado
        */
        double getValue() const;

        /*!
            Operador de atribuição (=) sobrecarregado para a classe System.
        */
        System* operator=(const System* system);
};

#endif