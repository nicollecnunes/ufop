#include <iostream>
#include "Ponto.h"
using namespace std;

int main()
{
	Ponto P1(2,3), P2(P1), P3, P4;
	//P1(2,3)   P2(2,3)   P3(0,0)   P4(0,0)

	P1.print();
	P1++;
	P1.print();

	P3 = P1 + P2;
	P3.print();
	P3 = P1;

	if (P3 == P1)
	{
		cout << "Iguais!\n";
	}
	else
	{
		cout << "Diferentes!\n";
	}

	cout << "Digite coordenadas para P4: ";
	cin >> P4;
	cout << P1;
	cout << P1++ << P1 + P2;
	return 0;




	return 0;

}