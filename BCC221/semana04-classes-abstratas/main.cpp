#include "ProfessorDE.h"
#include "ProfessorH.h"
#include <vector>

int main(){
    ProfessorDE *pd1, *pd2, *pd3;
    pd1 = new ProfessorDE("Gabriel", "789.26", 35, 5000.0);
    pd2 = new ProfessorDE("Marta", "789.26", 33, 5000.0);
    pd3 = new ProfessorDE("Simone", "789.26", 28, 6500.0);

    ProfessorH *ph1, *ph2;
    ph1 = new ProfessorH("Jane", "987.43", 28, 25, 101.00);
    ph2 = new ProfessorH("Jorge", "987.43", 50, 20, 101.00);

    // estrutura vetor com memoria alocada de forma dinamica
    vector<Professor*> v;

    // insere do inicio ao final
    v.push_back(pd1);
    v.push_back(pd2);
    v.push_back(pd3);

    v.push_back(ph1);
    v.push_back(ph2);

    for (auto item : v){
        cout << "\n" << *item << " Salario:"
        << item->calculaSalario();
    }

    return 0;
}