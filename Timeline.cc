#include "Timeline.hh"
 
#include <cstdio>
#include <iostream>
 
// constructor
Timeline::Timeline() {
  Time * baseTime = new Time(0, NULL);
  this->head = baseTime;
  this->currTime = baseTime;
  this->currEvent = NULL;
}
// destructor
Timeline::~Timeline() {
  delete this->head;
}
// advance one Event or Time link. preserve/record previous Time links
// if new Event encountered, calls the SimNode's act() function
// returns new timestamp; 0 if terminating
unsigned Timeline::advance() {
  if (this->currEvent == NULL) {
    this->currTime = this->currTime->next;
    if (this->currTime == NULL) {
      return 0;
    }
    this->currEvent = this->currTime->eventList;
    // Every Time should have at least 1 event
    assert(this->currEvent != NULL);
  }
  else {
    this->currEvent = this->currEvent->next;
    if (this->currEvent == NULL) {
      return this->advance();
    }
  }
  // Call the corresponding SimNode's act funtion
  //////////////// INSERT FUNCTION CALL HERE //////////////
  return this->currTime->timeID;
}
// schedule an event. create a new Time link if necessary
void Timeline::schedule(unsigned _timeOffset, SimNode * _source, unsigned _actID) {
  // Cannot schedule in the past
  assert(_timeOffset >= 0);
  if (this->currTime == NULL) {
    std::cout << "End of simulation reached... cannot schedule!" << std::endl;
    exit(0);
  }
  
  Time * curr = this->currTime;
  unsigned searchTime = this->currTime->timeID + _timeOffset;
  // Advance time until appropriate Time slot is found
  while (curr->next != NULL && curr->next->timeID < searchTime) {
    curr = curr->next;
  }
  // Need to create new Time
  if (curr->next == NULL) {
    Time * newTime = new Time(searchTime, NULL);
    curr->next = newTime;
  }
  else if (curr->next->timeID > searchTime) {
    Time * newTime = new Time(searchTime, curr->next);
    curr->next = newTime;
  }
  // curr->next is now guaranteed to be the correct Time
  curr = curr->next;
  curr->enqueue(_source, _actID);

  return;
}
// helper function: print Timeline in human readable format
void Timeline::print() {
  std::cout << "----------- Printing Timeline -----------" << std::endl;
  
  Time * curr = head;
  Event * curre = NULL;
  while (curr != NULL) {
    std::cout << "Timestamp " << curr->timeID << ":";
    curre = curr->eventList;
    while (curre != NULL) {
      std::cout << " " << curre->actID;
      curre = curre->next;
    }
    std::cout << std::endl;
    curr = curr->next;
  }
  
  std::cout << "-----------------------------------------" << std::endl;
}
