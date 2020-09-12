#ifndef __DATA_PATH_HH__
#define __DATA_PATH_HH__

#include "SimNode.hh"
#include "ComputeNode.hh"

class ComputeNode;

class DataPath: public SimNode {
protected:
  // dynamically allocated array of links (connections to other SimNodes)
  ComputeNode ** links;
public:
  // constructor
  DataPath(Timeline * _timeline, ComputeNode * _node1, ComputeNode * _node2);
  // destructor
  ~DataPath();
  // perform schedule action based on state machine
  virtual void act(unsigned _actID);
}; // DataPath

#endif // DATA_PATH_HH
