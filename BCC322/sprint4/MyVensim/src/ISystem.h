#ifndef ISYSTEM_H
#define ISYSTEM_H

/**
* @file ISystem.h
* @author Nicolle Nunes
* @date 29 April 2022
* @brief Arquivo header da entidade que define o sistema
**/

#include "string"

using namespace std;

//! Class ISystem
/**
* Representa o sistema/estoque da simulação.
*/
class ISystem
{
    public:
        /*!
            Destrutor padrão da classe ISystem.
        */
        virtual ~ISystem(){};


        /*!
            Define o valor armazenado pelo sistema
            \param value valor a ser armazenado
        */
        virtual void setSystemValue(double value) = 0;


         /*!
            Retorna o valor atual do sistema
            \return double valor armazenado
        */
        virtual double getSystemValue() const = 0;



};

#endif