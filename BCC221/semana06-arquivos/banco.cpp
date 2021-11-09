#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

void outputLine(int, string, double);

int main(){
    ofstream outClientFile("clients.dat", ios::out);

    // se nao conseguir criar o arquivo
    if (!outClientFile){
        cerr << "erro na abertura\n";
        exit(1);
    }

    cout << "account, name and balance\n\n? ";

    int account;
    char name[30];
    double balance;
    int i = 0;

    while(i < 3){
        cin >> account >> name >> balance;
        outClientFile << account << " " << name << " " << balance << endl;
        cout << "? ";
        i = i+1;
    }
    outClientFile.close();

    // leitura
    ifstream inClientFile("clients.dat", ios::in);

    if (!inClientFile){
        cerr << "erro na abertura\n";
        exit(1);
    }

    cout << left << setw(10) << "Account" << setw(13) << "Name" << "Balance" << endl << fixed << showpoint;

    // exibe cada registro
    while(inClientFile >> account >> name >> balance)
        cout << account << " " <<  name << " " <<  balance << "\n";

    return 0;
}