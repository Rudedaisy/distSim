// ComputeNode for PowerGraph!

#ifndef __COMPUTE_NODE_HH__
#define __COMPUTE_NODE_HH__

#include <vector>

#include "SimNode.hh"
#include "DataPath.hh"

class DataPath;

class ComputeNode: public SimNode {
private:
  std::vector<DataPath *> links;
public:
  // constructor
  ComputeNode(Timeline * _timeline);
  //destructor
  ~ComputeNode();
  // connect to specified DataPath;
  void connect(DataPath * _path);
  // perform schedule action based on state machine
  virtual void act(unsigned _actID);
}; // ComputeNode

#endif // COMPUTE_NODE_HH for PowerGraph
