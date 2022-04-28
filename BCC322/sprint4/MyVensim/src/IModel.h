#ifndef IMODEL_H
#define IMODEL_H

#include <list>
using namespace std;

class IFlow;
class ISystem;

class IModel {
    public:
        virtual ~IModel();

        virtual void run(double s = 0, double e = 0, double i = 0) = 0;
        virtual void add(IFlow *f = NULL) = 0;
        virtual void add(ISystem *s = NULL) = 0;
    };

#endif