#include "ClientData.h"
using std::string;
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

// construtor padrao
ClientData :: ClientData(int _accountNumber, string _lastName, string _firstName, double _balance){
    setAccountNumber(_accountNumber);
    setLastName(_lastName);
    setFirstName(_firstName);
    setBalance(_balance);
}

int ClientData::getAccountNumber() const { return accountNumber; }
void ClientData::setAccountNumber(int _n){ accountNumber = _n; }

string ClientData::getLastName() const{ return lastName; }
void ClientData::setLastName(string _n){
    const char *lastNameValue = _n.data();
    int length = _n.size();

    length = (length < 15 ? length : 14);

    strncpy(lastName, lastNameValue, length);
    lastName[length] = '\0';   
}

string ClientData::getFirstName() const{ return firstName; }
void ClientData::setFirstName(string _n){
    const char *firstNameValue = _n.data();
    int length = _n.size();

    length = (length < 10 ? length : 9);

    strncpy(firstName, firstNameValue, length);
    firstName[length] = '\0';

}

double ClientData::getBalance() const { return balance; }
void ClientData::setBalance(double _b) {balance = _b;}