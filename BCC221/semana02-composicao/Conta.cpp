#include "Conta.h"

Conta::Conta(int numConta,double saldo, Cliente& cliente, Data& data):
    numConta(numConta), saldo(saldo), cliente(cliente), data(data){}

Conta:: ~Conta(){}

bool Conta:: depositar(double valor)
{
    if(valor>0){
        saldo+=valor;
        return true;
    }
    return false;
}

bool Conta::saque(double valor)
{
    if(saldo>valor && valor>0){
        saldo -= valor;
        return true;
    }
    return false;
}

bool Conta::transferencia(Conta& destino,double valor)
{
    if(saque(valor)){
        destino.depositar(valor);
        return true;
    }
    return false;
}

void Conta::mostrarDados()const{
    cout<< "\nnome:" << cliente.getNome() <<"saldo:"<<getSaldo();
}

void Conta::setNumConta(int num) {numConta=num;}
int Conta::getNumConta()const{ return numConta;}

void Conta::setSaldo(double _saldo){saldo=_saldo;}
double Conta::getSaldo()const{ return saldo; }

void Conta::setCliente(Cliente& _cliente){cliente=_cliente;}
Cliente Conta::getCliente()const{ return cliente;}

void Conta::setData(Data& _data){data=_data;}
Data Conta::getData()const{return data;}
