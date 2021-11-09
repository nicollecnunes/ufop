#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

#include "ClientData.h"
using namespace std;

int main(){
    /*ofstream outCredit("credit.dat", ios::binary);

    if(!outCredit){
        cerr << "erro.";
        exit(1);
    }

    ClientData blankClient;

    gera 50 reg em branco no arquivo
    for(int i = 0; i<50; i++)
        outCredit.write(reinterpret_cast<const char*>(&blankClient), sizeof(ClientData));
    */

    int accountNumber;
    char lastName[15];
    char firstName[10];
    double balance;

    fstream outCredit("credit.dat", ios::in|ios::out|ios::binary);
    if(!outCredit){
        cerr << "erro.";
        exit(1);
    }

    cout << "Enter an account number 1 to 100 - 0 to exit\n? ";
    ClientData client;
    cin >> accountNumber;

    while(accountNumber > 0 && accountNumber <=100){
        cout << "enter lastname, first name and balance\n? ";
        cin >> setw(15) >> lastName;
        cin >> setw(10) >> firstName;
        cin >> balance;

        // configura valores
        client.setAccountNumber(accountNumber);
        client.setLastName(lastName);
        client.setFirstName(firstName);
        client.setBalance(balance);

        //busca posicao no arquivo
        outCredit.seekp((client.getAccountNumber() - 1) * sizeof (ClientData));

        //grava as informacoes
        outCredit.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));

        //permite inserir outra
        cout << "Enter an account number 1 to 100 - 0 to exit\n? ";
        cin >> accountNumber;
    }
    return 0;

}