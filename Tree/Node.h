#pragma once

namespace tree {
// Binary Node
template <class T> struct Node {
  int key;
  T val;
  Node<T> *l;
  Node<T> *r;
  Node<T> *p;

  Node(int key, T val) : key(key), val(val) {}
};

} // namespace tree