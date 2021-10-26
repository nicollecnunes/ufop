#include "Vetor.h"

template<typename T>
class SortVetor : public Vetor<T>{
public:
    SortVetor(int = 5);
    virtual ~SortVetor();

    bool pushBack(T);
};

template<typename T>
SortVetor<T>::SortVetor(int tam): Vetor<T>(tam){}

template<typename T>
SortVetor<T>:: ~SortVetor(){}

template<typename T>
bool SortVetor<T> :: pushBack(T value){
    if(Vetor<T>::pushBack(value)){
        for(int i = this->top-1; i>=0 && this->vec[i] > value; i--){
            this->vec[i+1] = this->vec[i];
            this->vec[i] = value;
        }
        return true;
    }
    return false;
}