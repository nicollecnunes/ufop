#include "Funcionario.h"

Funcionario :: Funcionario(string nome, double salario) : nome(nome), salario(salario){}
Funcionario :: ~Funcionario(){}

string Funcionario :: getNome() const
{
	return nome;
}

void Funcionario :: setNome(string nome)
{
	this->nome = nome;
}

double Funcionario :: getSalario() const
{
	return salario;
}

void Funcionario :: setSalario(double salario)
{
	if(salario > 0)
		this->salario = salario;
	else
		this->salario = 0.0;
}

double Funcionario :: calculaBonificacao()
{
	return getSalario() * 1.1;
}

ostream& operator<<(ostream& out, const Funcionario& funci)
{
	out << "\nnome: " << funci.nome << "\nsalario: "
	<< fixed << setprecision(2) << funci. salario << "\n";

	return out;
}
