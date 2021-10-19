#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <iostream>

using namespace std;

class Professor{
    string nome;
    string matricula;
    int idade;
public:
    Professor(string="",string="", int=0);
    ~Professor();

    string getNome() const;
    string getMatricula() const;   
    int getIdade() const;

    void setNome(string);
    void setMatricula(string);
    void setIdade(int);

    virtual void saida(ostream&) const;
    virtual double calculaSalario() const = 0;

    friend ostream& operator<<(ostream&, const Professor&);
};

#endif