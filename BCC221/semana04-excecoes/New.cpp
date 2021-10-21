#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main(){
    double *ptr[50];
    int i=0;

    for (i = 0; i < 50; i++){
        ptr[i] = new (nothrow) double[500000000];
        if (ptr[i] == nullptr){
            cerr << "Memory failed\n";
            break;
        }
        else{
            cout << "ok\n";
        }
    }

        cout << "\ndeleting...";
        for (int j=0; j< i; j++){
            if(ptr[i] != nullptr)
                delete[] ptr[j];
        }
        cout << "\ndeleted\n";
    

    return 0;
    
    }