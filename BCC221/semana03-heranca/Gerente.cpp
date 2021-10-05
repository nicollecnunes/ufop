#include "Gerente.h"

Gerente :: Gerente(string nome, double salario, string usuario, string senha) :
Funcionario(nome, salario), usuario(usuario), senha(senha){}

Gerente :: ~Gerente(){}

string Gerente :: getUsuario() const
{
	return usuario;
}

void Gerente :: setUsuario(string usuario)
{
	this->usuario = usuario;
}

string Gerente :: getSenha() const
{
	return senha;
}

void Gerente :: setSenha(string senha)
{
	this->senha = senha;
}

double Gerente :: calculaBonificacao() // redefinicao
{
	return getSalario() * 1.6 + 100;
}

ostream& operator<<(ostream& out, const Gerente& gr)
{
	out << "\nnome: " << gr.getNome() // com get pra acessar
	<< "\nsalario: " << gr.getSalario() // de dentro de func
	<<"\nusuario: " << gr.usuario << "\n";

	return out;
}
