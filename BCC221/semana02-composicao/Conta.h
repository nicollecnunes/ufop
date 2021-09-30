#ifndef CONTA_H
#define CONTA_H

#include<iostream>
#include"Cliente.h"
#include"Data.h"

using  namespace std;
class Conta{
    int numConta;
    double saldo;
    Cliente cliente;
    Data data;
    
    public:
        Conta(int,double,Cliente&,Data&);
        virtual ~Conta();
        bool depositar(double);
        bool saque(double);
        bool transferencia(Conta&,double);

        //gettersesetters
        void mostrarDados()const;

        void setNumConta(int);
        int getNumConta()const;

        void setSaldo(double);
        double getSaldo()const;

        void setCliente(Cliente&);
        Cliente getCliente()const;

        void setData(Data&);
        Data getData()const;
};
#endif