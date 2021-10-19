#include "ProfessorH.h"
ProfessorH :: ProfessorH(string n, string m, int i, int t, double s):
    Professor(n,m,i),
    totalHoras(t),
    salarioHora(s){}

ProfessorH :: ~ProfessorH(){}

int ProfessorH :: getTotalHoras() const {
    return totalHoras;
}

double ProfessorH :: getSalarioHora() const {
    return salarioHora;
}

void ProfessorH :: setTotalHoras(int _totalHoras){
    this->totalHoras = (_totalHoras > 0) ? _totalHoras : 0;
}

void ProfessorH :: setSalarioHora(double _salarioHora){
    this->totalHoras = (_salarioHora > 0) ? _salarioHora : 0;
}

double ProfessorH :: calculaSalario() const {
    return getTotalHoras() * getSalarioHora();
}

void ProfessorH :: saida(ostream&out) const{
    out << "Professor Horista: ";
    Professor :: saida(out);
    out << " " << totalHoras << " " << salarioHora;
}

ostream& operator<<(ostream& out, const ProfessorH& obj){
    obj.saida(out);
    return out;
}