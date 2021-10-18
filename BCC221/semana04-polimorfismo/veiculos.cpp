#include <iostream>
using namespace std;


class Veiculo{
    public:

    virtual void verificarLista(){
        cout << "\nVerifica Veiculo";
    }

    virtual void reparar(){
        cout << "\nRepara Veiculo";
    }

    virtual void limpar(){
        cout << "\nLimpa Veiculo";
    }

};

class Moto : public Veiculo{
    public:
    void verificarLista(){
        cout << "\nVerifica Moto";
    }

    void reparar(){
        cout << "\nRepara Moto";
    }

    void limpar(){
        cout << "\nLimpa Moto";
    }
};

class Automovel : public Veiculo{
    public:
    void verificarLista(){
        cout << "\nVerifica Automovel";
    }

    void reparar(){
        cout << "\nRepara Automovel";
    }

    void limpar(){
        cout << "\nLimpa Automovel";
    }
};

class Oficina{
    int R;
public:
    Veiculo *pProx();
    void manter(Veiculo *v);
    int getR();
};

Veiculo *Oficina :: pProx(){
    Veiculo *v;
    R = rand();

    if(R % 2 == 0)
        v = new Automovel();
    else
        v = new Moto();
    return v;
}

void Oficina :: manter(Veiculo *v){
    v->verificarLista();
    v->reparar();
    v->limpar();
}

int Oficina :: getR(){
    return R;
}

int main(){
    Oficina Of;
    Veiculo *pV;

    int n = 0;

    while (n < 6){
        pV = Of.pProx();
        cout << endl << Of.getR()<<endl;
        Of.manter(pV);
        n++;
        delete pV;
    }
    return 0;
}