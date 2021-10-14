#include "Circulo.h"

Circulo :: Circulo(int raio){
	setRaio(raio);
}

Circulo :: ~Circulo(){}

int Circulo :: getRaio() const
{
	return raio;
}

void Circulo :: setRaio(int raio)
{
	this->raio = raio;
}

int Circulo:: calculaPerimetro()
{
	return 2 * 3 * raio;
}

int Circulo::calculaArea()
{
	return 3 * raio * raio;
}

ostream& operator<<(ostream& out, const Circulo& obj){
	out << "\nraio: " << obj.raio;
	return out;
}
