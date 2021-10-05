#include <iostream>
#include "Gerente.h"
using namespace std;

int main()
{
	Funcionario f1("Nic Nunes", 12345.00);

	Gerente g1("Serj Tankian", 300000.00, "sjtk", "pwd123");

	cout << g1;
	cout << "Bonificacao: " << g1.calculaBonificacao();

	cout << f1;
	cout << "Bonificacao: " << f1.calculaBonificacao();

	return 0;
}