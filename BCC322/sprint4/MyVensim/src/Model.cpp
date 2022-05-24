#include "Model.hpp"
#include "ISystem.hpp"
#include "IFlow.hpp"

Model::Model(){
    setTime(0);
};

Model::~Model(){}

void Model::add(IFlow * flow) {
    flows.push_back(flow);
}

void Model::add(ISystem * system) {
    systems.push_back(system);
}

Model::iteratorFlow Model::beginFlows()
{
  return flows.begin();
}

Model::iteratorFlow Model::endFlows()
{
  return flows.end();
}

Model::iteratorSystem Model::beginSystems()
{
  return systems.begin();
}

Model::iteratorSystem Model::endSystems()
{
  return systems.end();
}

void Model::setTime(double time) {
    this->time = time;
}

double Model::getTime() const{
    return time;
}

void Model::incrementTime(double increment) {
    time += increment;
}


void Model::run(double start, double end, double increment)
{
    for(double i = start; i < end; i+=increment) 
    {
        for(auto it = beginFlows(); it != endFlows(); it++)
        {
            (*it)->setCurrentValue((*it)->execute());
        }    

        for(auto it = beginFlows(); it != endFlows(); it++)
        {
            ISystem *source = (*it)->getSource();
            ISystem *target = (*it)->getTarget();
            if(source != NULL)
            {
                source->setValue(source->getValue() - (*it)->getCurrentValue());
            }

            if(target != NULL) 
            {
                target->setValue(target->getValue() + (*it)->getCurrentValue());
            }
        }
        
        incrementTime(increment);
    }
}
