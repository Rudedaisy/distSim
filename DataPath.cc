#include <cstdlib>
#include <iostream>
#include <assert.h>

#include "DataPath.hh"

// constructor
DataPath::DataPath(Timeline * _timeline, ComputeNode * _node1, ComputeNode * _node2)
  : SimNode(_timeline, 0, NULL) {

  assert(_node1 != NULL);
  assert(_node2 != NULL);
  
  links = new ComputeNode*[2];
  links[0] = _node1;
  links[1] = _node2;
  _node1->connect(this);
  _node2->connect(this);
  std::cout << "DataPath set!" << std::endl;
}
// destructor
DataPath::~DataPath() {
}
// perform schedule action based on state machine
void DataPath::act(unsigned _actID) {
  std::cout << "Warning: cannot call act of virtual DataPath!" << std::endl;
  return;
}
