#include <iostream>
#include <iterator>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

struct Point {double x; double y;};
struct PointCmp {
    bool operator()(const Point& lhs, const Point& rhs) const {
        return std:: hypot(lhs.x, lhs.y) < std:: hypot(rhs.x, rhs.y);
    }
};

int main(){
    // construtor padrao
    set<string> a;
    a.insert("cat");
    a.insert("dog");
    a.insert("horse");

    for (auto& elem : a){
        cout << elem << " "; //cat, dog, horse
    }
    cout << "\n";

    // construtor iterador
    set<string> b(a.find("dog"), a.end());
    for(auto& elem: b){
        cout << elem << " "; // dog, horse
    }
    cout << "\n";

    // copia por construtor
    set<string> c(a);
    c.insert("another horse");
    for (auto& elem : c){
        cout << elem << " "; // another horse, cat, dog, horse
    }
    cout << "\n";

    // move construtor
    set<string> d(std::move(a));
    for(auto& elem : d){
        cout << elem << " "; //cat, dog, horse
    }
    cout << "\n";

    std::cout<< "moved-from set is: ";
    for(auto& elem : a){
        cout << elem << " "; // vazio
    }
    cout << "\n";

    // inicializa lista construtor
    set<string> e{"one", "two", "three", "five", "eight"};
    for(auto& elem:e){
        cout << elem << " ";
    }
    cout << "\n";

    // comparacao de points
    set<Point, PointCmp> z = {{2,5}, {3,4}, {1,1}};
    // usa o criterio pointCmp para ordenar
    z.insert({1,-1});
    for(auto& elem:z){
        cout << "(" << elem.x << ", " << elem.y << ") ";
    }
    cout << "\n";

}