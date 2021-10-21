#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;

int main(){
    int n, d;
    double res;

    cout << "\nDigite 2 numeros: ";
    while(true){
        try{
            if(!(cin >> n >> d)){
                throw invalid_argument("\nInt");
            }
            if( d == 0){
                throw runtime_error("\ndivisao por 0");
            }
            res =  static_cast<double>(n)/d;
            cout << "\nResposta: " << res;
        }
        catch(invalid_argument& e){
            cerr << "\nErro: " << e.what();
            cin.clear();
            cin.ignore(numeric_limits<streamsize> :: max(), '\n');
        }
        catch(runtime_error& e){
            cerr << "\nErro: " << e.what();
        }
        cout << "\nDigite 2 numeros: ";
        return 0;
    }
}