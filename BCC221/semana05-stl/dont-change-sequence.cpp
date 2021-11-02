#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int>:: iterator itrVec;

bool menor(int x){
    return x<10;
}

int main(){
    vector<int> vec = {9,60,90,8,45,87,90,69,69,55,7};

    itrVec it;
    pair<itrVec, itrVec> pair_itr;

    // contar
    int n = count(vec.begin(), vec.end(), 69); //2. procura 69 do inicio ao fim
    int m = count_if(vec.begin(), vec.end(), [](int x){return x <10;}); //3. procura do inicio ao final quais sao <10
    int m2 = count_if(vec.begin(), vec.end(), menor); //3. procura do inicio ao final quais sao <10

    // min e max
    it = max_element(vec.begin() + 3, vec.end()); // 90. procura da 3 posicao ate o final
    it = max_element(vec.begin(), vec.end(), [](int x, int y){return x%10 < y%10;});
    pair_itr = minmax_element(vec.begin(), vec.end());

    // primeiro = menor, ultimo = maior
    cout << *pair_itr.first << " " << *pair_itr.second << endl; //7 90

    // busca linear

    // retorna o primeiro
    it = find(vec.begin(), vec.end(), 55);
    if (it != vec.end()){
        cout << "\nFound";
    }
    else{
        cout << "\nNao encontrado";
    }

    // retorna o primeiro que e > 50
    it = find_if(vec.begin(), vec.end(), [](int x){return x>50;}); //60
    cout << "\n" << *it;

    //encontra 2 69 consecutivos
    it = search_n(vec.begin(), vec.end(), 2, 69);
    cout << "\n" << *it;

    // procura algum
    vector<int> item = {87,69,2};

    it = find_first_of(vec.begin(), vec.end(), item.begin(), item.end());
    cout << "\n" << *it; //87

    it = find_first_of(vec.begin(), vec.end(), item.begin(), item.end(), [](int x, int y){return x == 4 *y;});
    cout << "\n" << *it; // 8

    //dois elementos iguais consecutivos
    it = adjacent_find(vec.begin(), vec.end());
    cout << "\n" << *it; //69

    // comparacao
    vector<int> vec2(vec);  //copia
    if(equal(vec.begin(), vec.end(), vec2.begin())){
        cout << "\niguais";
    }

    // verificando atributos
    if(is_sorted(vec.begin(), vec.end())){
        cout << "\nordenado";
    }
    it = is_sorted_until(vec.begin(), vec.end()); //8
    cout << "\nParcialmente ordenado ate " << *it;


    return 0;
}