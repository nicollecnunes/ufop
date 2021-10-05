#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Funcionario
{
	string nome;
	double salario;

public:
	Funcionario(string="", double=0.0);
	~Funcionario();

	string getNome() const;
	void setNome(string);

	double getSalario() const;
	void setSalario(double);

	double calculaBonificacao();
	friend ostream& operator << (ostream&, const Funcionario&);
};