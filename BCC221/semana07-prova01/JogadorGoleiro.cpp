#include "JogadorGoleiro.h"

JogadorGoleiro :: JogadorGoleiro(string nome, int idade, int habilidade, int reflexos, float altura):
    Jogador(nome, idade, habilidade), reflexos(reflexos), altura(altura){}


double JogadorGoleiro :: getHabilidade() const{
    return ((habilidade*5) + (velocidade*2) + (tecnica*3) ) / 10;
}

void JogadorGoleiro :: saida(ostream& out) const {
    out << "\n\nJogador goleiro: ";
    Jogador :: saida(out);
    out <<  "\naltura: " << altura << "\nreflexos: " << reflexos << "\nHabilidade: " << getHabilidade();
}

ostream& operator<<(ostream& out, const JogadorGoleiro& obj){
    obj.saida(out);
    return out;
}