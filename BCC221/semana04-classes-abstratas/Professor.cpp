#include "Professor.h"
Professor :: Professor (string nome, string matricula, int idade) :
    nome(nome), matricula(matricula), idade(idade) {}

Professor :: ~Professor(){}

string Professor :: getNome() const {
    return nome;
}

string Professor :: getMatricula() const {
    return matricula;
}

int Professor :: getIdade() const {
    return idade;
}

void Professor :: setNome(string _nome){
    this->nome = _nome;
}

void Professor :: setMatricula(string _matricula){
    this->matricula = _matricula;
}

void Professor :: setIdade(int _idade){
    this->idade = _idade;
}

void Professor :: saida(ostream& out) const {
    out << nome << " " << matricula << " " << idade;
}

ostream& operator << (ostream& out, const Professor& obj){
    obj.saida(out);
    return out;
}