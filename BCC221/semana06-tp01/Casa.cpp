#include "Casa.h"

Casa :: Casa(const int id, const float valor, const string proprietario,
                        const string rua, const string bairro, const string cidade, const int numero,
                        const int quartos, const int banheiros, const int andares, const bool sala_jantar):
                        Imovel(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros),
                        andares(andares), sala_jantar(sala_jantar){}

int Casa::getAndares() const{
    return andares;
}

void Casa::setAndares(int andares){
    this->andares = andares;
}

bool Casa::getSalaJantar() const{
    return sala_jantar;
}

void Casa::setSalaJantar(bool sala_jantar){
    this->sala_jantar = sala_jantar;
}

void Casa::saida(ostream& out){
    Imovel::saida(out);
    out << "    Andares: " << this->getAndares() << endl;
}

ostream& operator<<(ostream& out, Casa& obj){
    obj.saida(out);
	return out;
}


void Casa::imprimirTudo(){
    cout << "    Sala de jantar: " << (this->getSalaJantar() ? "SIM" : "NAO") << endl;
}

Casa::~Casa() = default;
