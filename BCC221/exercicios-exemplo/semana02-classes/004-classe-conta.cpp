#include <iostream>
using namespace std;

class Conta{
    int numConta;
    double saldo;
    Cliente correntista;
    Data dataCriacao;
    
    public:
    // metodos publicos
    int getSaldo() { return saldo; }
    void setSaldo(int _saldo)
    { 
        if (saldo < 200)
        {
            cout << "Não foi possível iniciar a conta";
            return;
        }
        else
        {
            saldo = _saldo;
        }
    }

    bool depositar(double valor)
    {
        if (valor > 0)
        {
            setSaldo(getSaldo() + valor);
            return true;
        }
        else
        {
            return false;
        }    
    }

    bool sacar(double valor)
    {
        if ((valor > getSaldo()) && (valor < 0))
        {
            return false;
        }
        else
        {
            setSaldo(getSaldo() - valor);
            return true;
        }    
    }

    bool transferir(Conta contaDestino, double valor)
    {
        if (sacar(valor))
        {
            contaDestino.depositar(valor);
            return true;
        }
        else
        {
            return false;      
        }
    }

    void mostrarDados()
    {
        
    }
};

class Cliente{
    string nome, endereco, cpf;
};

class Data{
    int dia, mes, ano;
};

int main()
{

    return 0;
}