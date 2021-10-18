#include <iostream>
using namespace std;

class Mamifero{
    public:
    // sera sobrescrito
    // metodo polimorfico
    virtual void emitirSom(){
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
    Mamifero *p[4] = {
        new Cachorro(),
        new Vaca(),
        new Bode(),
        new Gato()
    };

    for (int i=0; i <4; i++)
        p[i]->emitirSom();
        
    return 0;
}