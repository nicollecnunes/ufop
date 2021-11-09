#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

enum requestType{ZERO_BALANCE = 1, CREDIT_BALANCE, DEBIT_BALANCE, END};

int getRequest(){
    int opc;
    cout << "\n\nSELECIONE UMA OPCAO DE FILTRO:\n";
    cout << "[1] ZERO BALANCE\n[2] CREDIT BALANCE\n[3] DEBIT BALANCE\n[4] END\n\n>>";
    cin >> opc;
    return opc;
}

void outputLine(int account, string name, double balance){
    cout << account << " " <<  name << " " <<  balance << "\n";
}

bool shouldDisplay(int type, double balance){
    if (type == ZERO_BALANCE && balance == 0)
        return true;

    if (type == CREDIT_BALANCE && balance < 0)
        return true;

    if (type == DEBIT_BALANCE && balance > 0)
        return true;
    
    return false;

}

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

    int request;
    request = getRequest();

    while (request != END){
        switch(request){
            case ZERO_BALANCE:
                cout << "\nAcc with ZERO balance:\n";
                break;
            case CREDIT_BALANCE:
                cout << "\nAcc with CREDIT balance:\n";
                break;
            case DEBIT_BALANCE:
                cout << "\nAcc with DEBIT balance:\n";
                break;
        }
        inClientFile >> account >> name >> balance; //leitura
        // exibe
        while(!inClientFile.eof()){
            //exibe
            if(shouldDisplay(request, balance))
                outputLine(account, name, balance);
            
            // le a conta, nome e saldo
            inClientFile >> account >> name >> balance; //leitura
        }
        //redefine eof para a prox entrada
        inClientFile.clear();
        //posiciona no comeco do arquivo
        inClientFile.seekg(0);
        //otem a solicitacao nova do usuario
        request = getRequest();
    }

    cout << "end";

    /*cout << left << setw(10) << "Account" << setw(13) << "Name" << "Balance" << endl << fixed << showpoint;

    exibe cada registro
    while(inClientFile >> account >> name >> balance)
        outputLine(account, name, balance);*/

    return 0;
}