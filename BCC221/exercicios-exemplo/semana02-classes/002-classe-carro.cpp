#include <iostream>
using namespace std;

class Carro{
    // antes do public e tudo privado
    int velocidade;
    string placa;
    public:
    // metodos publicos sem retorno

    //construtor
    Carro()
    {
        placa = "";
        velocidade = 0;  
    }

    Carro(string _placa, int _velocidade)
    {
        placa = _placa;
        velocidade = _velocidade; 
    }

    void acelerar()
    {
        velocidade = velocidade + 10;
    }

    void freiar()
    {
        velocidade = velocidade - 10;
    }

    void set(string _placa, int _velocidade)
    {
        placa = _placa;
        velocidade = _velocidade;
    }
    
    void mostrarVelocidade()
    {
        cout << "O carro " << placa << " esta a " << velocidade << "Km/h \n";
    }
};

int main()
{
    Carro c1;
    c1.set("ABC123", 50);
    c1.mostrarVelocidade();
    c1.acelerar();
    c1.mostrarVelocidade();

    return 0;
}