#ifndef LIGER_H
#define LIGER_H

#include "Tiger.h"
#include "Lion.h"

using namespace std;

class Liger : public Lion, public Tiger{
    public:
        Liger();
};

#endif