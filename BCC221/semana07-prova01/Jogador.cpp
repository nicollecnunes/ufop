#include "Jogador.h"

Jogador :: Jogador (string nome,int idade, int habilidade) :
    nome(nome), idade(idade), habilidade(habilidade)  {}


void Jogador :: somaGol(){
    gols = gols + 1;
}

void Jogador :: saida(ostream& out) const {
    out << "\nNome: " << nome << "\nIdade: " << idade;
}

ostream& operator << (ostream& out, const Jogador& obj){
    obj.saida(out);
    return out;
}
