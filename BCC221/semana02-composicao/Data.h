#ifndef DATA_H
#define DATA_H

class Data{
    int dia,mes,ano;

    public:

    Data(int=0,int=0,int=0);
    virtual ~Data();

    int getDia()const;
    void setDia(int);

    int getMes()const;
    void setMes(int);
    
    int getAno()const;
    void setAno(int);
};

#endif