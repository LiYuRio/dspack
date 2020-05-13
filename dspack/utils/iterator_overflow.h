#pragma once
#include <ostream>

class iterator_overflow {
 public:
  iterator_overflow(int index, int max) : _index(index), _max(max) {}
  int index() { return _index; }
  int max() { return _max; }
  void what_happened(std::ostream &os = std::cerr) {
    os << "Internal error: current index " << _index
       << " exceeds maximum bound: " << _max;
  }

 private:
  int _index;
  int _max;
};