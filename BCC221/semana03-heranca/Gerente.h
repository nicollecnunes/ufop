#include "Funcionario.h"

class Gerente : public Funcionario
{
	string usuario, senha;
public:
	Gerente(string="", double = 0.0, string="", string="");
	~Gerente();

	string getUsuario() const;
	void setUsuario(string);

	string getSenha() const;
	void setSenha(string);

	double calculaBonificacao();
	friend ostream& operator << (ostream&, const Gerente&);
};