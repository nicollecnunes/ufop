#include <iostream>
#include "Retangulo.h"
#include "Quadrado.h"

using namespace std;

int main()
{
	Retangulo R1, R2;
	Quadrado S;

	R1.setValores(2,3);
	cout << R1.calculaArea() << "\n";

	R2 = duplicaAmiga(R1);
	cout << R2.calculaArea() << "\n";

	S.setLado(4);
	R1.converte(S);
	cout << R1.calculaArea() << "\n";




	return 0;
}