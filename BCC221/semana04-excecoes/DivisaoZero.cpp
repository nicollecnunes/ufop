using namespace std;
#include <iostream>

int main (){
    int a, b;
    double c;

    cin >> a >> b;

    try{
        if(b == 0){
            throw "Divisao por zero\n";
        }
        c = static_cast<double>(a) / b;
        cout << "Resultado: " << c << endl;
    }
    catch (const char* e){
        cerr << "Erro: " << e;
    }
    return 0;
}