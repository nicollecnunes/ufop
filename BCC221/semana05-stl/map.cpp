#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main(){
    typedef map<string, int> mapType;

    mapType popMap;

    popMap.insert(pair<string, int>("China", 1339));
    popMap.insert(pair<string, int>("India", 1187));

    popMap.insert(mapType::value_type("US", 310));
    popMap.insert(mapType::value_type("Indonesia", 234));

    popMap.insert(make_pair("Brasil", 193));
    popMap.insert(make_pair("Pakistan", 170));

    popMap["Italia"] = 60;
    popMap["Alemanha"] = 81;

    //apaga o ultimo elemento usando erase()
    //map elements não ficam na ordem de entrada, pq sao ordenados
    // o ultimo é US

    mapType :: iterator iter = --popMap.end(); //volta uma posicao,
    //pq end() aponta pra depois do ultimo, nao ao ultimo
    popMap.erase(iter);

    cout << "Novo size: " << popMap.size() << "\n";

    for (iter = popMap.begin(); iter != popMap.end(); ++iter){
        cout << iter->first << ": " << iter->second << "M\n";
    }

    //find() retorna o iterador para o elemento match
    // se nao acha, vai pro final end
    string country("Indonesia");

    iter = popMap.find(country);

    if (iter != popMap.end()){
        cout << "Found..\n";
        cout << "population: " << iter->second;
    }
    else{
        cout << "Not found\n";
    }

    popMap.clear(); //apaga tudo
    

    return 0;

}