#include <iostream>
using namespace std;

class Retangulo{
    // antes do public e tudo privado
    int base, altura;
    public:
    // metodos publicos
    int getAltura() { return altura; }
    void setAltura(int _altura) { altura = _altura; }

    int getBase() { return base; }
    void setBase(int _base) { base = _base; }

    int calculaArea()
    {
        return base * altura;
    }

    int calculaPerimetro()
    {
        return ((2 * getBase()) + (2 * getAltura()));
    }
    
    void mostrarInformacoes()
    {
        cout << "O Retangulo " << getBase() << "x" << getAltura() << " tem:\n";
        cout << calculaPerimetro() << " de perimetro\n" << calculaArea() << " de area\n";
    }
};

int main()
{
    Retangulo r1;
    int mBase, mAltura;
    
    cout << "Digite a base e a altura do retangulo\n";
    cin >> mBase >> mAltura;

    r1.setBase(mBase);
    r1.setAltura(mAltura);

    r1.mostrarInformacoes();
    return 0;
}