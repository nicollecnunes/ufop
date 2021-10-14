#include "Cilindro.h"

Cilindro :: Cilindro(int raio, int altura):
    Circulo(raio), Retangulo(0, altura){
        setBase(Circulo :: calculaPerimetro());
    }

Cilindro :: ~Cilindro(){}

void Cilindro :: set(int raio, int altura){
    setRaio(raio); // da classe circulo
    setAltura(altura); // da classe retangulo
    setBase(Circulo :: calculaPerimetro()); 
}

int Cilindro :: calculaArea(){
    return 2 * Circulo :: calculaArea() + Retangulo :: calculaArea();
}

int Cilindro :: calculaVolume(){
    return getAltura() * Circulo :: calculaArea();
}

ostream& operator<<(ostream& out, const Cilindro& obj){
    out << "\nraio: " << obj.getRaio() << "\naltura: " << obj.getAltura();
    return out;
}