#include <iostream>
using namespace std;

class DiarioClasse{
    // antes do public e tudo privado
    public:
    // metodo  publico sem retorno
    void MostraMensagem()
    {
        cout  << "Ola, mundo!" << endl;
    }
};

int main()
{
    // instancia um objeto do tipo DiarioClasse
    DiarioClasse d1; 

    // chama o metodo MostraMensagem
    d1.MostraMensagem();
    
    return 0;
}