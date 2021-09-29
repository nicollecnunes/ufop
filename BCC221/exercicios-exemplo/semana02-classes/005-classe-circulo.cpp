#include <iostream>
using namespace std;

class Circulo
{
    int raio, x, y;

    public:
    Circulo(int _raio)
    {
        setRaio(_raio);
    }

    Circulo(int _x, int _y)
    {
        setCentro(_x, _y);
    }

    Circulo(){}

    void setCentro(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    void setRaio(int _raio)
    {
        raio = _raio;
    }

    int getRaio()
    {
        return raio;
    }

    void deslocarCentro(int deltaX, int deltaY)
    {
        x = x + deltaX;
        y = y + deltaY;
    }

    void mostrarInformacoes()
    {
        cout << "Raio: " << raio << "\n";
        cout << "Centro: (" << x << "," << y << ")" << "\n";
    }

};

int main(){

    Circulo c1;
    c1.setCentro(0, 0);
    c1.setRaio(5);

    c1.mostrarInformacoes();
    c1.deslocarCentro(5,5);
    c1.mostrarInformacoes();
    

    return 0;
}