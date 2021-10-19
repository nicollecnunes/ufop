#include "Professor.h"

class ProfessorDE : public Professor{
    double salario;
public:
    ProfessorDE(string="", string="", int=0, double=0.0);
    virtual ~ProfessorDE();

    void setSalario(double);
    double getSalario() const;

    virtual double calculaSalario() const;
    virtual void saida(ostream&) const;

    friend ostream& operator<<(ostream&, const ProfessorDE&);

};