#include <iostream>
using namespace std;

template<typename T>
class Vetor{
protected:
    T* vec;
    int n, top;
public:
    Vetor(int = 5);
    virtual ~Vetor();

    void clear();
    bool pushBack(T);
    int size();

    T at(int);
    
    template<typename T2>
    friend ostream& operator <<(ostream&, const Vetor<T2>&);
};

template<typename T>
Vetor<T> :: Vetor(int n){
    this->n = (n<5) ? 5 : n;
    vec = new T[n];
    this->top = -1;
}

template<typename T>
Vetor<T> :: ~Vetor(){
    if (vec != nullptr){
        delete[] vec;
        this->top = -1;
        this->n = 0;
    }
}

template<typename T>
void Vetor<T> :: clear(){
    top = -1;
}

template<typename T>
bool Vetor<T> :: pushBack(T value){
    if (top < n){
        top = top + 1;
        vec[top] = value;
        return true;
    }
    return false;
}

template<typename T>
T Vetor<T> :: at(int pos){
    if (pos >= 0 && pos<=top){
        return vec[pos];
    }
    else{
        throw out_of_range("Out of range");
    }
}

template<typename T>
int Vetor<T> :: size(){
    return top+1;
}

template<typename T>
ostream& operator<<(ostream& out, const Vetor<T>& obj){
    for (int i = 0; i<= obj.top; i++){
        out << obj.vec[i] << " ";
    }
    return out;
}