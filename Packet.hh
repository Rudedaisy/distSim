#ifndef __PACKET_HH__
#define __PACKET_HH__

#include <cstdlib>

enum PacketType = {
  CTRL,
  DATA
};

class Packet {
private:
  unsigned source;
  unsigned size;
  PacketType type;
public:
  // constructor
  Packet(unsigned _source, unsigned _size, PacketType _type):
    source(_source), size(_size), type(_type) {}
}; // Packet

#endif // PACKET_HH
