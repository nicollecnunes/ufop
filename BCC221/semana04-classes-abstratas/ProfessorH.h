#include "Professor.h"

class ProfessorH : public Professor{
    int totalHoras;
    double salarioHora;
public:
    ProfessorH(string="", string="", int=0, int=0, double=0.0);
    virtual ~ProfessorH();

    int getTotalHoras() const;
    double getSalarioHora() const;

    void setTotalHoras(int);
    void setSalarioHora(double);

    virtual double calculaSalario() const;
    virtual void saida(ostream&) const;

    friend ostream& operator<<(ostream&, const ProfessorH&);
};