#include "FlowTestUnit.hpp"
#include "../../../src/System.hpp"

FlowTestUnit::FlowTestUnit(): Flow(){}

FlowTestUnit::FlowTestUnit(string name): Flow(name){}

FlowTestUnit::FlowTestUnit(const Flow *flow): Flow(flow){}

FlowTestUnit::~FlowTestUnit() {}

double FlowTestUnit::execute() const { return 0.1 * getSource()->getValue(); }
