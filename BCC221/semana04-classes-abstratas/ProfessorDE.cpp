#include "ProfessorDE.h"

ProfessorDE :: ProfessorDE(string nome, string matricula, int idade, double salario):
    Professor(nome, matricula, idade), salario(salario){}

ProfessorDE::~ProfessorDE(){}

void ProfessorDE :: setSalario(double _salario){
    this->salario = (_salario > 0) ? _salario : 0;
}

double ProfessorDE :: getSalario() const {
    return salario;
}

double ProfessorDE :: calculaSalario() const{
    return getSalario();
}

void ProfessorDE :: saida(ostream& out) const {
    out << "ProfessorDE: ";
    Professor :: saida(out);
    out <<  " " << calculaSalario();
}

ostream& operator<<(ostream& out, const ProfessorDE& obj){
    obj.saida(out);
    return out;
}