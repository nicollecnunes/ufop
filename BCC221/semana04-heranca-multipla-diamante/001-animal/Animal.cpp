#include "Animal.h"
#include <string>
#include <iostream>
#include <iomanip>

Animal :: Animal(int _age){
    this->age = _age;
    cout << "Animal Construtor!\n"; 
}

void Animal :: walk(){
    cout <<  "Animal walks\n";
}