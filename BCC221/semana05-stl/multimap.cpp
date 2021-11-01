#include <iostream>
#include <map>

using namespace std;

// define o nome abreviado
typedef std::multimap<int, double, std::less<int>> Mmid;

int main(){
    Mmid pairs; //pares de multimap

    cout << "There are " << pairs.count(15) <<
    " pairs with key 15\n"; // 0

    pairs.insert(Mmid::value_type(15, 2.7));
    pairs.insert(Mmid::value_type(15, 7.2));

    cout << "After inserts: " << pairs.count(15) << 
    " pairs with key 15\n\n"; //2

    pairs.insert(Mmid::value_type(30, 233.7));
    pairs.insert(Mmid::value_type(10, 7.264));
    pairs.insert(Mmid::value_type(25, 2.6667));
    pairs.insert(Mmid::value_type(20, 447.2));
    pairs.insert(Mmid::value_type(5, 244.7));

    cout << "Multimap pairs contains:\nKey\tValue\n";

    //usa const iterator para percorrer elementos de pares

    for(Mmid :: const_iterator iter = pairs.begin(); iter!=pairs.end(); ++iter){
        cout << iter->first << '\t' << iter->second << '\n';
    }
    //chaves ordenadas

    return 0;

}