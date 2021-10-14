#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Circulo
{
	int raio;

public:
	Circulo(int=0);
	~Circulo();

	int getRaio() const;
	void setRaio(int);

	int calculaArea();
    int calculaPerimetro();

    friend ostream& operator <<(ostream&, const Circulo&);
};