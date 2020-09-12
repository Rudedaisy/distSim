#include "SimNode.hh"

// update internal state using state machine
void SimNode::updateSM(){
  state = SMnext[state];
}
// schedule next action and updateSM
void SimNode::schedEvent(){
  /////////// TBD
}

// constructor
SimNode::SimNode(Timeline * _timeline, unsigned _state, unsigned * _SMnext)
  :timeline(_timeline), state(_state), SMnext(_SMnext) {
}

// destructor
SimNode::~SimNode() {
}
