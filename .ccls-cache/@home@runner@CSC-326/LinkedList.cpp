#include "LinkedList.h"
#include <iostream>
#include <ostream>

namespace linkedlist {

LinkedList::LinkedList() : _head(new Node()), _len(0) {
  _tail = _head;
  _head->next = _tail;
}

const int LinkedList::len() const { return _len; }
const Node *LinkedList::head() const { return _head; }
const Node *LinkedList::tail() const { return _tail; }

void LinkedList::append(int val) {
  Node *n = new Node();
  n->val = val;
  _tail->next = n;
  _tail = n;
  _len++;
}

void LinkedList::prepend(int val) {
  Node *n = new Node();
  n->val = val;
  if (_len == 0)
    _tail = n;
  n->next = _head->next;
  _head->next = n;
  _len++;
}

void LinkedList::insert(int val) {
  Node *cur = _head->next;
  Node *prev = _head;
  while (cur) {
    if (cur->val > val) {
      Node *n = new Node();
      n->next = cur;
      n->val = val;
      prev->next = n;
      _len++;
      return;
    }
    prev = cur;
    cur = cur->next;
  }
  Node *n = new Node();
  n->val = val;
  prev->next = n;
  _len++;
}

void LinkedList::remove(int val) {
  Node *cur = _head->next;
  Node *prev = _head;
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

void r(Node *h) {
  if (!h->next)
    return;
  r(h->next);
  h->next->next = h;
}

void LinkedList::reverse() {
  if (!_head->next)
    return;
  Node *cur = _head->next;
  r(_head->next);

  _head->next->next = nullptr;
  _head->next = _tail;
  _tail = cur;
}

// void LinkedList::reverse_iter() {
//   Node* head = _head->next, first = head->next, last = tail;
//   while (last != head) {
//     tail->next = 
//     _head->next = tail;
//   }
// }

int LinkedList::get_mid() {
  if (!_head->next)
    return -1;
  Node *slow = _head->next;
  Node *fast = slow;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow->val;
}

int LinkedList::index_of(int val) {
  int idx = 0;
  Node *cur = _head->next;
  while (cur) {
    if (cur->val == val)
      return idx;
    cur = cur->next;
    idx++;
  }
  return -1;
}

int LinkedList::getFrequencyof(int val) {
  int freq = 0;
  Node *cur = _head->next;
  while (cur) {
    if (cur->val == val)
      freq++;
    cur = cur->next;
  }
  return freq;
}

void LinkedList::sort() {
  if (_len < 2)
    return;
  Node *prev;
  Node *cur;
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

std::ostream &operator<<(std::ostream &os, const LinkedList &list) {
  Node *cur = list.head()->next;
  while (cur) {
    os << cur->val << " ";
    cur = cur->next;
  }
  return os;
}

void LinkedList::print() { std::cout << *this << std::endl; }

LinkedList::~LinkedList() {
  Node *cur = _head;
  Node *prev = cur;
  while (cur) {
    cur = cur->next;
    delete prev;
    prev = cur;
  }
  _len = 0;
}

}