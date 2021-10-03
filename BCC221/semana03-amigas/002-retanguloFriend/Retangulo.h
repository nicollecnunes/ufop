#ifndef RETANGULO_H
#define RETANGULO_H

class Quadrado;

class Retangulo
{
	double largura, comprimento;
	public:
		Retangulo(double = 0.0, double = 0.0);
		~Retangulo();
		
		void setValores(double, double);
		double calculaArea();

		friend Retangulo duplicaAmiga(Retangulo);
		void converte(Quadrado);
};

#endif