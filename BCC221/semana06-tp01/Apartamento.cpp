#include "Apartamento.h"

Apartamento :: Apartamento(const int id, const float valor, const string proprietario,
                        const string rua, const string bairro, const string cidade, const int numero,
                        const int quartos, const int banheiros,const int andar, const float taxa_condominio,
                        const bool elevador, const bool sacada) : Imovel(id, valor, proprietario, rua, bairro,
                        cidade, numero, quartos, banheiros), andar(andar), taxa_condominio(taxa_condominio),
                        elevador(elevador), sacada(sacada){}

int Apartamento::getAndar() const{
    return andar;
}

void Apartamento::setAndar(int andar){
    this->andar = andar;
}

float Apartamento::getTaxaCondominio() const{
    return taxa_condominio;
}

void Apartamento::setTaxaCondominio(float taxa_condominio){
    this->taxa_condominio = taxa_condominio;
}

bool Apartamento::getElevador() const{
    return elevador;
}

void Apartamento::setElevador(bool elevador){
    this->elevador = elevador;
}

bool Apartamento::getSacada() const{
    return sacada;
}

void Apartamento::setSacada(bool sacada){
    this->sacada = sacada;
}

void Apartamento::saida(ostream& out){
    Imovel::saida(out);
    if (this->elevador){
        out << "    Elevador: SIM" << endl;
    }
    else{
        out << "    Elevador: NAO" << endl;
    }
}
    
ostream& operator<<(ostream& out, Apartamento& obj){
    obj.saida(out);
    return out;
}

void Apartamento::imprimirTudo(){
    cout << "    Andar: " << (this->getAndar());
    cout << "\n    Taxa de condominio: " << (this->getTaxaCondominio());
    cout << "\n    Sacada: " << (this->getSacada() ? "SIM" : "NAO") << endl;
}

Apartamento::~Apartamento() = default;
