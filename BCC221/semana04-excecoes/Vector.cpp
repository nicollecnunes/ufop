#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main(){
    vector<int> v(4);
    int i, valor;

    try{
        cin >> i >> valor;
        v.at(i) = valor;
        cout << "\nInserido o numero " << valor << " na posicao " << i;
    }
    catch(out_of_range &e){
        cout << "\nErro: " << e.what();
    }
    catch(...){
        cout << "\nErro inesperado\n";
    }
    return 0;
}