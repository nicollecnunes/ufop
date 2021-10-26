#include "SortVetor.h"

using namespace std;

int main(){
    Vetor<int> v(10);
    v.pushBack(3);
    v.pushBack(10);
    v.pushBack(1);
    v.pushBack(19);
    cout << "\nVetor nao ordenado: " << v;

    SortVetor<int> v2(10);
    v2.pushBack(3);
    v2.pushBack(10);
    v2.pushBack(1);
    v2.pushBack(19);
    cout << "\nVetor ordenado: " << v2;

    return 0;
}