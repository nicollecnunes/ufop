#ifndef MODEL_H
#define MODEL_H

#include <list>
#include "IModel.h"

using namespace std;

class Model : public IModel
{
    protected:
        double time = 0;
        list<IFlow *> listFlow;
        list<ISystem *> listSystem;

        Model* operator=(const Model* m);
    public:
        Model();
        virtual ~Model();

        void run(double s = 0, double e = 0, double i = 0);
        void add(IFlow *f = NULL);
        void add(ISystem *s = NULL);
};

#endif