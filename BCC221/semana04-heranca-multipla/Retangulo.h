#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Retangulo
{
	int base, altura;

public:
	Retangulo(int=0, int=0);
	~Retangulo();

	int getBase() const;
	void setBase(int);

    int getAltura() const;
	void setAltura(int);

	int calculaArea();
    int calculaPerimetro();

    friend ostream& operator <<(ostream&, const Retangulo&);
};