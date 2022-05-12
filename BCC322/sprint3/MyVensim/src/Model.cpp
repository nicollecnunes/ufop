/**
* @file Model.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo que define os métodos da entidade Modelo
**/

#include "Model.h"
#include "Flow.h"
#include "System.h"

Model::~Model()
{
    listSystem.clear();
    listFlow.clear();
}
Model::Model()
{
    time = 0;
    listSystem.clear();
    listFlow.clear();
}

Model::Model(const Model &model)
{   
    time = model.time;

    listSystem.clear();
    listFlow.clear();

    listSystem = model.listSystem;
    listFlow = model.listFlow;
}

void Model::add(Flow *f)
{
    listFlow.push_back(f);
}

void Model::add(System *s)
{
    listSystem.push_back(s);
}

void Model::run(double start, double end, double increment)
{
    for(double i = start; i < end; i+=increment) 
    {
        for(auto it = listFlow.begin(); it != listFlow.end(); it++)
        {
            (*it)->setValue((*it)->run());
        }
    

        for(auto it = listFlow.begin(); it != listFlow.end(); it++)
        {
            System *origin = (*it)->getOrigin();
            System *target = (*it)->getTarget();
            if(origin != NULL)
            {
                origin->setValue(origin->getValue() - (*it)->getValue());
            }

            if(target != NULL) 
            {
                target->setValue(target->getValue() + (*it)->getValue());
            }
        }
        
        time += increment;
    }
}

Model* Model::operator=(const Model *m)
{
    if (m == this)
    {
        return this;
    }

    time = m->time;
    listFlow = m->listFlow;
    listSystem = m->listSystem;

    return this;
}