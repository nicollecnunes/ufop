#include "JogadorDefesa.h"

JogadorDefesa :: JogadorDefesa(string nome, int idade, int habilidade, int desarme, int cobertura):
    Jogador(nome, idade, habilidade), desarme(desarme), cobertura(cobertura){}


double JogadorDefesa :: getHabilidade() const{
    return ((habilidade*5) + (cobertura*3) + (desarme*2) )/10;
}

void JogadorDefesa :: saida(ostream& out) const {
    out << "\n\nJogador defesor: ";
    Jogador :: saida(out);
    out <<  "\ncobertura: " << cobertura << "\ndesarme: " << desarme << "\nHabilidade: " << getHabilidade();
}

ostream& operator<<(ostream& out, const JogadorDefesa& obj){
    obj.saida(out);
    return out;
}