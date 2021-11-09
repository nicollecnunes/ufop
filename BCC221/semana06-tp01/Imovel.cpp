#include "Imovel.h"

Imovel::Imovel(const int id, const float valor, const string proprietario,
                        const string rua, const string bairro, const string cidade, const int numero,
                        const int quartos, const int banheiros) : id(id), valor(valor), proprietario(proprietario),
                        rua(rua), bairro(bairro), cidade(cidade), numero(numero), quartos(quartos),
                        banheiros(banheiros) {}

int Imovel::getId() const{
    return id;
}

void Imovel::setId(int id){
    this->id = id;
}

float Imovel::getValor() const{
    return valor;
}

void Imovel::setValor(float valor){
    this->valor = valor;
}

string Imovel::getProprietario() const{
    return proprietario;
}

void Imovel::setProprietario(string proprietario){
    this->proprietario = proprietario;
}

string Imovel::getRua() const{
    return rua;
}

void Imovel::setRua(string rua){
    this->rua = rua;
}

string Imovel::getBairro() const{
    return bairro;
}

void Imovel::setBairro(string bairro){
    this->bairro = bairro;
}

string Imovel::getCidade() const{
    return cidade;
}

void Imovel::setCidade(string cidade){
    this->cidade = cidade;
}

int Imovel::getNumero() const{
    return numero;
}

void Imovel::setNumero(int numero){
    this->numero = numero;
}

int Imovel::getQuartos() const{
    return quartos;
}

void Imovel::setQuartos(int quartos){
    this->quartos = quartos;
}

int Imovel::getBanheiros() const{
    return banheiros;
}

void Imovel::setBanheiros(int banheiros){
    this->banheiros = banheiros;
}

bool Imovel::operator<(const Imovel &other) {
    return valor < other.valor;
}

void Imovel::imprimirTudo(){
}

void Imovel::saida(ostream& out){
    out << "\n-----------------------------------\n" 
        << "Proprietario: " << this->proprietario << "\n"
        << "    Preco: " << this->valor << "\n"
        << "    Quartos: " << this->quartos << "\n"
        << "    Rua: " << this->rua << "\n"
        << "    Bairro: " << this->bairro << "\n"
        << "    Cidade: " << this->cidade << "\n";
}


ostream& operator<<(ostream& out, Imovel& obj){
    obj.saida(out);
 	return out;
}

Imovel::~Imovel() = default;
