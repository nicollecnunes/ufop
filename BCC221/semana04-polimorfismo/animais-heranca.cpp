#include <iostream>
using namespace std;

class Mamifero{
    public:
    void emitirSom(){
        cout << "\nSom de mamifero";
    }
};

class Cachorro : public Mamifero{
    public:
    void emitirSom(){
        cout << "\nWoof woof";
    }
};

class Vaca : public Mamifero{
    public:
    void emitirSom(){
        cout << "\nMuu muu";
    }
};

class Bode : public Mamifero{
    public:
    void emitirSom(){
        cout << "\nBaa baa";
    }
};

class Gato : public Mamifero{
    public:
    void emitirSom(){
        cout << "\nMeow meow";
    }
};

int main(){
    Cachorro C;
    Vaca V;
    Bode B;
    Gato G;

    C.emitirSom();
    V.emitirSom();
    B.emitirSom();
    G.emitirSom();
    return 0;
}