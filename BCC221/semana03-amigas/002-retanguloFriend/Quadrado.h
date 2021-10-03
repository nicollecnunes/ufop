#ifndef QUADRADO_H
#define QUADRADO_H

class Retangulo;

class Quadrado
{
	double lado;
	public:
		Quadrado();
		~Quadrado();
		
		void setLado(double);
		// da para a classe Retangulo a permissao de acessar tudo aqui
		friend class Retangulo;
};

#endif