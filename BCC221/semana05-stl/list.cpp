#include <list>
#include <iostream>
#include <iterator>

using namespace std;

template<typename T>
void printList(list <T> & L){
    for (auto elem : L){
        cout << elem << " ";
    }
    cout << endl;
}

template<typename T>
void reversePrintList(const list<T> & L){
    for (typename list<T>::revertse_iterator it = L.rbegin(); it != L.rend(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    const int SIZE = 4;
    int array[SIZE] = {2,6,4,8};
    list<int> values; //cria lista de int
    list<int> otherValues;

    values.push_front(1);
    values.push_front(2);
    values.push_front(4);
    values.push_front(3);

    cout << "Values contains ";
    printList(values);

    values.sort(); 
    cout << "\nValues AFTER SORTING contains ";
    printList(values);

    // insere elementos do array em otherValues
    otherValues.insert(otherValues.begin() , array, array + SIZE);
    cout << "\nAfter Insert, otherValues contains ";
    printList(otherValues);

    // remove elementos de otherValues e insere ao fim de Values
    values.splice(values.end(), otherValues);
    cout << "\nAfter splice, values contains ";
    printList(values);

    values.sort(); 
    cout << "\nValues AFTER SORTING contains ";
    printList(values);

    values.unique();
    cout << "\nValues unique ";
    printList(values);

    values.remove(4);
    cout << "\nAfter 4 banned ";
    printList(values);
}