#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include <string>
using std::string;

class ClientData{
    int accountNumber;
    char lastName[15];
    char firstName[10];
    double balance;
public:
    // constructor
    ClientData(int = 0, string = "", string = "", double = 0.0);

    //funcoes de acesso
    void setAccountNumber(int);
    int getAccountNumber() const;

    void setLastName(string);
    string getLastName() const;

    void setFirstName(string);
    string getFirstName() const;

    void setBalance(double);
    double getBalance() const;
};

#endif