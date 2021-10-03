#ifndef RELOGIO_H
#define RELOGIO_H

class Relogio{
    int h,m,s;
    
    public:
    Relogio(int=0,int=0,int=0);
    ~Relogio();
    void setHora(int,int,int);
    void printHora();

    // funcao amiga alterHMS, recebe uma referencia da classe Relogio
    friend void alteraHMS(Relogio&);
};
#endif