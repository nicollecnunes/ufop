#include "JogadorAtacante.h"
#include "JogadorDefesa.h"
#include "JogadorGoleiro.h"

#include <iostream>
#include <string>

using namespace std;

int main(){
    Jogador j("nic", 19, 2);
    JogadorAtacante ja("nic atacante", 19, 2, 20, 20);
    JogadorDefesa jd("nic defesa", 19, 2, 20, 40);
    JogadorGoleiro jg("nic goleira", 19, 2, 5, 1.64);

    cout << j << ja << jd << jg;
}