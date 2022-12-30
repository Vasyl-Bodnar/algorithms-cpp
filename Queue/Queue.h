#pragma once

#include "../LinkedList/LinkedList.h"

using linkedlist::LinkedList, linkedlist::Node;

namespace queue {
template <class T> class Queue {
public:
  Queue() : list_(LinkedList<T>()) {}
  Queue(LinkedList<T> list) : list_(list) {}

  const bool empty() const { return list_.len() == 0; }
  const T peek() const {
    return (!empty()) ? list_.head()->next->val : throw "List is Empty!";
  }
  void enqueue(T val) { list_.append(val); }
  void dequeue() {
    auto old = list_.head()->next;
    list_.head()->next = list_.head()->next->next;
    delete old;
  }

private:
  LinkedList<T> list_;
};
} // namespace queue