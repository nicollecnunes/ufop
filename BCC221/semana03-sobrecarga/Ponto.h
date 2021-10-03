#ifndef PONTO_H
#define PONTO_H
#include <iostream>
#include <ostream>

class Ponto
{
	int x, y;

	public:
		Ponto(int =0, int=0);
		Ponto(const Ponto&);
		~Ponto();

		void set(int, int);
		void set(const Ponto&);
		void print();

		//declaracao de operadores unarios como metodos
		Ponto& operator++(); //p++
		Ponto& operator++(int); //++p

		//binatrios como metodos
		Ponto operator+(const Ponto&) const;
		Ponto& operator=(const Ponto&);

		//binarios com funcao friend
		friend bool operator==(const Ponto&, const Ponto&);

		friend std :: ostream& operator<<(std:: ostream&, const Ponto&);
		friend std :: istream& operator>>(std::istream&, Ponto&);
};

#endif