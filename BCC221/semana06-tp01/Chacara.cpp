#include "Chacara.h"

Chacara :: Chacara(const int id, const float valor, const string proprietario,
                        const string rua, const string bairro, const string cidade, const int numero,
                        const int quartos, const int banheiros, const bool salao_festa,const bool salao_jogos,
                        const bool campo_futebol,const bool churrasqueira,const bool piscina): Imovel(id, valor, proprietario, rua, bairro,
                        cidade, numero, quartos, banheiros), salao_festa(salao_festa), salao_jogos(salao_jogos),
                        campo_futebol(campo_futebol), churrasqueira(churrasqueira), piscina(piscina){}

bool Chacara::getSalaoFesta() const{
    return salao_festa;
}

void Chacara::setSalaoFesta(bool salao_festa){
    this->salao_festa = salao_festa;
}

bool Chacara::getSalaoJogos() const{
    return salao_jogos;
}

void Chacara::setSalaoJogos(bool salao_jogos){
    this->salao_jogos = salao_jogos;
}

bool Chacara::getCampoFutebol() const{
    return campo_futebol;
}

void Chacara::setCampoFutebol(bool campo_futebol){
    this->campo_futebol = campo_futebol;
}

bool Chacara::getChurrasqueira() const{
    return churrasqueira;
}

void Chacara::setChurrasqueira(bool churrasqueira){
    this->churrasqueira = churrasqueira;
}

bool Chacara::getPiscina() const{
    return piscina;
}

void Chacara::setPiscina(bool piscina){
    this->piscina = piscina;
}

void Chacara::saida(ostream& out){
    Imovel::saida(out);
    if (this->getPiscina()){
        out << "    Piscina: SIM" << endl;
    }
    else{
        out << "    Piscina: NAO" << endl;
    }
}

ostream& operator<<(ostream& out, Chacara& obj){
    obj.saida(out);
	return out;
}

void Chacara::imprimirTudo(){
    cout << "    Salao de festas: " << (this->getSalaoFesta() ? "SIM" : "NAO");
    cout << "\n    Salao de jogos: " << (this->getSalaoJogos() ? "SIM" : "NAO");
    cout << "\n    Campo de futebol: " << (this->getCampoFutebol() ? "SIM" : "NAO");
    cout << "\n    Churrasqueira: " << (this->getChurrasqueira() ? "SIM" : "NAO") << endl;
}

Chacara::~Chacara() = default;
