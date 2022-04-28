/**
* @file Model.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo que define os métodos da entidade Modelo
**/

#include "Model.h"
#include "IFlow.h"
#include "ISystem.h"

Model::~Model(){}
Model::Model(){}

void Model::add(IFlow *f)
{
    listFlow.push_back(f);
}

void Model::add(ISystem *s)
{
    listSystem.push_back(s);
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
            ISystem *origin = (*it)->getOrigin();
            ISystem *target = (*it)->getTarget();
            if(origin != NULL)
            {
                origin->setSystemValue(origin->getSystemValue() - (*it)->getFlowValue());
            }

            if(target != NULL) 
            {
                target->setSystemValue(target->getSystemValue() + (*it)->getFlowValue());
            }
        }
        
        time += increment;
    }
}