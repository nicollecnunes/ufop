#include <iostream>
using namespace std;

class Poligono {
    protected:
    double base, altura;
    public:
    void setValores(double a, double b){
        base = a;
        altura = b;
    }

    virtual double area(void){
        return 0;
    }
};

class Retangulo: public Poligono{
    public:
    double area(void){
        return (base * altura);
    }
};

class Triangulo : public Poligono{
    public:
    double area(void){
        return (base * altura /2);
    }
};

int main(){
    Poligono *pPoly1 = new Retangulo();
    Poligono *pPoly2 = new Triangulo();
    Poligono *pPoly3 = new Poligono();

    pPoly1->setValores(4,5);
    pPoly2->setValores(4,5);
    pPoly3->setValores(4,5);

    cout << pPoly1->area() << endl; //area retangulo
    cout << pPoly2->area() << endl; //area triangulo
    cout << pPoly3->area() << endl; //area poligono

    return 0;
}
