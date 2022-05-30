#include "FlowTestUnit.hpp"
#include "../../../src/include/SystemImpl.hpp"

FlowTestUnit::FlowTestUnit(): FlowImpl(){}

FlowTestUnit::FlowTestUnit(string name, System *s, System *t ) :FlowImpl(name, s, t){}

FlowTestUnit::FlowTestUnit(const FlowImpl *flow): FlowImpl(flow){}

FlowTestUnit::~FlowTestUnit() {}

double FlowTestUnit::execute() const { return 0.1 * getSource()->getValue(); }
