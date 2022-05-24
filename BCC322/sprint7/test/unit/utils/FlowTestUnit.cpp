#include "FlowTestUnit.hpp"
#include "../../../src/include/SystemImpl.hpp"

FlowTestUnit::FlowTestUnit(): FlowBody(){}

FlowTestUnit::FlowTestUnit(string name = "", System *s = NULL, System *t = NULL): FlowBody(name, s, t){}

FlowTestUnit::~FlowTestUnit(){}

double FlowTestUnit::execute() const { return 0.1 * getSource()->getValue(); }
