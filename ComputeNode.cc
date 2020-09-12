#include <cstdio>
#include <iostream>

#include "ComputeNode.hh"

// constructor
ComputeNode::ComputeNode(Timeline * _timeline)
  : SimNode(_timeline, 0, NULL) {
}
//destructor
ComputeNode::~ComputeNode() {
}
// connect to assigned DataPath
void ComputeNode::connect(DataPath * _path) {
  links.push_back(_path);
  std::cout << "Connect finished!" << std::endl;
}
// perform schedule action based on state machine
void ComputeNode::act(unsigned _actID) {
  std::cout << "act() called on ComputeNode!" << std::endl;
}
