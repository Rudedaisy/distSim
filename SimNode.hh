#ifndef __SIM_NODE_HH__
#define __SIM_NODE_HH__

#include <cstdlib>
#include <cstdio>

#include "Timeline.hh"

class Timeline;

class SimNode {
protected:
  // pointer to global timeline
  Timeline * timeline;
  // ID of current state
  unsigned state;

  // pointer to State Machine next array
  unsigned * SMnext;
  // pointer to State Machine array of function pointers
  //void (**FunctionPointers)();
  // update internal state using state machine
  void updateSM();
  // schedule next action and updateSM
  void schedEvent();

public:
  // constructor
  SimNode(Timeline * _timeline, unsigned _state, unsigned * _SMnext); //, void (*_FunctionPointers[])());
  // destructor
  ~SimNode();
  // perform schedule action based on state machine
  virtual void act(unsigned _actID)=0;
  
}; // SimNode

#endif // SIM_NODE_HH
