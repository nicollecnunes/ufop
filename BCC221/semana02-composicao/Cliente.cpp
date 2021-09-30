#include "Cliente.h"
#include <string>

Cliente :: Cliente(string _nome, string _endereco, string _cpf):
    nome(_nome), endereco(_endereco), cpf(_cpf) {}

Cliente :: ~Cliente(){}

string Cliente :: getNome() const {return nome;}
void Cliente :: setNome(string _nome) {nome = _nome;}

string Cliente :: getEndereco() const {return endereco;}
void Cliente :: setEndereco (string _endereco) {endereco = _endereco;}

string Cliente :: getCpf() const {return cpf;}
void Cliente:: setCpf( string _cpf) {cpf = _cpf;}
