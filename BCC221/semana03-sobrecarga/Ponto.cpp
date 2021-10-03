#include <iostream>
#include <ostream>
#include <istream>
#include "Ponto.h"
using namespace std;

Ponto :: Ponto(int x, int y) :  x(x), y(y) {}

Ponto :: Ponto(const Ponto& P)
{
	x = P.x;
	y = P.y;
}

Ponto :: ~Ponto(){}

void Ponto :: set(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Ponto :: set(const Ponto& P)
{
	this->x = P.x;
	this->y = P.y;
}

Ponto& Ponto :: operator++()
{
	this->x++;
	this->y++;
	// entrega o objeto, o conteudo
	return *this;
}

Ponto& Ponto :: operator++(int)
{
	this->operator++();
	return *this;
}

Ponto Ponto :: operator+(const Ponto& P2) const
{
	Ponto tmp;
	tmp.x = this->x + P2.x;
	tmp.y = this->y + P2.y;

	// retorna esse terceiro objeto, somado
	return tmp;
}

Ponto& Ponto :: operator=(const Ponto& P)
{
	if (this == &P)
	{
		return *this;
	}
	else
	{
		this->x = P.x;
		this->y = P.y;
		return *this;
	}
}

bool operator==(const Ponto& P1, const Ponto& P2)
{
	return (P1.x == P2.x && P1.y == P2.y);
}

void Ponto::print()
{
	cout << "(" << this->x << ", " << this->y << ")\n";
}

std :: ostream& operator<<(std::ostream& out, const Ponto& P)
{
	//out é o nome do objeto referenciado
	out << "(" << P.x << ", " << P.y << ")\n";
	return out;
}

std :: istream& operator>>(std:: istream& in, Ponto& P)
{
	in >> P.x >> P.y;
	return in;
}