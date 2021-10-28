#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

template<typename T>
void pushElements(T &stackRef){
    for (int i = 0; i < 10; i++){
        stackRef.push(i); // insere
        cout << stackRef.top() << " "; //exibe elemento superior
    }
}

template<typename T>
void popElements(T &stackRef){
    while(!stackRef.empty()){
        cout << stackRef.top() <<  " "; //exibe superior
        stackRef.pop();
    }
}

int main(){
    //deque subjacente padrão
    std::stack<int> intDequeStack;

    //vetor subjacente
    std::stack<int, vector<int>> intVectorStack;

    //lista subjacente
    std::stack<int, list<int>> intListStack;

    //insere 0-9 em cada pilha
    cout << "\nPushing to intDequeStack: ";
    pushElements(intDequeStack);

    cout << "\nPushing to intVectorStack: ";
    pushElements(intVectorStack);

    cout << "\nPushing to intListStack: ";
    pushElements(intListStack);

    cout << "\nPopping from intDequeStack: ";
    popElements(intDequeStack);

    cout << "\nPopping from intVectorStack: ";
    popElements(intVectorStack);

    cout << "\nPopping from intListStack: ";
    popElements(intListStack);

    // LAST IN, FIRST OUT

    return 0;
}