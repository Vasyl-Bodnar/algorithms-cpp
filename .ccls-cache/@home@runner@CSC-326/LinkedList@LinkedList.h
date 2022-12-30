#pragma once

#include "Node.h"

#include <iostream>
#include <ostream>

namespace linkedlist {

template <class T> class LinkedList {
public:
  const Node<T> *head() const;
  const Node<T> *tail() const;
  Node<T> *head();
  Node<T> *tail();
  const int len() const;
  void append(int);
  void prepend(int);
  void insert(int);
  void remove(int);
  void reverse();
  void reverse_iter();

  int last_k(int);
  int get_mid();
  int index_of(int);
  int getFrequencyof(int);
  void sort();
  void print();

  ~LinkedList<T>();

private:
  Node<T> *_head = new Node<T>();
  Node<T> *_tail = _head;
  int _len = 0;
};

template <typename T> const int LinkedList<T>::len() const { return _len; }
template <typename T> const Node<T> *LinkedList<T>::head() const {
  return _head;
}
template <typename T> const Node<T> *LinkedList<T>::tail() const {
  return _tail;
}
template <typename T> Node<T> *LinkedList<T>::head() { return _head; }
template <typename T> Node<T> *LinkedList<T>::tail() { return _tail; }

template <typename T> void LinkedList<T>::append(int val) {
  Node<T> *n = new Node<T>();
  n->val = val;
  _tail->next = n;
  _tail = n;
  _len++;
}

template <typename T> void LinkedList<T>::prepend(int val) {
  Node<T> *n = new Node<T>();
  n->val = val;
  if (_len == 0)
    _tail = n;
  n->next = _head->next;
  _head->next = n;
  _len++;
}

template <typename T> void LinkedList<T>::insert(int val) {
  Node<T> *cur = _head->next;
  Node<T> *prev = _head;
  while (cur) {
    if (cur->val > val) {
      Node<T> *n = new Node<T>();
      n->next = cur;
      n->val = val;
      prev->next = n;
      _len++;
      return;
    }
    prev = cur;
    cur = cur->next;
  }
  append(val);
}

template <typename T> void LinkedList<T>::remove(int val) {
  Node<T> *cur = _head->next;
  Node<T> *prev = _head;
  while (cur) {
    if (cur->val == val) {
      prev->next = cur->next;
      delete cur;
      _len--;
      return;
    }
    prev = cur;
    cur = cur->next;
  }
}

template <typename T> void r(Node<T> *n) {
  if (!n->next)
    return;
  r(n->next);
  n->next->next = n;
}

template <typename T> void LinkedList<T>::reverse() {
  if (!_head->next->next)
    return;
  Node<T> *head = _head->next;
  r(_head->next);

  _head->next->next = nullptr;
  _head->next = _tail;
  _tail = head;
}

template <typename T> void LinkedList<T>::reverse_iter() {
  Node<T> *prev = nullptr, *cur = _head->next, *next = cur->next;
  _tail = cur;
  while (next) {
    cur->next = prev;
    prev = cur;
    cur = next;
    next = next->next;
  }
  _head->next = cur;
  cur->next = prev;
}

template <typename T> int LinkedList<T>::last_k(int k) {
  Node<T> *prev = _head->next;
  Node<T> *next = prev;

  for (int i = 0; i < k; i++)
    prev = prev->next;

  while (prev) {
    prev = prev->next;
    next = next->next;
  }

  return next->val;
}

template <typename T> int LinkedList<T>::get_mid() {
  if (!_head->next)
    return -1;
  Node<T> *slow = _head->next;
  Node<T> *fast = slow;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow->val;
}

template <typename T> int LinkedList<T>::index_of(int val) {
  int idx = 0;
  Node<T> *cur = _head->next;
  while (cur) {
    if (cur->val == val)
      return idx;
    cur = cur->next;
    idx++;
  }
  return -1;
}

template <typename T> int LinkedList<T>::getFrequencyof(int val) {
  int freq = 0;
  Node<T> *cur = _head->next;
  while (cur) {
    if (cur->val == val)
      freq++;
    cur = cur->next;
  }
  return freq;
}

template <typename T> void LinkedList<T>::sort() {
  if (_len < 2)
    return;
  Node<T> *prev;
  Node<T> *cur;
  for (int i = 0; i < _len; i++) {
    prev = _head->next;
    cur = prev->next;
    while (cur) {
      if (cur->val < prev->val) {
        std::swap(prev->val, cur->val);
      }
      prev = cur;
      cur = cur->next;
    }
  }
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list) {
  Node<T> *cur = list.head()->next;
  while (cur) {
    os << cur->val << " ";
    cur = cur->next;
  }
  return os;
}

template <typename T> void LinkedList<T>::print() {
  std::cout << *this << std::endl;
}

template <typename T> LinkedList<T>::~LinkedList() {
  Node<T> *cur = _head;
  Node<T> *prev = cur;
  while (cur) {
    cur = cur->next;
    delete prev;
    prev = cur;
  }
}

} // namespace linkedlist