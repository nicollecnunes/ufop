#include "Model.h"
#include "Flow.h"
#include "System.h"

Model::~Model(){}
Model::Model(){}

void Model::add(Flow *f)
{
    listFlow.push_back(f);
}

void Model::run(double start, double end, double increment)
{
    for(double i = start; i < end; i+=increment) 
    {
        for(auto it = listFlow.begin(); it != listFlow.end(); it++)
        {
            (*it)->setFlowValue((*it)->run());
        }
    

        for(auto it = listFlow.begin(); it != listFlow.end(); it++)
        {
            System *nock = (*it)->getNock();
            System *target = (*it)->getTarget();
            if(nock != NULL)
            {
                nock->setSystemValue(nock->getSystemValue() - (*it)->getFlowValue());
            }

            if(target != NULL) 
            {
                target->setSystemValue(target->getSystemValue() + (*it)->getFlowValue());
            }
        }
        
        time += increment;
    }
}