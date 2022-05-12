
/**
* @file System.h
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo header da entidade que define o Modelo
**/

#ifndef MODEL_HPP
#define MODEL_HPP

#include <list>
using namespace std;

class Flow;
class System;

class Model {
    private:
        Model(const Model &model);
    protected:
        double time = 0;
        list<Flow *> listFlow;
        list<System *> listSystem;

        Model* operator=(const Model* m);
    public:
        Model();
        virtual ~Model();

        void run(double s = 0, double e = 0, double i = 0);
        void add(Flow *f = NULL);
        void add(System *s = NULL);

        Model* operator=(const Model* s);
};

#endif