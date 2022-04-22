#include "../src/Flow.h"
#include "../src/Model.h"
#include "../src/System.h"

class FlowExponential : public Flow
{
    public:
        FlowExponential(): Flow(){}

        double run(){
            return 0.01 * getNock()->getSystemValue();
        }
};

class FlowLogistic : public Flow
{
    public:
        FlowLogistic(): Flow(){}

        double run(){
            return 0.01 * getTarget()->getSystemValue() * (1 - getTarget()->getSystemValue() / 70);
        }
};

class FlowComplex: public Flow
{
    public:
        FlowComplex(): Flow(){}

        double run(){
            return 0.01 * getNock()->getSystemValue();
        }
};

