#include <iostream>
#include "Retangulo.h"
#include "Quadrado.h"


Retangulo :: Retangulo (double largura, double comprimento) : largura(largura), comprimento(comprimento){}

Retangulo :: ~Retangulo(){}

void Retangulo :: setValores(double largura, double comprimento)
{
	this->largura = largura;
	this->comprimento = comprimento;
}

double Retangulo :: calculaArea()
{
	return largura * comprimento;
}

Retangulo duplicaAmiga(Retangulo R)
{
	Retangulo tmp;
	tmp.largura = 2 * R.largura;
	tmp.comprimento = 2 * R.comprimento;
	return tmp;
}

void Retangulo :: converte(Quadrado S)
{
	// operacao valida pois sao classes amigas
	largura = S.lado;
	comprimento = S.lado;
}
