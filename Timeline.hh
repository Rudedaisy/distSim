#ifndef __TIMELINE_HH__
#define __TIMELINE_HH__

#include <cstdlib>
#include <assert.h>
#include <iostream>

#include "SimNode.hh"

class SimNode;

class Timeline {
private:
  class Event {
  public:
    SimNode * source;
    unsigned actID;
    Event * next;

    // constructor
    Event(SimNode * _source, unsigned _actID):
      source(_source), actID(_actID), next(NULL) {}
  }; // Event

  class Time {
  public:
    unsigned timeID;
    Event * eventList;
    Event * tail;
    Time * next;

    // constructor
    Time(unsigned _timeID, Time * _next):
      timeID(_timeID), eventList(NULL), tail(NULL), next(_next) {}
    // destructor
    ~Time() {
      // Deleting a Time will delete all proceeding Times
      while (eventList != NULL) {
	Event * temp = eventList->next;
	delete eventList;
	eventList = temp;
      }
      delete next;
    }
    /*
    // remove from front - dequeue
    Event * dequeue() {
      if (eventList == NULL) return NULL;
      Event * temp = eventList->next;
      Event * curr = eventList;
      curr->next = NULL;
      if (tail == eventList) tail = temp; // same as tail = NULL
      eventList = temp;
      return curr;
    }
    */
    // add to back - enqueue
    void enqueue(SimNode * _source, unsigned _actID) {
      assert ((eventList == NULL && tail == NULL) || (eventList != NULL && tail != NULL));

      Event * curr = new Event(_source, _actID);
      if (tail == NULL) {
	eventList = curr;
	tail = curr;
	return;
      }
      tail->next = curr;
      tail = curr;
      return;
    }
  }; // Time

  Time * head;
  Time * currTime;
  Event * currEvent;
  
public:
  // constructor
  Timeline();
  // destructor
  ~Timeline();
  // advance one Event or Time link. preserve/record previous Time links
  // if new Event encountered, calls the SimNode's act() function
  // returns new timestamp; 0 if terminating
  unsigned advance();
  // schedule an event. create a new Time link if necessary
  void schedule(unsigned _timeOffset, SimNode * _source, unsigned _actID);
  // helper function: print Timeline in human readable format
  void print();
}; // Timeline

#endif // TIMELINE_HH
