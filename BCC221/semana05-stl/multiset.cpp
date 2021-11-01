#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

// define nome abreviado para o tipo multiset usado no programa
typedef std::multiset<int, std::less<int>> lms;

int main(){
    const int SIZE =10;

    int a[SIZE] = {7,22,9,1,18,30,100,22,22,85};

    lms intMultiset; // lms e o typedef de multiset int
    std :: ostream_iterator<int> output(cout, " ");

    cout <<  "There are currently " << intMultiset.count(15) <<
    " values of 15\n"; // 0

    intMultiset.insert(15);
    intMultiset.insert(15);

    cout << "After inserts: ";
    cout <<  "There are currently " << intMultiset.count(15) <<
    " values of 15\n"; // 2

    // iterador que não pode ser utilizado para alterar valores de elemento
    lms::const_iterator result;

    //localiza 15 em intMultiset. find retorna o iterador
    // retorna end() se o elemento não é encontrado
    result = intMultiset.find(15);

    if (result != intMultiset.end())
        cout << "Found\n";

    // insere elementos do array a em intMultiset
    intMultiset.insert(a,  a + SIZE);
    cout << "After all: ";
    std::copy(intMultiset.begin(), intMultiset.end(), output);

    // for (auto itr = intMultiset.begin(); itr != intMultiset.end(); ++itr)
    //cout << itr<<;

    cout << "\n\nLower 22: " << *(intMultiset.lower_bound(22));
    cout << "\nUpper 22: " << *(intMultiset.upper_bound(22)); 

    // p representa par de const_iterators
    std :: pair < lms :: const_iterator, lms :: const_iterator > p;

    // usa equal_range pra determinar limite inf e sup de 22
    p = intMultiset.equal_range(22);

    cout << "\n\nEqual 22:"
    << "\nLower: " << *(p.first)
    << "\nUpper: " << *(p.second);

    return 0;
}