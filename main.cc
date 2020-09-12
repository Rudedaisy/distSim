#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "SimNode.hh"
#include "Timeline.hh"
#include "ComputeNode.hh"
#include "DataPath.hh"

int main(void) {
  Timeline t2;
  ComputeNode c1(&t2);
  ComputeNode c2(&t2);
  DataPath d1(&t2, &c1, &c2);
  
  return 0;

  ComputeNode a(&t2);
  
  std::cout << "*** Testing Timeline ***" << std::endl;
  Timeline t1;
  std::cout << "Using t.advance on empty timeline: " << t1.advance() << std::endl;
  std::cout << "Schedule atomic (this Time) and for future time" << std::endl;
  Timeline t;
  unsigned ecounter = 0;
  std::cout << ecounter << std::endl;
  t.schedule(1, &a, ecounter++);   // 0
  std::cout << ecounter << std::endl; 
  t.schedule(100, &a, ecounter++); // 1
  std::cout << ecounter << std::endl; 
  t.schedule(99, &a, ecounter++);  // 2
  std::cout << ecounter << std::endl; 
  t.schedule(50, &a, ecounter++);  // 3
  std::cout << ecounter << std::endl; 
  t.schedule(200, &a, ecounter++); // 4
  std::cout << ecounter << std::endl; 
  t.schedule(100, &a, ecounter++); // 5
  std::cout << ecounter << std::endl;
  t.schedule(100, &a, ecounter++); // 6
  std::cout << "Advance til end: ";
  unsigned returnVal = 1;
  while (returnVal != 0) {
    returnVal = t.advance();
    std::cout << " " << returnVal;
  }
  std::cout << std::endl;

  t.print();
  
  return 0;
}
