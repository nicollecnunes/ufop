//
// Created by anton on 11/7/2021.
//

#ifndef TP1POO_CONGLOMERADOIMOVEL_H
#define TP1POO_CONGLOMERADOIMOVEL_H
#include <cstdio>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <iostream>
#include "Chacara.h"
#include "Apartamento.h"
#include "Casa.h"
#include <string>
#include <algorithm>

class ConglomeradoImovel : public Casa, public Apartamento, public Chacara{
public:
    virtual ~ConglomeradoImovel();
    static vector<Imovel*> lerArquivo();
    static void formatacaoVetor(ifstream &, vector<Imovel*> &, int);
    static bool funcaoDois(vector<Imovel*> *, const string&);
    static vector<Imovel*> funcaoTres(float valor, vector<Imovel *> *vetor);
    static vector<Imovel*> funcaoQuatro(vector<Imovel*> *, int);
    static vector<Imovel*> funcaoCinco(const string& tipo, vector<Imovel *> *);
    static vector<Imovel*> funcaoSeis(vector<Imovel*> *vetor, const string&);
    static vector<vector<Imovel*>::iterator> funcaoSete(vector<Imovel*> *vetor, const string& nome);
    static void funcaoOito(vector<Imovel*> *, int);

};

#endif //TP1POO_CONGLOMERADOIMOVEL_H
