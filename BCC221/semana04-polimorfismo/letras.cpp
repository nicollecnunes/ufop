#include <iostream>
using namespace std;

class Base{
    int a, b, c;
public:
    Base(int a=0, int b=0, int c=0): a(a), b(b), c(c){}
    void print(){
        cout << "\nBase: " << a << ", " << b << ", " << c;
    }
};

class Derivada : public Base{
    int d, e, f;
public:
    Derivada(int d=0, int e=0, int f=0): d(d), e(e), f(f){}
    void print(){
        cout << "\nDerivada: " << d << ", " << e << ", " << f;
    }

};

int main(){
    Base objB(1,2,3);
    Base *pObjB=nullptr;

    Derivada objD(4,5,6);
    Derivada *pObjD=nullptr;

    pObjB = &objB;
    pObjB->print(); // a b c

    //pObjD = &objB; : Invalida, nao pode converter ptrD -> prtB, fica incompleto
    
    pObjD = &objD;
    pObjD->print(); // d e f

    pObjB = &objD; // objBase recebe endereço de objDeri, valido.
    pObjB->print(); // a b c

    return 0;
}