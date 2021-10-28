#include <iostream>
#include <queue>

using namespace std;

int main(){
    std::queue<double> values;

    values.push(3.2);
    values.push(9.8);
    values.push(5.4);

    cout << "Popping: ";

    while(!values.empty()){
        cout << values.front() << " ";
        values.pop(); //3.2 9.8 5.4
    }
    return 0;
}