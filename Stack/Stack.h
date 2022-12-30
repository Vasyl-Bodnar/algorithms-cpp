#pragma once
#include "../Vec/Vec.h"

namespace stack {

template <class T> class Stack {
public:
  bool isEmpty() { vec.empty(); }
  void pop() { vec.pop(); }
  void push(T val) { vec.push(val); }
  const T peek() const { return vec.at(vec.size() - 1); }
  vec::Vec<T> get_inner() { return vec; }

private:
  vec::Vec<T> vec;
};

} // namespace stack