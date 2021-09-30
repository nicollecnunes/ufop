#include"Data.h"

Data::Data(int dia,int mes,int ano):
    dia(dia),mes(mes),ano(ano){}

Data:: ~Data(){}

int Data::getDia()const{return dia;}
void Data::setDia(int _dia){dia=_dia;}

int Data::getMes()const{return mes;}
void Data::setMes(int _mes){mes=_mes;}

int Data::getAno()const{return ano;}
void Data::setAno(int _ano){ano=_ano;}
