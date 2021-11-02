#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

int main(){
    vector<int> vec = {9,1,10,2,45,3,90,4,9,5,8};
    ostream_iterator<int> out(cout, " ");


    sort(vec.begin(), vec.end());
    //vec 1,2,3,4,5,8,9,9,10,45,90

    sort(vec.begin(), vec.end(), [](int x, int y){
        return x%10 < y%10;
    });
    //vec: 10,90,1,2,3,4,45,5,8,9,9

    partial_sort(vec.begin(), vec.begin()+5, vec.end(),
        greater<int>());
    //vec: 90,45,10,9,9,1,2,3,4,5,8
    //especificou o greater ate a pos 5

    partial_sort(vec.begin(), vec.begin()+5, vec.end());
    //vec 1,2,3,4,5,90,45,10,9,9,8
    //default menor ao maior

    nth_element(vec.begin(), vec.begin()+vec.size() /2, vec.end()); //8
    cout << "mediana: " << vec[vec.size()/2] << "\n";

    nth_element(vec.begin(), vec.begin() +1, vec.end(), greater<int>()); //45
    cout << "o segundo maior: " << vec[1] << "\n";

    // mover todos os valores menores que 10 pra frente do vetor
    vec.assign({9,1,10,2,45,3,90,4,9,5,8});
    partition(vec.begin(), vec.end(), [](int x){return x<10;});
    //vec: 9,1,8,2,5,3,9,4,90,45,10

    //preserva a ordem original dentro de cada particao
    vec.assign({9,1,10,2,45,3,90,4,9,5,8});
    stable_partition(vec.begin(), vec.end(), [](int x){return x<10;});
    //vec 9,1,2,3,4,9,5,8,10,45,90

    //heapsort
    make_heap(vec.begin(), vec.end());
    sort_heap(vec.begin(), vec.end());
    //vec: 1,2,3,4,5,8,9,9,10,45,90

    return 0;
}