#include <iostream>
#include <queue>
#include <cstdlib> //rand()
#include <functional> //function

using namespace std;

template<typename T>
void pushElements(T& fila){
    cout << endl;
    int num;

    for (int i = 0; i < 10; i++){
        num = rand();
        fila.push(num);

        cout << num << " ";
    }
}

template<typename T>
void popElements(T& fila){
    cout << endl;
    while(!fila.empty()){
        cout << fila.top() << " ";
        fila.pop();
    }
}

class compare{
    public:
    bool operator()(int a, int b){
        return a < b;
    };
};

bool compareFunc(int a, int b){
    return a < b;
};

int main(){
    //forma 1
    priority_queue<int, deque<int>, compare> pqD1;

    //forma 2
    priority_queue<int, deque<int>, std::function<bool(int, int)>> pqD2(compareFunc);

    //forma 3
    auto cmp = [](int a, int b){ return a < b;  }; // funcao sem nome
    priority_queue<int, deque<int>, decltype(cmp)> pqD3(cmp);

    //forma 4
    priority_queue<int, deque<int>, function<bool(int a, int b)>> pqD4([](int a, int b){
        return a<b;
    });

    cout << "\n Pushing \n";
    pushElements(pqD1);
    pushElements(pqD2);
    pushElements(pqD3);
    pushElements(pqD4);

    cout << "\n Popping \n";
    popElements(pqD1);
    popElements(pqD2);
    popElements(pqD3);
    popElements(pqD4);

    return 0;

}