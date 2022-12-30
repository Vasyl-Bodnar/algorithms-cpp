#pragma once

#include "../Heap/Heap.h"

using heap::Heap; 

namespace queue {
template <class T> class PriorityQueue {
public:
  bool empty() {
    return heap_.empty();
  }
  T top() {
    return heap_.max();
  }
  // heap does not support templates currently
  void push(int val) {
    heap_.insert(val);
  }
  T pop() {
    return heap_.extractMax();
  }
private:
  Heap heap_;
};
} // namespace queue