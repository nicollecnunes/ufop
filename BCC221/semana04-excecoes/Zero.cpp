#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class Zero : public runtime_error{
public: 
    Zero(const string msg) : runtime_error(msg){}
};

double divisao(int n, int d){
    if (d == 0)
        throw Zero("Divisao por 0\n");
    return static_cast<double>(n) / d;
}

int main(){
    int a, b;
    double result;

    cout << "\nDigite 2 numeros inteiros: ";

    while (cin >> a >> b){
        try{
            result = divisao(a,b);
            cout << divisao(a,b);
        }
        catch (Zero& e){
            cout << "erro: " << e.what() << "\n";

        }
        cout << "\nDigite 2 numeros inteiros: ";
    }

    return 0;
}