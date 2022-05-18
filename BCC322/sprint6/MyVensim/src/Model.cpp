/**
* @file Model.cpp
* @author Nicolle Nunes
* @date 26 April 2022
* @brief Arquivo que define os Metodos da entidade Modelo
**/

#include "Model.h"
#include "IFlow.h"
#include "ISystem.h"

#define DEBUGING
#ifdef DEBUGING
    int numHandleCreated = 0;
	int numHandleDeleted = 0;
	int numBodyCreated = 0;
	int numBodyDeleted = 0;
#endif


Model::~Model(){}

Model::Model()
{
    time = 0;
    listSystem.clear();
    listFlow.clear();
}

void Model::add(IFlow *f)
{
    listFlow.push_back(f);
}

void Model::add(ISystem *s)
{
    listSystem.push_back(s);
}

double Model::getTime()
{
    return time;
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
            ISystem *origin = (*it)->getOrigin();
            ISystem *target = (*it)->getTarget();
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

Model::systemIterator Model::beginSystems()
{
    return listSystem.begin();
}

Model::systemIterator Model::endSystems()
{
    return listSystem.end();
}

Model::flowIterator Model::beginFlows()
{
    return listFlow.begin();
}

Model::flowIterator Model::endFlows()
{
    return listFlow.end();
}
