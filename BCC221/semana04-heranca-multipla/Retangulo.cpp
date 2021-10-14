#include "Retangulo.h"

Retangulo :: Retangulo(int base, int altura){
	setBase(base);
	setAltura(altura);
}
Retangulo :: ~Retangulo(){}

int Retangulo :: getBase() const
{
	return base;
}

void Retangulo :: setBase(int b)
{
	base = b;
}

int Retangulo :: getAltura() const
{
	return altura;
}

void Retangulo :: setAltura(int a)
{
	altura = a;
}

int Retangulo :: calculaArea()
{
	return base * altura;
}

int Retangulo :: calculaPerimetro()
{
	return 2 * base + 2 * altura;
}

ostream& operator<<(ostream& out, const Retangulo& obj){
	out << "\nbase: " << obj.base << "\naltura: " << obj.altura;
	return out;
}


