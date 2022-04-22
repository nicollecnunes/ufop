#ifndef MODEL_HPP
#define MODEL_HPP

#include <list>
using namespace std;

class Flow;
class System;

class Model {
protected:
    double time = 0;
    list<Flow *> listFlow;

    Model* operator=(const Model* m);
public:
    Model();
    virtual ~Model();

    void run(double s = 0, double e = 0, double i = 0);
    void add(Flow *f = NULL);
};

#endif