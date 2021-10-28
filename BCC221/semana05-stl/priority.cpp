#include <iostream>
#include <queue>

using namespace std;

int main(){
    std :: priority_queue<double> P;

    P.push(3.2);
    P.push(9.8);
    P.push(5.4);

    cout << "Popping: ";

    while(!P.empty()){
        cout << P.top() << " "; //9.8 5.4 3.2
        P.pop();
    }
    return 0;

}