#include "JogadorAtacante.h"

JogadorAtacante :: JogadorAtacante(string nome, int idade, int habilidade, int velocidade, int tecnica):
    Jogador(nome, idade, habilidade), velocidade(velocidade), tecnica(tecnica){}


double JogadorAtacante :: getHabilidade() const{
    return ((habilidade*5) + (velocidade*2) + (tecnica*3) ) / 10;
}

void JogadorAtacante :: saida(ostream& out) const {
    out << "\n\nJogador atacante: ";
    Jogador :: saida(out);
    out <<  "\nTecnica: " << tecnica << "\nVelocidade: " << velocidade << "\nHabilidade: " << getHabilidade();
}

ostream& operator<<(ostream& out, const JogadorAtacante& obj){
    obj.saida(out);
    return out;
}